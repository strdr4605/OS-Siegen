// Diese Klasse enthlt eine Integer Variable, die von allen
// Threads genutzt werden kann.
class CommonVar
{
	public int i;
	public CommonVar()
	{
		i = 0;
	}

	public synchronized void increment() { //added this to make it work properly
		++i;
	}
}

// Thread-Klasse
public class Test extends Thread
{
	private CommonVar cvar;

	// Konstruktor initialisiert Referenz auf gemeinsame Variable
	public Test(CommonVar c)
	{
		cvar = c;
	}

	// Implementierung der run() Methode
	public void run()
	{
		for (int i = 0; i < 1000000; i++) {
			// cvar.i++;      //this will not work with multiple threads
							  //accessing same object
			cvar.increment(); //in order to make it properly work we
							  //we need to make increment synchronized
		}
	}

	public static void main(String[] args) throws InterruptedException
	{
		CommonVar c = new CommonVar();
		Thread t1 = new Test(c);
		Thread t2 = new Test(c);

		// Starte Thread
		t1.start();
		t2.start();

		// Warte auf Thread-Ende
		t1.join();
		t2.join();

		// Drucke c.i
		System.out.println(c.i);
	}
}
