class PrintingThread extends Thread {
    private char letter;
    private int times;

    PrintingThread(char letter, int times) {
        this.letter = letter;
        this.times = times;
    }
    
    public void run() {
        for(int i = 0; i < times; ++i) {
            System.out.println(letter);
        }
        System.out.println("Thread printing letter \"" + letter + "\" exiting.");
    }
}

public class MultithreadedCharPrinting {
    public static void main(String args[]) {
        char[] letters = {'a', 'b', 'c', 'd'};
        int times = 100;
        for(char letter : letters) {
            PrintingThread printingThread = new PrintingThread(letter, times);
            printingThread.start();
            try {
                //printingThread.sleep(1000);//sleeps for amount of milisesconds
                printingThread.join();    //wait for thread to finish
            }catch (InterruptedException e) {
                System.out.println("Thread printing letter \"" + letter + "\" was interrupted.");
            }
            //printingThread.yield();     //pauses current thread and allow
                                        //other thread to execute
        }
    }  
}
