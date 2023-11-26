module it.unibo.esiot.smart_bridge {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.ikonli.javafx;
    requires org.kordamp.bootstrapfx.core;
    requires jssc;

    opens it.unibo.esiot.smart_bridge to javafx.fxml;
    exports it.unibo.esiot.smart_bridge;
}