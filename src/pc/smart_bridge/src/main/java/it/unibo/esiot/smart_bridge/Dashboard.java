package it.unibo.esiot.smart_bridge;

import it.unibo.esiot.smart_bridge.connector.ExecutorServiceHelper;
import it.unibo.esiot.smart_bridge.connector.MessageService;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;
import javafx.util.Callback;
import jssc.SerialPortList;

import java.io.IOException;
import java.util.concurrent.*;

public class Dashboard extends Application {

    private static ExecutorService executor = Executors.newSingleThreadExecutor();
    private static final BlockingQueue<String> messageBuffer = new ArrayBlockingQueue<>(10, true);
    private static DashboardController dashboardController = new DashboardController();

    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(Dashboard.class.getResource("dashboard-view.fxml"));

        fxmlLoader.setControllerFactory((Callback<Class<?>, Object>) controllerClass -> {
            return this.dashboardController;
        });

        stage.setOnCloseRequest(new EventHandler<WindowEvent>() {
            @Override
            public void handle(WindowEvent event) {
                try {
                    ExecutorServiceHelper.shutdownAndAwaitTermination(executor);
                    Platform.exit();
                    System.exit(0);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

        Scene scene = new Scene(fxmlLoader.load(), 530, 660);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        if (args.length > 0) {
            executor.submit(new MessageService(args[0], messageBuffer, dashboardController));
            launch(args);
        } else {
            /* detect serial ports */
            System.out.println("Error. Pass the serial port as an argument.");
            System.out.println("Available ports:");
            for (String portName : SerialPortList.getPortNames()) {
                System.out.println("- " + portName);
            }
        }
    }
}
