#include "myPushButton.h"

MyPushButton::MyPushButton(const QString &normalImg, const QString &pressImg) {
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    drawImage(this, normalImg);
}

void MyPushButton::zoom(int direction) {
    // 创建动画特效
    auto *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(200);

    int startY = this->y(), endY = this->y();
    if (direction > 0) {
        endY += 10;
    } else {
        startY += 10;
    }
    animation->setStartValue(QRect(this->x(), startY, this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), endY, this->width(), this->height()));

    // 设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    // 执行动画
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e) {
    if (this->pressImgPath != "") {
        drawImage(this, this->pressImgPath);
    }

    // 让父类执行其他内容
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e) {
    if (this->pressImgPath != "") {
        drawImage(this, this->normalImgPath);
    }
    return QPushButton::mouseReleaseEvent(e);
}

void MyPushButton::drawImage(QPushButton *context, const QString &image) {
    QPixmap pix;
    bool result = pix.load(image);
    if (!result) {
        qDebug() << "图片加载失败";
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
