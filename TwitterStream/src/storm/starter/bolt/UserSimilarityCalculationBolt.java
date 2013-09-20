package storm.starter.bolt;

import java.text.DateFormat;
import java.text.DecimalFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.StringTokenizer;

import storm.starter.util.TweeterStreamHelper;
import twitter4j.Status;
import backtype.storm.task.OutputCollector;
import backtype.storm.task.TopologyContext;
import backtype.storm.topology.OutputFieldsDeclarer;
import backtype.storm.topology.base.BaseRichBolt;
import backtype.storm.tuple.Fields;
import backtype.storm.tuple.Tuple;
import backtype.storm.tuple.Values;

public class UserSimilarityCalculationBolt extends BaseRichBolt{
	private OutputCollector collector;
	DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
	DecimalFormat decimal_Format = new DecimalFormat("#.####");
	private static final double default_similarity_threshold = 0.65;
	private double similarity_threshold;
	TweeterStreamHelper _TweeterStreamHelper= new TweeterStreamHelper();
	
	public UserSimilarityCalculationBolt() {
		this(default_similarity_threshold);
	}

	public UserSimilarityCalculationBolt(double similarity_threshold_value) {
		this.similarity_threshold = similarity_threshold_value;
	}
	
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
		Map<String, Map<String, Integer>> user_tweet_words_list = (Map<String, Map<String, Integer>>) tuple.getValue(0);
		Date date = new Date();
		System.err.println(dateFormat.format(date));
		
		for (Entry<String, Map<String, Integer>> entry : user_tweet_words_list.entrySet()) {
			String user  = entry.getKey();
			Map<String, Integer> user_words_statistics = entry.getValue();			
			for(Entry<String, Map<String, Integer>> entry_others : user_tweet_words_list.entrySet())
			{
				if(entry_others.getKey().equals(user))
					continue;
				double similarity = _TweeterStreamHelper.Calculate_Similarity(entry,entry_others);
				if(similarity>similarity_threshold)
				{
					System.out.println(user+" "+entry_others.getKey()+" "+similarity);
				}
			}
		}	
	}

	@Override
	public void declareOutputFields(OutputFieldsDeclarer declarer) {
		declarer.declare(new Fields("user_similarity_scores"));
	}
	

}
