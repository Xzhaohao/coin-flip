#include "MyCoin.h"

MyCoin::MyCoin(const QString &btnImg) {
    drawImage(this, btnImg);

    // 初始化定时器
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    connect(timer1, &QTimer::timeout, [=]() {
        QString str = QString(":/assets/Coin000%1.png").arg(this->min++);
        drawImage(this, str);

        if (this->min > this->max) {
            this->min = 1;
            isAnimation = false;
            timer1->stop();
        }
    });

    connect(timer2, &QTimer::timeout, [=]() {
        QString str = QString(":/assets/Coin000%1.png").arg(this->max--);
        drawImage(this, str);

        if (this->max < this->min) {
            this->max = 8;
            isAnimation = false;
            timer2->stop();
        }
    });
}

void MyCoin::drawImage(QPushButton *context, const QString &image) {
    QPixmap pix;
    bool result = pix.load(image);
    if (!result) {
        QString msg = QString("图片 %i 加载失败").arg(image);
        qDebug() << msg;
        return;
    }

    // 设置图片固定大小
    context->setFixedSize(pix.width(), pix.height());
    // 设置不规则图片样式
    context->setStyleSheet("QPushButton{ border: 0px; }");
    // 设置图标
    context->setIcon(pix);
    // 设置图标大小
    context->setIconSize(QSize(pix.width(), pix.height()));
}

void MyCoin::changeFlag() {
    if (this->flag) {
        timer1->start(30);
        isAnimation = true;
        this->flag = false;
    } else {
        timer2->start(30);
        isAnimation = true;
        this->flag = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *e) {
    if (this->isAnimation || this->isWin) {
        return;
    } else {
        QPushButton::mousePressEvent(e);
    }
}
