
public class ThreadDemo {
    public static void main(String[] args) {
        System.out.println("Main thread started.");

        for (int i = 1; i <= 4; i++) {
            final int threadNumber = i;

            Thread worker = new Thread(() -> {
                try {
                    System.out.println("Worker " + threadNumber + " started.");
                    Thread.sleep(60000);
                    System.out.println("Worker " + threadNumber + " finished.");
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            });

            worker.start();
        }

        System.out.println("Main thread finished.");
    }
}
