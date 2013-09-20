package storm.starter.comp90056;

import backtype.storm.Config;
import backtype.storm.LocalCluster;
import backtype.storm.StormSubmitter;
import backtype.storm.task.ShellBolt;
import backtype.storm.topology.BasicOutputCollector;
import backtype.storm.topology.IRichBolt;
import backtype.storm.topology.OutputFieldsDeclarer;
import backtype.storm.topology.TopologyBuilder;
import backtype.storm.topology.base.BaseBasicBolt;
import backtype.storm.tuple.Fields;
import backtype.storm.tuple.Tuple;
import backtype.storm.tuple.Values;
import storm.starter.spout.RandomSentenceSpout;
import storm.starter.spout.TextFileReaderSpout;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/**
 * This topology demonstrates Storm's stream groupings and multilang
 * capabilities.
 */
public class WordCountTopology {

	public static class SplitSentence extends BaseBasicBolt {

		@Override
		public Map<String, Object> getComponentConfiguration() {
			return null;
		}

		@Override
		public void execute(Tuple tuple, BasicOutputCollector collector) {
			String sentence = tuple.getString(0);
			if(sentence.equals("90056FinalMarker"))
			{
				collector.emit(new Values("90056FinalMarker"));
			}
			else
			{
				String[] words = sentence.split("[\\s]+");
				for (String word : words) {
					collector.emit(new Values(word));
				}
			}
			
		}

		@Override
		public void declareOutputFields(OutputFieldsDeclarer declarer) {
			declarer.declare(new Fields("word"));
		}

	}

	public static class WordCountFrequenAlgBolt extends BaseBasicBolt {
		// ArrayList<String> container = new ArrayList<String>();
		Map<String, Integer> TopK = new HashMap<String, Integer>();
		int K = 8;
		int n = 0;
		@Override
		public void execute(Tuple tuple, BasicOutputCollector collector) {
			String word = tuple.getString(0);
			if (word.equals("90056FinalMarker")) {
				System.out.println("Following is a list of the top 5 frequent words.");
				for (Map.Entry<String, Integer> entry : TopK.entrySet()) {
					System.out
							.println(entry.getKey() + ": " + entry.getValue());
				}
			} else {
				if (TopK.get(word) != null && TopK.get(word) != 0) {
					int value = TopK.get(word) + 1;
						TopK.put(word,value);					
				} else if (TopK.size() < K) {
					TopK.put(word, 1);
				} else {
					ArrayList<String> need_To_Remove = new ArrayList<String>();
					for (Map.Entry<String, Integer> entry : TopK.entrySet()) {
						int newFrequency = entry.getValue() - 1;
						TopK.put(entry.getKey(), newFrequency);
						if(newFrequency==0)
						{
							need_To_Remove.add(entry.getKey());
						}
						
					}
					for (String key : need_To_Remove) {
							TopK.remove(key);
					}
				}
			}

		}

		@Override
		public void declareOutputFields(OutputFieldsDeclarer declarer) {
			declarer.declare(new Fields("word", "count"));
		}
	}

	public static void main(String[] args) throws Exception {

		TopologyBuilder builder = new TopologyBuilder();

		builder.setSpout("spout", new TextFileReaderSpout(), 5);

		builder.setBolt("split", new SplitSentence(), 8).shuffleGrouping(
				"spout");

		builder.setBolt("count", new WordCountFrequenAlgBolt(), 12).fieldsGrouping("split",
				new Fields("word"));

		Config conf = new Config();
		conf.setDebug(true);

		if (args != null && args.length > 0) {
			conf.setNumWorkers(3);

			StormSubmitter.submitTopology(args[0], conf,
					builder.createTopology());
		} else {
			conf.setMaxTaskParallelism(3);

			LocalCluster cluster = new LocalCluster();
			cluster.submitTopology("word-count", conf, builder.createTopology());
			
			Thread.sleep(10000);

			//cluster.shutdown();
		}
	}
}
