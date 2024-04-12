#ifndef REWARDBAGDISPLAYER_H
#define REWARDBAGDISPLAYER_H

#include <QLCDNumber>
#include <QRandomGenerator>
#include <QDebug>

class RewardBagDisplayer : public QLCDNumber
{
public:
    RewardBagDisplayer();

signals:
    void rewardDisplayed();

};

#endif // REWARDBAGDISPLAYER_H
