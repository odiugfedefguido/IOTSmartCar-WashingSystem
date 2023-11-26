package it.unibo.esiot.smart_bridge;

import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class DashboardController {

    @FXML
    private Label temperatureLabel;

    @FXML
    private Label carWashCounterLabel;

    @FXML
    private Label statusLabel;

    private int carWashCounter = 0;

    @FXML
    protected void onHelloButtonClick() {
        // welcomeText.setText("Welcome to JavaFX Application!");
    }

    public void displayTemperature(String temperature) {
        this.temperatureLabel.setText(temperature);
    }

    public void displayStatus(String status) {
        this.statusLabel.setText(status);
    }

    public void increaseWashes() {
        this.carWashCounterLabel.setText(String.valueOf(++this.carWashCounter));
    }
}