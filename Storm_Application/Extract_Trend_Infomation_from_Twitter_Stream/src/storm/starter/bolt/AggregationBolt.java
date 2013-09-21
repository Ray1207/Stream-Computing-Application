package storm.starter.bolt;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import twitter4j.Status;
import backtype.storm.topology.BasicOutputCollector;
import backtype.storm.topology.OutputFieldsDeclarer;
import backtype.storm.topology.base.BaseBasicBolt;
import backtype.storm.tuple.Fields;
import backtype.storm.tuple.Tuple;
import backtype.storm.tuple.Values;

public class AggregationBolt  extends BaseBasicBolt {
	
	
	Map<String, Integer> accumulated_Tweet_word_counts = new HashMap<String, Integer>();
	Map<String, Integer> accumulated_Tweet_word_tweet_counts = new HashMap<String, Integer>();
	String a ="";

	

	@Override
	public Map<String, Object> getComponentConfiguration() {
		return null;
	}

	@SuppressWarnings("unchecked")
	@Override
	public void execute(Tuple tuple, BasicOutputCollector collector) {
		
		@SuppressWarnings("unchecked")
		Map<String, Integer> window_Tweet_word_counts = (Map<String, Integer>) tuple.getValue(0);
		Map<String, Integer> window_Tweet_word__tweet_counts = (Map<String, Integer>) tuple.getValue(1);
		
		
		
		//print last five minutes' statistcis
		Map<String, String> sortedMap_time_interval = sortByComparator(window_Tweet_word_counts);	
		
		String a ="";
		try
		{
			/*File file = new File("result.txt");
			if (!file.exists()) {
				file.createNewFile();
			}
			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);*/
			
			int count = 0;
			for (Map.Entry entry : sortedMap_time_interval.entrySet()) {
				if(count==20) break;
				String word = entry.getKey().toString();
				//bw.write(word+" "+ entry.getValue()+ " "+window_Tweet_word__tweet_counts.get(word));
				
				System.err.println(word+"zbsb "+ entry.getValue()+ " "+window_Tweet_word__tweet_counts.get(word));
				count++;
			}
			/*bw.write(""+window_Tweet_word_counts.size());
			
			bw.flush();
			bw.close();
			fw.close();*/
		}
		catch(Exception e)
		{
			
		}

		
		//put word frequency into accumulated map
		for(Map.Entry<String,Integer> entry : window_Tweet_word_counts.entrySet())
		{
			String word = entry.getKey();
			Integer word_counts = entry.getValue();
			
			if(accumulated_Tweet_word_counts.containsKey(word))
			{
				Integer current_tweet_word_frequency = accumulated_Tweet_word_counts.get(word);
				accumulated_Tweet_word_counts.put(word, current_tweet_word_frequency+word_counts);				
			}
			else
			{
				accumulated_Tweet_word_counts.put(word, word_counts);
			}
			
		}
		
		//put word frequency into accumulated tweet counts map
				for(Map.Entry<String,Integer> entry : window_Tweet_word__tweet_counts.entrySet())
				{
					String word = entry.getKey();
					Integer tweet_counts = entry.getValue();
					
					if(accumulated_Tweet_word_tweet_counts.containsKey(word))
					{
						Integer current_tweet_frequency = accumulated_Tweet_word_tweet_counts.get(word);
						accumulated_Tweet_word_tweet_counts.put(word, current_tweet_frequency+tweet_counts);				
					}
					else
					{
						accumulated_Tweet_word_counts.put(word, tweet_counts);
					}
					
				}
				
		// Sort whole map and get top 20
		Map<String, String> sortedMap_whole = sortByComparator(accumulated_Tweet_word_counts);	
		int count_whole = 0;
		for (Map.Entry entry : sortedMap_whole.entrySet()) {
			if(count_whole==20) break;
			String word = entry.getKey().toString();
			System.err.println(word+" "+ entry.getValue()+ " "+window_Tweet_word__tweet_counts.get(word));
			count_whole++;
		}
				
		//sort hash map first by value
		
		//before accumulating, report this five minutes
	}

	@Override
	public void declareOutputFields(OutputFieldsDeclarer declarer) {
		declarer.declare(new Fields("window_Tweet_Statistics"));
	}
	
	//Sort map by value
	@SuppressWarnings("unchecked")
	private static Map sortByComparator(Map unsortMap) {
		 
		List list = new LinkedList(unsortMap.entrySet());
 
		// sort list based on comparator
		Collections.sort(list, new Comparator() {
			public int compare(Object o1, Object o2) {
				return ((Comparable) ((Map.Entry) (o1)).getValue())
                                       .compareTo(((Map.Entry) (o2)).getValue());
			}
		});
 
		// put sorted list into map again
                //LinkedHashMap make sure order in which keys were inserted
		Map sortedMap = new LinkedHashMap();
		for (Iterator it = list.iterator(); it.hasNext();) {
			Map.Entry entry = (Map.Entry) it.next();
			sortedMap.put(entry.getKey(), entry.getValue());
		}
		return sortedMap;
	}


}
