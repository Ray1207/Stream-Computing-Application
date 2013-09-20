package storm.starter.bolt;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.Map.Entry;

import twitter4j.Status;
import backtype.storm.task.OutputCollector;
import backtype.storm.task.TopologyContext;
import backtype.storm.topology.OutputFieldsDeclarer;
import backtype.storm.topology.base.BaseRichBolt;
import backtype.storm.tuple.Fields;
import backtype.storm.tuple.Tuple;
import backtype.storm.tuple.Values;

public class PrepareUserSimilarityCalculationBolt extends BaseRichBolt {

	private OutputCollector collector;
	private Map<String, String> user_tweet_text_list = new HashMap<String, String>();
	private Map<String, Map<String, Integer>> user_tweet_words_list = new HashMap<String, Map<String, Integer>>();

	@Override
	public void prepare(Map stormConf, TopologyContext context,
			OutputCollector collector) {
		this.collector = collector;	
	}
	
	@Override
	public Map<String, Object> getComponentConfiguration() {
		return null;
	}

	@Override
	public void execute(Tuple tuple) {
		List<Status> window_Tweet_List = (ArrayList<Status>) tuple.getValue(0);
		
		//Generate user tweet text map
		for (Status tweet : window_Tweet_List) {
			String userId = tweet.getUser().getScreenName();			
			String text = 	tweet.getText();
			text = text.replaceAll("@[a-zA-Z0-9]+", "");			
			text = text.replaceAll("[^a-zA-Z0-9\\s]", "");
			text = text.replaceAll("RT", "");
			text = text.toLowerCase();		
			//if it is not a new user, perform accumulation
			if(user_tweet_text_list.containsKey(userId))
			{
				String old_text = user_tweet_text_list.get(userId);
				String new_text = old_text+" "+text;
				user_tweet_text_list.put(userId, new_text);
			}
			//if it is a new user, just put data in
			else
			{
				user_tweet_text_list.put(userId, text);
			}
		}
		//based on user text, generate words list.
		for (Map.Entry entry : user_tweet_text_list.entrySet()) {		
			String user = entry.getKey().toString();
			String text = entry.getValue().toString();
			
			//calculate the words statistics
			StringTokenizer words = new StringTokenizer(text);
			Map<String, Integer> tweet_words_list = new HashMap<String, Integer>();
			while (words.hasMoreTokens()) {
				String word = words.nextToken();
				Integer word_in_line_count = tweet_words_list.get(word);
				if(word_in_line_count==null)
				{
					word_in_line_count=0;
				}				
				word_in_line_count++;				
				tweet_words_list.put(word, word_in_line_count);
			}	
			user_tweet_words_list.put(user, tweet_words_list);
		}	
		Map<String, Map<String, Integer>> copy_user_tweet_words_list = new HashMap<String, Map<String, Integer>>(user_tweet_words_list);		
		collector.emit(new Values(copy_user_tweet_words_list));
		user_tweet_words_list.clear();
	}

	@Override
	public void declareOutputFields(OutputFieldsDeclarer declarer) {
		declarer.declare(new Fields("user_tweet_words_list"));
	}
}
