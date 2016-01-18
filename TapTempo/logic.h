#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>

class QTime;
class QTimer;

class Logic : public QObject
{
    Q_OBJECT
public:
    explicit Logic(QObject *parent = 0);
    ~Logic();
    Q_INVOKABLE void tapClicked();
    Q_INVOKABLE QString bpm();

private:
    void calculateBPM(qint64 passed);

    bool m_started;
    int m_bpm;
    QTime *m_time;
    QTimer *m_timeout;

signals:
    void newBpm();

private slots:
    void timeout();
};

#endif // LOGIC_H
