#include <QApplication>
#include <QWidget>
#include <QPainter>

// 1. Create a minimal widget that hooks into the paint event
class DemoWidget : public QWidget {
protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        
        // Draw a basic background canvas
        painter.fillRect(rect(), Qt::white);
        
        // Draw a simple blue test rectangle
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 14, QFont::Bold));
        painter.drawText(rect(), Qt::AlignCenter, "QPainter Ready!");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    DemoWidget window;
    window.resize(400, 300);
    window.setWindowTitle("QPainter Demo");
    window.show();

    return app.exec();
}

