#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void onDrawingToolButtonToggled(int drawingContent, bool checked);

 private:
    Ui::MainWindow *ui;

    //std::map<QPushButton*, DrawingToolButtonInfo> drawingToolButtons;   //  存放绘图工具button指针和其对应的信息

};

#endif // MAINWINDOW_H
