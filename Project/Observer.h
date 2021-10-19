#pragma once
#include "Subject.h"

class observer
{
public:
    virtual ~observer(void);
    virtual void update(void) = 0;

    void set_object(subject* pSubject)
    {
        m_pSubject = pSubject;
    }

protected:
    subject* m_pSubject = nullptr;
};