package storm.starter.util;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.Map.Entry;

public class TweeterStreamHelper {

	//Get stop words list
	public String Obtain_Stop_Words_List()
	{
		try
		{
			String stop_words_list="a";
			BufferedReader brTest = new BufferedReader(new FileReader("stop_words.txt"));
			String stop_word_line = brTest.readLine();
			
			while (stop_word_line != null) {
				StringTokenizer stop_words = new StringTokenizer(stop_word_line,",");
				while (stop_words.hasMoreTokens()) {
					String stop_word = stop_words.nextToken();					
					  stop_words_list = stop_words_list+"|"+stop_word;
				}				
				stop_word_line = brTest.readLine();
			}
			 
			stop_words_list = stop_words_list+"a";
			return stop_words_list;
		}
		catch(Exception e)
		{
			return "";
		}
		
	}
	
	//Filter tweets
	public String Filter_Text(String text,String stop_words_list)
	{
		text = text.replaceAll("@[a-zA-Z0-9]+", " ");			
		text = text.replaceAll("[^a-zA-Z0-9\\s]", " ");
		text = text.replaceAll("\\bRT\\b", " ");
		text = text.toLowerCase();
		text = text.replaceAll("\\b[a-z0-9]\\b", " ");
		text = text.replaceAll("\\b[0-9]+\\b", " ");
		text = text.replaceAll("\\b("+stop_words_list+")\\b", " ");
		return text;
	}
	
	//Calculate similarity of two users based on tweets
	public double Calculate_Similarity(Entry<String, Map<String, Integer>> user_stat1,Entry<String, Map<String, Integer>> user_stat2)
	{
		String user1 = user_stat1.getKey();
		Map<String, Integer> user_words_statistics1 = user_stat1.getValue();
		
		String user2 = user_stat2.getKey();
		Map<String, Integer> user_words_statistics2 = user_stat2.getValue();
		
		Map<String, Integer> copy_user_words_statistics1 = new HashMap<String, Integer>(user_words_statistics1);
		Map<String, Integer> copy_user_words_statistics2 = new HashMap<String, Integer>(user_words_statistics2);
		
		Set words_set1 = copy_user_words_statistics1.keySet();
		Set words_set2 = copy_user_words_statistics2.keySet();
		words_set1.retainAll(words_set2);
		
		//calculate the sum of g(w1,w2)
		double sum_G = 0;	
		Iterator iter = words_set1.iterator();
		while (iter.hasNext()) {
			   String common_word =iter.next().toString();
			   sum_G += user_words_statistics1.get(common_word)*user_words_statistics2.get(common_word);
			}

		//calculate words set1's value
		double sum_frequency_set1 = 0;
		for(Entry<String, Integer> entry : user_words_statistics1.entrySet())
		{
			sum_frequency_set1+= Math.pow(entry.getValue(), 2);
		}
		//calculate words set1's value
		double sum_frequency_set2 = 0;
		for(Entry<String, Integer> entry : user_words_statistics2.entrySet())
		{
			sum_frequency_set2+= Math.pow(entry.getValue(), 2);
		}
		
		if(sum_frequency_set1==0||sum_frequency_set2==0)
			return 0;
		double similarity = sum_G/(Math.sqrt(sum_frequency_set1)*Math.sqrt(sum_frequency_set2));				
		return similarity;
	}
	
	//Get the item with least value in a map
	public Entry<String,Integer> Get_Min_Word_Entry(Map<String, Integer> map)
	{
		Entry<String, Integer> min = null;
		for (Entry<String, Integer> entry : map.entrySet()) {
		    if (min == null || min.getValue() > entry.getValue()) {
		        min = entry;
		    }
		}		
		return min;
	}
	
	//sort a map based on its value descending
	@SuppressWarnings("unchecked")
	public static Map sortByComparator(Map unsortMap) {
		 
		List list = new LinkedList(unsortMap.entrySet());
 
		// sort list based on comparator
		Collections.sort(list, new Comparator() {
			public int compare(Object o1, Object o2) {
				return ((Comparable) ((Map.Entry) (o2)).getValue())
                                       .compareTo(((Map.Entry) (o1)).getValue());
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
