#include "MainView.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "BaseItem.h"
QList<QPushButton* > btnlist;
MainView::MainView(QWidget *parent) : QWidget(parent)
{
    view=new QGView;

    QList<QString> namelist;
    namelist<<QStringLiteral("矩形")<<QStringLiteral("矩形旋转");
    namelist<<QStringLiteral("圆形")<<QStringLiteral("椭圆旋转");
    namelist<<QStringLiteral("同心圆")<<QStringLiteral("饼图");
    namelist<<QStringLiteral("多边形")<<QStringLiteral("圆端矩形");
    namelist<<QStringLiteral("圆角矩形")<<QStringLiteral("直线");
    namelist<<QStringLiteral("卡尺")<<QStringLiteral("锚点-无");
    namelist<<QStringLiteral("打开图片")<<QStringLiteral("清空");

//    namelist<<"矩形"<<"矩形旋转";
//    namelist<<"圆形"<<"椭圆旋转";
//    namelist<<"同心圆"<<"饼图";
//    namelist<<"多边形"<<"圆端矩形";
//    namelist<<"圆角矩形"<<"直线";
//    namelist<<"卡尺"<<"锚点-无";
//    namelist<<"打开图片"<<"清空";
    QList<QString> objname;
    objname<<"a1"<<"a2";
    objname<<"a3"<<"a4";
    objname<<"a5"<<"a6";
    objname<<"a7"<<"a8";
    objname<<"a9"<<"a10";
    objname<<"a11"<<"a12";
    objname<<"a13"<<"a14";

    auto BtnArea=new QVBoxLayout;
    QSize sz(80,30);
    for (int i=0;i<objname.length();i++)
    {
        auto btn=new QPushButton;
        btn->setFixedSize(sz);
        btn->setText(namelist[i]);
        btn->setObjectName(objname[i]);
        BtnArea->addWidget(btn);
        btn->installEventFilter(this);
        btnlist<<btn;
    }

    auto MainArea=new QHBoxLayout;
    MainArea->addLayout(BtnArea);
    MainArea->addWidget(view);

    this->setLayout(MainArea);
}

Caliper* ptr;

bool MainView::eventFilter(QObject *obj, QEvent *event)
{
    QMouseEvent *MouseEvent = static_cast<QMouseEvent *>(event);

    if((MouseEvent->buttons() == Qt::LeftButton)&&(event->type() == QEvent::MouseButtonPress))
    {
        QString Name=obj->objectName();
        //QAbstractButton *CkBtn = qobject_cast<QAbstractButton *>(obj);
        int itemCount = view->items().size();
        if(Name=="a1")
        {
            auto obj=new RectangleItem(200,200,200,200);
            obj->setItemDiscrib(QString::number(itemCount));
            view->AddItems(obj);
            qDebug() << obj->GetObject().x << obj->GetObject().y << obj->GetObject().width << obj->GetObject().height;

        }
        if(Name=="a2")
        {
            auto obj=new RectangleRItem(200,200,200,200,3.14/6);

            view->AddItems(obj);
        }
        if(Name=="a3")
        {
            auto obj=new CircleItem(200,200,300);

            view->AddItems(obj);
        }
        if(Name=="a4")
        {
            auto obj=new EllipseItem(200,200,300,200,0.2);
            view->AddItems(obj);
        }
        if(Name=="a5")
        {
            auto obj=new ConcentricCircleItem(200,200,200,300);
            view->AddItems(obj);
        }
        if(Name=="a6")
        {
            auto obj=new PieItem(200,200,200,3.14/3,0);
            view->AddItems(obj);
        }
        if(Name=="a7")
        {
            //DefCircle
          // ptr->SetObject(DefCaliper(100,100,500,100,100));



//PolygonItem

//            view->scene->startCreate();
//            for (int i=0;i<btnlist.length();i++)
//            {
//                btnlist[i]->setEnabled(false);
//            }
//            //setBtnEnabled(false);


            QVector<QPointF> P;
            P<<QPointF(50,100)<<QPointF(50,120)<<QPointF(90,190)<<QPointF(100,70)<<QPointF(90,20)<<QPointF(200,100);
            PolygonItem *m_polygon = new PolygonItem(P);
            view->AddItems(m_polygon);
//            view->scene->addItem(m_polygon);

//            connect(view->scene, SIGNAL(updatePoint(QPointF, QList<QPointF>, bool)), m_polygon, SLOT(pushPoint(QPointF, QList<QPointF>, bool)));
//            connect(view->scene, &QGraphicsScenes::createFinished, [=]()
//            {
//                for (int i=0;i<btnlist.length();i++)
//                {
//                    btnlist[i]->setEnabled(true);
//                }
//            });
        }
        if(Name=="a8")
        {
            auto obj=new RoundRectangle1Item(50,100,200,100,100);
            view->AddItems(obj);
        }
        if(Name=="a9")
        {
            //auto item=ptr->GetObject();
            //qDebug()<<item.X1<<item.Y1;
            //qDebug()<<item.X2<<item.Y2;
        }
        if(Name=="a10")
        {
            auto obj=new LineItem(0,0,300,200);
            view->AddItems(obj);
        }
        if(Name=="a11")//Caliper
        {
            auto obj=new Caliper(0,0,300,200,30);
            ptr=obj;
            view->AddItems(obj);
        }
        if(Name=="a12")
        {
            auto obj=new PointItem(0,0);
            view->AddItems(obj);

//            MRectangle rec;
//            ptr->GetRect(rec);

//            qDebug()<<rec.cols;
//            qDebug()<<rec.rows;
//            qDebug()<<rec.width;
//            qDebug()<<rec.height;
        }
        if(Name=="a13")
        {
            QImage img("d.bmp");
            view->DispImage(img);
        }
        if(Name=="a14")
        {
            view->ClearObj();
        }
    }


return QObject::eventFilter(obj, event);

}
