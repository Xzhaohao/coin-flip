#ifndef __DATA_CONFIG_H
#define __DATA_CONFIG_H

#include <QObject>
#include <QMap>
#include <QVector>

class DataConfig : public QObject {
Q_OBJECT
public:
    explicit DataConfig(QObject *parent = nullptr);

public:

    QMap<int, QVector<QVector<int> > > mData;
};


#endif //__DATA_CONFIG_H
