package TwitterTrend;

import storm.starter.bolt.PrepareUserSimilarityCalculationBolt;
import storm.starter.bolt.PrintTweetWordsStatistics;
import storm.starter.bolt.TokenizeTweetsBolt;
import storm.starter.bolt.UserSimilarityCalculationBolt;
import storm.starter.bolt.WindowingTwitterStream;
import storm.starter.spout.TwitterStreamSpout;
import backtype.storm.Config;
import backtype.storm.LocalCluster;
import backtype.storm.StormSubmitter;
import backtype.storm.topology.TopologyBuilder;

public class UserSimilarity {

	public static void main(String[] args) throws Exception {

		TopologyBuilder builder = new TopologyBuilder();
		builder.setSpout("spout", new TwitterStreamSpout(), 5);
		builder.setBolt("windowingTwitterStream", new WindowingTwitterStream(300), 1)
				.shuffleGrouping("spout");		
		
		builder.setBolt("PrepareUserSimilarityCalculationBolt", new PrepareUserSimilarityCalculationBolt(), 1).shuffleGrouping("windowingTwitterStream");			
		builder.setBolt("UserSimilarityCalculationBolt", new UserSimilarityCalculationBolt(), 1).shuffleGrouping("PrepareUserSimilarityCalculationBolt");	

		Config conf = new Config();
		conf.setDebug(false);

		if (args != null && args.length > 0) {
			conf.setNumWorkers(3);
			StormSubmitter.submitTopology(args[0], conf,
					builder.createTopology());
		} else {
			conf.setMaxTaskParallelism(3);
			LocalCluster cluster = new LocalCluster();
			cluster.submitTopology("word-count", conf, builder.createTopology());
			// Thread.sleep(10000);
			// cluster.shutdown();
		}
	}
	
}
