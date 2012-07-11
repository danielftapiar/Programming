/**
 * 
 */

/**
 * @author Daniel FTR
 *
 */
public class Promedio {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		int nota1;
		int nota2;
		int nota3;
		int nota4;
		
		StdOut.println("Ingrese las Notas");
		nota1=StdIn.readInt();
		nota2=StdIn.readInt();
		nota3=StdIn.readInt();
		nota4=StdIn.readInt();
		StdOut.println("Primera Nota: "+ nota1);
		StdOut.println("Segunda Nota: "+ nota2);
		StdOut.println("Tercera Nota: "+ nota3);
		StdOut.println("Cuarta Nota: "+ nota4);
		StdOut.println("El promedio es: " + (nota1+nota2+nota3+nota4)/4);
	}

}
