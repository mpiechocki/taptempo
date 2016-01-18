#include "logic.h"

#include <QDebug>
#include <QTime>
#include <QTimer>

#define TIMEOUT 3000 // in miliseconds

Logic::Logic(QObject *parent) :
    QObject(parent),
    m_started(false),
    m_bpm(0),
    m_time(new QTime()),
    m_timeout(new QTimer(this))
{
    connect(m_timeout, SIGNAL(timeout()), this, SLOT(timeout()));
}

Logic::~Logic()
{
    delete m_time;
    m_time = 0;
    delete m_timeout;
    m_timeout = 0;
}

void Logic::tapClicked()
{
    if(!m_started)
    {
        m_time->start();
        m_timeout->start(TIMEOUT);
        m_started = true;
    }
    else
    {
        calculateBPM(m_time->elapsed());
        m_time->restart();
        m_timeout->start(TIMEOUT);
    }
}

QString Logic::bpm()
{
    return QString::number(m_bpm);
}

void Logic::calculateBPM(qint64 passed)
{
    m_bpm = 60000 / passed;
    emit newBpm();
}

void Logic::timeout()
{
    qDebug() << Q_FUNC_INFO << "timeout!";
    m_timeout->stop();
    m_started = false;
}


