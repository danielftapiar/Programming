/**
 * 
 */

/**
 * @author Daniel FTR
 *
 */
public class Circulos {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		float radio; // variable creada para almacenar la entrada de datos
		StdOut.println("Ingrese el radio: ");
		radio=StdIn.readInt(); // se llama a la funcion StdIn(Standard Input) y almacena el dato en la variable radio
		
		StdOut.println("Perimetro:" + 2*radio*Math.PI); //Imprime por pantalla Perimetro
		StdOut.println("Area: " + Math.PI*radio*radio ); // Imprime por pantalla el Area
		


	}

}
