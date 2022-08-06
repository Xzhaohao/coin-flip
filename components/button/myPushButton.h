#ifndef MY_PUSHBUTTON_H
#define MY_PUSHBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>
#include <QMouseEvent>

class MyPushButton : public QPushButton {
Q_OBJECT

public:
    explicit MyPushButton(const QString &normalImg, const QString &pressImg = "");

    // 正常显示的图片路径
    QString normalImgPath;
    // 按钮按下后显示的图片路径
    QString pressImgPath;

    // 弹跳特效，1向上弹，-1向下弹
    void zoom(int direction);

    void mousePressEvent(QMouseEvent *e) override;

    void mouseReleaseEvent(QMouseEvent *e) override;

private:
    static void drawImage(QPushButton *context, const QString &image);

signals:

};

#endif // MY_PUSHBUTTON_H
