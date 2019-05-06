#include<iostream>
#include <memory>
#include <sstream>
#include"kmp.hh"
KMP::KMP(string match, string original)
{
    unsigned int length = match.length();
    m_original = original;
    m_match = match;
    std::shared_ptr<int> p(new int[length], std::default_delete<int[]>());
    m_next = p;
}

void KMP::calculate_next()
{
    unsigned int length = m_match.length();
    unsigned int cursor = 0;
    
    int *next = m_next.get();
    next[0] = -1;
    int position = -1;
    while (cursor < length - 1)
    {
        if ((position == -1)
            || (m_match[cursor] == m_match[position]))
            {
                ++cursor;
                ++position;
                next[cursor] = position;
            }
        else
            position = next[position];
    }
}

int KMP::algorithm()
{
    calculate_next();
    int i = 0;
    ostringstream o;
    o.clear();
    int *next = m_next.get();
    int m_length = m_match.length();
    for (i = 0; i < m_length; i++){
        o << std::to_string(next[i]) + " ";
    }
        
    cout << o.str() << endl;
    int o_length = m_original.length();
    int m_cursor = 0;
    int o_cursor = 0;
    
    while ((m_cursor < m_length) && (o_cursor < o_length))
    {
        if ((m_cursor == -1)
            || (m_original[o_cursor] == m_match[m_cursor]))
            {
                ++m_cursor;
                ++o_cursor;
            }
        else
            m_cursor = next[m_cursor];
    }
    if (m_cursor == m_length)
    {
        cout << o_cursor << " " << o_length << " match" << endl;
        return o_length - o_cursor;
    }
    else
    {
        cout << "don't match" << endl;  
        return -1;
    }
}
