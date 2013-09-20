package storm.starter.bolt;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import twitter4j.Status;

import backtype.storm.topology.BasicOutputCollector;
import backtype.storm.topology.OutputFieldsDeclarer;
import backtype.storm.topology.base.BaseBasicBolt;
import backtype.storm.tuple.Fields;
import backtype.storm.tuple.Tuple;
import backtype.storm.tuple.Values;

//In this bolt, five  minutes' texts are tokenised and statistics is calculated
public class TokenizeTextBolt extends BaseBasicBolt {

	List<Status> window_Tweet_List = new ArrayList<Status>();
	
	Map<String, Integer> window_Tweet_word_counts = new HashMap<String, Integer>();
	Map<String, Integer> window_Tweet_word__tweet_counts = new HashMap<String, Integer>();
	
	@Override
	public Map<String, Object> getComponentConfiguration() {
		return null;
	}

	@Override
	public void execute(Tuple tuple, BasicOutputCollector collector) {
		window_Tweet_List = (ArrayList<Status>) tuple.getValue(0);

		for (Status tweet : window_Tweet_List) {
			String text = tweet.getText();
						
			text = text.replaceAll("@[a-zA-Z0-9]+", "");			
			text = text.replaceAll("[^a-zA-Z0-9\\s]", "");
			text = text.replaceAll("RT|the|of|a|an|ohh|lol", "");
			
			
			String[] words = text.split("[\\s]+");			
			Map<String, Integer> tweet_words = new HashMap<String, Integer>();
			int tweet_Count = 1;
			
			for (String word : words) {
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
				// It is a new word
				if (word_Statistics == null) {
					window_Tweet_word_counts.put(word,word_count);
					window_Tweet_word__tweet_counts.put(word,1);
				}
				else
				{					
					window_Tweet_word_counts.put(word,word_Statistics+word_count);
					window_Tweet_word__tweet_counts.put(word,original_word_tweet_counts+1);
				}			    
			}
		}
		
		Map<String, Integer> copy_window_Tweet_word_counts = new HashMap<String, Integer>(window_Tweet_word_counts);
		Map<String, Integer> copy_window_Tweet_word__tweet_counts = new HashMap<String, Integer>(window_Tweet_word__tweet_counts);
		
		collector.emit(new Values(copy_window_Tweet_word_counts,copy_window_Tweet_word__tweet_counts));
		// after emitting, clear this 5 minutes' data
		window_Tweet_List.clear();
		window_Tweet_word_counts.clear();
		window_Tweet_word__tweet_counts.clear();
	}

	@Override
	public void declareOutputFields(OutputFieldsDeclarer declarer) {
		declarer.declare(new Fields("window_Tweet_word_counts","window_Tweet_word__tweet_counts"));
	}
}
