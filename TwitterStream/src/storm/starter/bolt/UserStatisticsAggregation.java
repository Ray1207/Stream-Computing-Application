package storm.starter.bolt;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.Map.Entry;

import storm.starter.util.TweeterStreamHelper;
import twitter4j.Status;
import backtype.storm.task.OutputCollector;
import backtype.storm.task.TopologyContext;
import backtype.storm.topology.OutputFieldsDeclarer;
import backtype.storm.topology.base.BaseRichBolt;
import backtype.storm.tuple.Fields;
import backtype.storm.tuple.Tuple;
import backtype.storm.tuple.Values;

public class UserStatisticsAggregation extends BaseRichBolt{

	private OutputCollector collector;
	Map<String, Integer> user_tweets_counts = new HashMap<String, Integer>();
	int TOP_K = 1000;
	TweeterStreamHelper _TweeterStreamHelper = new TweeterStreamHelper();

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
		for (Status tweet : window_Tweet_List) {
			String userId = tweet.getUser().getScreenName();
			if(user_tweets_counts.containsKey(userId))
			{
				Integer tweet_counts = user_tweets_counts.get(userId);
				user_tweets_counts.put(userId, tweet_counts);
			}
			else if(user_tweets_counts.size()<TOP_K)
			{
				user_tweets_counts.put(userId, 1);
			}
			else
			{
				Entry<String,Integer> item_least_count = _TweeterStreamHelper.Get_Min_Word_Entry(user_tweets_counts);
				String user_least_count = item_least_count.getKey();
				Integer user_least_count_value = item_least_count.getValue();
				user_tweets_counts.remove(item_least_count);
				user_tweets_counts.put(userId, user_least_count_value+1);
			}		
		}			
		collector.emit(new Values(user_tweets_counts));
	}

	@Override
	public void declareOutputFields(OutputFieldsDeclarer declarer) {
		declarer.declare(new Fields("user_tweets_counts"));
	}
}
