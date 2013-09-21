package storm.starter.bolt;

import java.text.DateFormat;
import java.text.DecimalFormat;
import java.text.SimpleDateFormat;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import storm.starter.util.TweeterStreamHelper;

import backtype.storm.topology.BasicOutputCollector;
import backtype.storm.topology.OutputFieldsDeclarer;
import backtype.storm.topology.base.BaseBasicBolt;
import backtype.storm.tuple.Fields;
import backtype.storm.tuple.Tuple;

public class PrintTweetWordsStatistics extends BaseBasicBolt {
	DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
	private static final int default_Top_K = 20;
	private static final int default_Time_Interval = 300;
	private int Top_K;
	private int Time_Interval;
	DecimalFormat df = new DecimalFormat("#.##");
	TweeterStreamHelper _TweeterStreamHelper = new TweeterStreamHelper();
	
	public PrintTweetWordsStatistics() {
		this(default_Top_K,default_Time_Interval);
	}

	public PrintTweetWordsStatistics(int Top_K_value, int Time_Interval_value) {
		this.Top_K = Top_K_value;
		this.Time_Interval = Time_Interval_value;
	}
	
	@Override
	public Map<String, Object> getComponentConfiguration() {
		return null;
	}

	@SuppressWarnings("unchecked")
	@Override
	public void execute(Tuple tuple, BasicOutputCollector collector) {
		Date date = new Date();
		System.err.println(dateFormat.format(date));
		
		@SuppressWarnings("unchecked")
		Map<String, Integer> window_Tweet_word_counts = (Map<String, Integer>) tuple.getValue(0);
		Map<String, Integer> window_Tweet_word__tweet_counts = (Map<String, Integer>) tuple.getValue(1);
		
		Map<String, String> sorted_Map_time_interval = _TweeterStreamHelper.sortByComparator(window_Tweet_word_counts);					
			int count = 0;
			for (Map.Entry entry : sorted_Map_time_interval.entrySet()) {
				if(count==Top_K) break;
				String word = entry.getKey().toString();	
				String frequency_per_second = df.format(Double.parseDouble(entry.getValue().toString())/Time_Interval);
				System.out.println(word+"\t"+ window_Tweet_word__tweet_counts.get(word)+ "\t"+frequency_per_second);
				count++;
			}
	}

	@Override
	public void declareOutputFields(OutputFieldsDeclarer declarer) {
		declarer.declare(new Fields("window_Tweet_Statistics"));
	}
}
