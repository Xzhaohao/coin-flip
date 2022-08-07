#ifndef __MY_COIN_H
#define __MY_COIN_H

#include <QPushButton>
#include <QPixmap>
#include <QDebug>
#include <QTimer>

class MyCoin : public QPushButton {
Q_OBJECT

public:

    explicit MyCoin(const QString &btnImg);

    void changeFlag();

    void mousePressEvent(QMouseEvent *e) override;

public:
    QTimer *timer1{};  // 正面翻反面定时器
    QTimer *timer2{};  // 反面翻正面定时器

    int min = 1;
    int max = 8;

    int posX{};
    int posY{};
    // 正反坐标
    bool flag{};

    // 执行动画的标志
    bool isAnimation = false;
    bool isWin = false;

private:
    static void drawImage(QPushButton *context, const QString &image);
};

#endif //__MY_COIN_H
