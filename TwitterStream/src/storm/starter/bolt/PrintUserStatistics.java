package storm.starter.bolt;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
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

public class PrintUserStatistics extends BaseBasicBolt{
	
	DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
	TweeterStreamHelper _TweeterStreamHelper = new TweeterStreamHelper();
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
		Map<String, Integer> user_tweets_counts = (Map<String, Integer>) tuple.getValue(0);
		
		Map<String, String> sorted_Map_time_interval = _TweeterStreamHelper.sortByComparator(user_tweets_counts);			
		
			int count = 0;
			for (Map.Entry entry : sorted_Map_time_interval.entrySet()) {
				if(count==20) break;
				String user = entry.getKey().toString();			
				System.out.println(user+" "+ entry.getValue());
				count++;
			}
	}

	@Override
	public void declareOutputFields(OutputFieldsDeclarer declarer) {
		declarer.declare(new Fields("print_user_statistics"));
	}

}
