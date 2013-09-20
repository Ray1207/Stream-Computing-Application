

package storm.starter.spout;

import backtype.storm.Config;
import twitter4j.auth.AccessToken;
import twitter4j.conf.ConfigurationBuilder;
import twitter4j.TwitterStream;
import twitter4j.TwitterStreamFactory;
import backtype.storm.spout.SpoutOutputCollector;
import backtype.storm.task.TopologyContext;
import backtype.storm.topology.OutputFieldsDeclarer;
import backtype.storm.topology.base.BaseRichSpout;
import backtype.storm.tuple.Fields;
import backtype.storm.tuple.Values;
import backtype.storm.utils.Utils;
import java.util.Map;
import java.util.concurrent.LinkedBlockingQueue;
import twitter4j.Status;
import twitter4j.StatusDeletionNotice;
import twitter4j.StatusListener;

public class TwitterStreamSpout extends BaseRichSpout {
    SpoutOutputCollector _collector;
    LinkedBlockingQueue<Status> queue = null;
    TwitterStream _twitterStream;
    String ConsumerKey = "27U1FBgLjab2EUJKm2Hrw";
    String ComsumerSecret = "rgPYtkfCklvRfCDWLWf4CkmQTStn5w3u1v2rv6qQ";
    String Access_Token = "787068782-VSPP0Dx9spgB5cus02wb5a00UDMmYqfkfHkVmacC";
    String Access_token_Secret ="PLFrnF0LDCDsxS8tWrxxbW5ixyeINVzle9PI6yErMGg"; 
    
    public TwitterStreamSpout() {
    }
    
    @Override
    public void open(Map conf, TopologyContext context, SpoutOutputCollector collector) {
        queue = new LinkedBlockingQueue<Status>(1000);
        _collector = collector;
        StatusListener listener = new StatusListener() {
            @Override
            public void onStatus(Status status) {
                queue.offer(status);
            }

            @Override
            public void onDeletionNotice(StatusDeletionNotice sdn) {
            }

            @Override
            public void onTrackLimitationNotice(int i) {
            }

            @Override
            public void onScrubGeo(long l, long l1) {
            }

            @Override
            public void onException(Exception e) {
            	e.printStackTrace();
            }
            
        };
        _twitterStream = new TwitterStreamFactory(new ConfigurationBuilder().setJSONStoreEnabled(true).build()).getInstance();
        _twitterStream.setOAuthConsumer(ConsumerKey, ComsumerSecret);
        _twitterStream.setOAuthAccessToken(new AccessToken(Access_Token,Access_token_Secret));           
        _twitterStream.addListener(listener);
        _twitterStream.sample();
    }

    @Override
    public void nextTuple() {
        Status ret = queue.poll();
        if(ret==null) {
            Utils.sleep(50);
        } else {
            _collector.emit(new Values(ret));
        }
    }

    @Override
    public void close() {
        _twitterStream.shutdown();
    }

    @Override
    public Map<String, Object> getComponentConfiguration() {
        Config ret = new Config();
        ret.setMaxTaskParallelism(1);
        return ret;
    }    

    @Override
    public void ack(Object id) {
    }

    @Override
    public void fail(Object id) {
    }

    @Override
    public void declareOutputFields(OutputFieldsDeclarer declarer) {
        declarer.declare(new Fields("tweet"));
    }
    
}
