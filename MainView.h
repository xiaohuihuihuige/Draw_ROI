#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include "QGView.h"


class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = nullptr);

    QGView* view;
protected:
    bool eventFilter(QObject *obj, QEvent *event);
signals:

};

#endif // MAINVIEW_H
