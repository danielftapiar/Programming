/**
 * 
 */

/**
 * @author Daniel.Tapia FTR
 *
 */
public class Time {

	public static void main(String[] args) {
		int horactual,next,cont;
		StdOut.print("Hora Actual: ");
		horactual=StdIn.readInt();
		StdOut.print("Cantidad de Horas: ");
		next=StdIn.readInt();
		cont=next;
		while(cont>0)
		{
			horactual=horactual+1;
			cont=cont-1;
			if (horactual==24)
				horactual=0;
			
		}
		StdOut.println("En " + next + " horas, el reloj marcara las " + horactual );
	}

}	