package storm.starter.bolt;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;

import storm.starter.util.TweeterStreamHelper;
import twitter4j.Status;
import backtype.storm.Config;
import backtype.storm.task.OutputCollector;
import backtype.storm.task.TopologyContext;
import backtype.storm.topology.BasicOutputCollector;
import backtype.storm.topology.OutputFieldsDeclarer;
import backtype.storm.topology.base.BaseBasicBolt;
import backtype.storm.topology.base.BaseRichBolt;
import backtype.storm.tuple.Fields;
import backtype.storm.tuple.Tuple;
import backtype.storm.tuple.Values;

public class TokenizeTweetsBolt extends BaseRichBolt {
	
	private OutputCollector collector;
	private String stop_words_list;
	Map<String, Integer> window_Tweet_word_counts = new HashMap<String, Integer>();
	Map<String, Integer> window_Tweet_word__tweet_counts = new HashMap<String, Integer>();
	private static final int default_Map_Size_for_TopK = 1000;
	int Map_Size_for_TopK;
	TweeterStreamHelper _TweeterStreamHelper = new TweeterStreamHelper();
	
	//Read stop words

	public TokenizeTweetsBolt() {
		this(default_Map_Size_for_TopK);
	}

	public TokenizeTweetsBolt(int Map_Size_for_TopK_Value) {
		this.Map_Size_for_TopK = Map_Size_for_TopK_Value;
	}
	
	@Override
	public void prepare(Map stormConf, TopologyContext context,
			OutputCollector collector) {
		this.collector = collector;	
		stop_words_list = _TweeterStreamHelper.Obtain_Stop_Words_List();
	}
	
	@Override
	public Map<String, Object> getComponentConfiguration() {
		return null;
	}

	@Override
	public void execute(Tuple tuple) {
		List<Status> window_Tweet_List = (ArrayList<Status>) tuple.getValue(0);

		for (Status tweet : window_Tweet_List) {
			
			String text = tweet.getText();
			text = _TweeterStreamHelper.Filter_Text(text,stop_words_list);			
			StringTokenizer words = new StringTokenizer(text);
			//statistics of one tweet
			Map<String, Integer> tweet_words = new HashMap<String, Integer>();		
			while (words.hasMoreTokens()) {
				String word = words.nextToken();
				Integer word_in_line_count = tweet_words.get(word);
				if(word_in_line_count==null)
				{
					word_in_line_count=0;
				}			
				word_in_line_count++;			
				tweet_words.put(word, word_in_line_count);
			}
			
			for (Map.Entry<String,Integer> entry : tweet_words.entrySet()) {
			    String word = entry.getKey();
			    Integer word_count = entry.getValue();
			    
			    Integer word_Statistics = window_Tweet_word_counts.get(word);
			    Integer original_word_tweet_counts = window_Tweet_word__tweet_counts.get(word);
				
			    if(word_Statistics != null)
				{
			    	window_Tweet_word_counts.put(word,word_Statistics+word_count);
			    	window_Tweet_word__tweet_counts.put(word,original_word_tweet_counts+1);
				}
			    else if(window_Tweet_word_counts.size()<Map_Size_for_TopK)
			    {
			    	window_Tweet_word_counts.put(word,word_count);
					window_Tweet_word__tweet_counts.put(word,1);
			    }
			    else
			    {
			    	//find the item with least count
			    	Entry<String, Integer> least_count_word = _TweeterStreamHelper.Get_Min_Word_Entry(window_Tweet_word_counts);
			    	String least_count_word_key = least_count_word.getKey();
			    	Integer least_count_word_value = least_count_word.getValue();
			    	
			    	window_Tweet_word_counts.remove(least_count_word_key);
			    	window_Tweet_word_counts.put(word, least_count_word_value+1);
			    	
			    	window_Tweet_word__tweet_counts.remove(least_count_word_key);
			    	window_Tweet_word__tweet_counts.put(word,1);
			    }			    
			}
		}
		collector.emit(new Values(window_Tweet_word_counts,window_Tweet_word__tweet_counts));
	}

	@Override
	public void declareOutputFields(OutputFieldsDeclarer declarer) {
		declarer.declare(new Fields("window_Tweet_word_counts","window_Tweet_word__tweet_counts"));
	}
	

}
