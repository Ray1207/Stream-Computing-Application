package storm.starter.util;

public class TEST {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		String text = "This is a good b as 3.";
		text = text.replaceAll("\\?", " ");
		text = text.toLowerCase();
		//text = text.replaceAll("[\\s]+(the|a|oh|http|of)[\\s]+", " ");
		text = text.replaceAll("\\b[a-z0-9]\\b", " ");
		System.out.println(text);
	}

}
