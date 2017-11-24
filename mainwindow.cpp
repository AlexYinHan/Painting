#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <list>
#include <string>
#include <QSignalMapper>
#include <QPushButton>
#include "common.h"

/*
 * 添加绘图工具按钮时，只要在下面的drawingToolButtonInfo[]中增加相应的按钮文字/文件名，和对应的图元类型的编号，并修改drawingToolButtonNum
 * 所有绘图工具按钮的同一类型事件都在同一个函数中统一处理
 */
struct DrawingToolButtonInfo
{
    QString title;
    CONTENT_DRAWING content;
};
DrawingToolButtonInfo drawingToolButtonInfo[] = {
    {":/image/res/2dGraphics/Line.png", LINE},
    {":/image/res/2dGraphics/Circle.png", CIRCLE},
    {":/image/res/2dGraphics/Oval.png", OVAL}
};
const int drawingToolButtonNum = 3;

QButtonGroup* drawingToolButtons = new QButtonGroup();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置绘图工具按钮
    drawingToolButtons->setExclusive(true); //  checked状态互斥

    for(int i = 0; i < drawingToolButtonNum; i ++)
    {
        // 初始化按钮
        QPushButton* button = new QPushButton();
        button->setCheckable(true);
        QIcon icon;
        icon.addFile(drawingToolButtonInfo[i].title);
        //qDebug() << icon.actualSize(QSize(90, 90)) << endl;
        button->setIcon(icon);
        button->setFlat(true);
        button->setFixedSize(QSize(60, 60));

        // 把这个按钮加入group
        drawingToolButtons->addButton(button, i);

        //drawingToolButtons.insert(map<QPushButton*, DrawingToolButtonInfo>::value_type(button, drawingToolButtonInfo[i]));

        // 所有绘图工具按钮在一个垂直布局中
        ui->gridLayout->addWidget(button, 3, i%3);  //  每行3个
    }
    connect(drawingToolButtons, SIGNAL(buttonToggled(int, bool)), this, SLOT(onDrawingToolButtonToggled(int, bool)));
}

MainWindow::~MainWindow()
{
    delete drawingToolButtons;
    delete ui;
}


void MainWindow::onDrawingToolButtonToggled(int drawingToolButtonId, bool checked)
{
    if(checked)
    {
        ui->DrawingArea->drawingContent = drawingToolButtonInfo[drawingToolButtonId].content;
        ui->DrawingArea->drawingState = willDraw;
    }
    else
    {
        ui->DrawingArea->drawingContent = EMPTY;
        ui->DrawingArea->drawingState = completeDrawing;
    }

    /*
     * 本来使用signalMapper将所有的绘图工具按钮使用统一的函数来处理事件，并且使得添加按钮的工作简化
     * 但是这样想让所有按钮的checked状态互斥比较麻烦
     * 后来改用QButtonGroup，可以很方便地实现想要的功能
     */

    /*  使用signalMapper的方法
     * 使用全局变量 std::list<QPushButton*> drawingToolButtonPointers; 记录按钮的指针
     * 在mainWindow构造函数中
        //创建信号匹配器
        QSignalMapper* signalMapper = new QSignalMapper(this);

        // 记录指向这个按钮的指针
       drawingToolButtonPointers.push_back(button);

        // 连接按钮信号
        connect(button, SIGNAL(toggled(bool)), signalMapper, SLOT(map()));
        signalMapper->setMapping(button, (int)(drawingToolButtonInfo[i].content));

        //连接配对信号
        connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(onDrawingToolButtonToggled(int)));

      * 在onDrawingToolButtonToggled(int drawingContent)函数中

        QPushButton *senderButton = qobject_cast<QPushButton *>(((QSignalMapper*)sender())->mapping(drawingContent));

    // 这里sender()返回的是signalMapper，所以先获取到匹配的button再做类型转换
    // 如果两个按钮发送的int消息是一样的，那么这一步得到的button可能是两个中的随机一个按钮，所以可能得到的不是真正被点击的按钮
    // 因为本例中每个按钮对应的图元类型是不同的，所以实际上所有drawingToolButton发送的消息都是不一样的

    if(senderButton == NULL)
    {
        qDebug() << "匹配按钮失败" << endl
                 << "void MainWindow::onDrawingToolButtonToggled(int drawingContent);" << endl
                 << "drawingContent = " << drawingContent << endl << endl;
        return;
    }

    if(senderButton->isChecked())
    {
        // 其他所有按钮的checked置为false
        // for_each(drawingToolButtonPointers.begin(), drawingToolButtonPointers.end(), [](QPushButton* &thisButton)
        // {
        //    thisButton->setChecked(false);
        // });
        // senderButton->setChecked(true);
        ui->DrawingArea->drawingContent = (CONTENT_DRAWING)drawingContent;
        ui->DrawingArea->drawingState = willDraw;
    }
    else
    {
        ui->DrawingArea->drawingContent = EMPTY;
        ui->DrawingArea->drawingState = completeDrawing;
    }
    */
}
