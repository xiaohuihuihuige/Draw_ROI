#ifndef DEFINEDATATYPE_H
#define DEFINEDATATYPE_H

#endif // DEFINEDATATYPE_H
#include <QPointF>
#include <QVector>



//矩形
struct DefRect
{
    DefRect():x(0),y(0),width(0),height(0)
    {

    }
    DefRect(float x,float y,float width,float height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }
    DefRect(QPointF topLeftP,float width,float height)
    {
        this->x = topLeftP.x();
        this->y = topLeftP.y();
        this->width = width;
        this->height = height;
    }

    float x;
    float y;
    float width;
    float height;
};

//旋转矩形
struct DefRotateRect
{
    DefRotateRect():x(0),y(0),width(0),height(0),angle(0)
    {

    }
    DefRotateRect(float x,float y,float length1,float length2,float angDeg)
    {
        this->x = x;
        this->y = y;
        this->width = length1;
        this->height = length2;
        angle = angDeg;
    }
    DefRotateRect(QPointF center,float length1,float length2,float angDeg)
    {
        this->x = center.x();
        this->y = center.y();
        this->width = length1;
        this->height = length2;
        angle = angDeg;
    }

    float x;
    float y;
    float width;
    float height;
    float angle;

    QVector<QPointF> cornerPoints = QVector<QPointF>(4);//四个角点坐标
};

//圆形
struct DefCircle
{
    DefCircle():x(0),y(0),r(0)
    {

    }
    DefCircle(float x,float y,float r)
    {
        this->x = x;
        this->y = y;
        this->r = r;
    }
    DefCircle(QPointF center,float r)
    {
        this->x = center.x();
        this->y = center.y();
        this->r = r;
    }
    float x;
    float y;
    float r;
};

//旋转椭圆
struct DefRotateEllipse
{
    DefRotateEllipse():x(0),y(0),width(0),height(0),angle(0)
    {

    }
    DefRotateEllipse(float x,float y,float length1,float length2,float angDeg)
    {
        this->x = x;
        this->y = y;
        this->width = length1;
        this->height = length2;
        this->angle = angDeg;
    }
    DefRotateEllipse(QPointF center, float length1, float length2, float angDeg)
    {
        this->x = center.x();
        this->y = center.y();
        this->width = length1;
        this->height = length2;
        this->angle = angDeg;
    }

    float x;
    float y;
    float width;
    float height;
    float angle;

    QVector<QPointF> cornerPoints = QVector<QPointF>(4);//四个角点坐标
};

//同心圆
struct DefConcentricCircle
{
    DefConcentricCircle():x(0),y(0),rOuter(0),rInner(0)
    {

    }
    DefConcentricCircle(float x,float y,float rOuter,float rInner)
    {
        this->x = x;
        this->y = y;
        this->rOuter = rOuter;
        this->rInner = rInner;
    }
    DefConcentricCircle(QPointF center,float rOuter,float rInner)
    {
        this->x = center.x();
        this->y = center.y();
        this->rOuter = rOuter;
        this->rInner = rInner;
    }
    float x;
    float y;
    float rOuter;
    float rInner;
};

//饼图
struct DefPie
{
    DefPie():x(0),y(0),r(0),angleStart(0),angleEnd(0)
    {

    }
    DefPie(float x,float y,float r,float angleStart,float angleEnd)
    {
        this->x = x;
        this->y = y;
        this->r = r;
        this->angleStart = angleStart;
        this->angleEnd = angleEnd;
    }
    DefPie(QPointF Center,float r,float angleStart,float angleEnd)
    {
        this->x = Center.x();
        this->y = Center.y();
        this->r = r;
        this->angleStart = angleStart;
        this->angleEnd = angleEnd;
    }

    float x;
    float y;
    float r;
    float angleStart;
    float angleEnd;
};

//圆角矩形
struct DefRoundRect
{
    DefRoundRect():x(0),y(0),width(0),height(0),r(0)
    {}
    DefRoundRect(float x,float y,float width,float height,float r)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->r = r;
    }
    DefRoundRect(QPointF topLeftP,float width,float height,float r)
    {
        this->x = topLeftP.x();
        this->y = topLeftP.y();
        this->width = width;
        this->height = height;
        this->r = r;
    }
    float x;
    float y;
    float width;
    float height;
    float r;
};
//直线
struct DefLine
{
    DefLine():x1(0),y1(0),x2(0),y2(0)
    {}
    DefLine(float x1,float y1,float x2,float y2)
    {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
    DefLine(QPointF p1,QPointF p2)
    {
        this->x1 = p1.x();
        this->x2 = p2.x();
        this->y1 = p1.y();
        this->y2 = p2.y();
    }
    float x1;
    float y1;
    float x2;
    float y2;
};


//卡尺
struct DefCaliper
{
    DefCaliper():x1(0),y1(0),x2(0),y2(0),width(0)
    {}
    DefCaliper(float x1,float y1,float x2,float y2,float width)
    {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        this->width = width;
    }
    DefCaliper(QPointF p1,QPointF p2,float width)
    {
        this->x1 = p1.x();
        this->x2 = p2.x();
        this->y1 = p1.y();
        this->y2 = p2.y();
        this->width = width;
    }
    float x1;
    float y1;
    float x2;
    float y2;
    float width;

};
//锚点
struct DefPoint
{
    DefPoint():x1(0),y1(0)
    {}
    DefPoint(float x1,float y1)
    {
        this->x1 = x1;
        this->y1 = y1;
    }
    DefPoint(QPointF p)
    {
        this->x1 = p.x();
        this->y1 = p.y();
    }
    float x1;
    float y1;
};
//多边形
struct DefPolygon
{

    DefPolygon(){}
    DefPolygon(QVector<QPointF> pList)
    {
        lstPoint = pList;
    }
    QVector<QPointF> lstPoint;
};


struct DefDispItem
{

};











