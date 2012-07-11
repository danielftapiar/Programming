/**
 * 
 */

/**
 * @author Daniel FTR
 *
 */
public class Pitagoras {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		float a;
		float b;
		StdOut.print("Ingrese cateto a: ");
		a=StdIn.readInt();
		StdOut.print("Ingrese cateto b: ");
		b=StdIn.readInt();
		StdOut.print("La Hipotenusa es : " +Math.sqrt(a*a+b*b ));
		
	}

}
