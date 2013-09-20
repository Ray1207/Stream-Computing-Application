package storm.starter.bolt;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import storm.starter.util.TupleHelpers;
import twitter4j.Status;
import backtype.storm.Config;
import backtype.storm.task.OutputCollector;
import backtype.storm.task.TopologyContext;
import backtype.storm.topology.OutputFieldsDeclarer;
import backtype.storm.topology.base.BaseRichBolt;
import backtype.storm.tuple.Fields;
import backtype.storm.tuple.Tuple;
import backtype.storm.tuple.Values;

//In this Bolt, I will implement windowing and language filtering
public class WindowingTwitterStream extends BaseRichBolt {
	TupleHelpers _tupleHelper;
	private OutputCollector collector;
	private List<Status> windowArrayList;
	private Status stat;
	private String twitterTextString;
	private static final int default_tick_frequency_in_seconds = 1;
	private int tick_frequency_in_seconds;
	
	public WindowingTwitterStream() {
		this(default_tick_frequency_in_seconds);
	}

	public WindowingTwitterStream(int emitFrequencyInSeconds) {
		this.tick_frequency_in_seconds = emitFrequencyInSeconds;
	}

	@Override
	public void prepare(Map stormConf, TopologyContext context,
			OutputCollector collector) {
		windowArrayList = new ArrayList<Status>();
		this.collector = collector;
	}

	@Override
	public void execute(Tuple tuple) {

		if (TupleHelpers.isTickTuple(tuple)) {
			List<Status> copy_of_windowArrayList = new ArrayList<Status>(windowArrayList);
			collector.emit(new Values(copy_of_windowArrayList));
			windowArrayList.clear();						
		} else {
			Status tupleStatus = (Status) tuple.getValue(0);
			// Filter languages that are not English
			String language = tupleStatus.getUser().getLang();
			if (language.equals("en")) {				
				windowArrayList.add(tupleStatus);
			}
		}

	}

	@Override
	public Map<String, Object> getComponentConfiguration() {
		//Map<String, Object> conf = new HashMap<String, Object>();
		Config conf = new Config();
		conf.setMaxTaskParallelism(1);
		conf.put(Config.TOPOLOGY_TICK_TUPLE_FREQ_SECS,
				tick_frequency_in_seconds);
		return conf;
	}

	@Override
	public void declareOutputFields(OutputFieldsDeclarer declarer) {
		declarer.declare(new Fields("TwitterValue"));
	}

}
