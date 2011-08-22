#ifndef CREFMAPH
#define CREFMAPH

#include <map>

namespace libmsdoc
{
    namespace internal
    {
    template <class T> class CRefSet;
    }
}

#include "cref.h"

namespace libmsdoc
{
    namespace internal
    {
    struct SRefObj
    {
    public:
    int     m_id;
    int     m_refs;
            SRefObj():
                m_id( 0 ), m_refs( 0 )
            {
            }
    };

    template <class T>
    class CRefSet:
        protected std::map<T,SRefObj>
    {
    protected:
    typedef std::map<T,SRefObj> base;
    typedef typename base::iterator base_iterator;
    typedef typename base::const_iterator base_const_iterator;

    public:
    typedef CRefSet<T> self;
    typedef CRef<self,base_iterator> iterator;
    typedef iterator const_iterator;

    typedef T key_type;
    typedef T value_type;
    typedef typename base::key_compare key_compare;
    typedef typename base::key_compare value_compare;
    typedef typename base::allocator_type allocator_type;
    typedef typename iterator::reference reference;
    typedef typename iterator::const_reference const_reference;
    typedef typename base::size_type size_type;
    typedef typename iterator::difference_type difference_type;
    typedef typename iterator::pointer pointer;
    typedef typename iterator::const_pointer const_pointer;
    typedef typename std::reverse_iterator<iterator> reverse_iterator;
    typedef typename std::reverse_iterator<const_iterator> const_reverse_iterator;

    using base::key_comp;
    using base::value_comp;

    using base::empty;
    using base::size;
    using base::max_size;
    using base::clear;
    using base::count;

    iterator    begin() const;
    iterator    end() const;
    iterator    insert(const T& obj);
    iterator    find(const T& obj) const;
    iterator    lower_bound(const T& obj) const;
    iterator    upper_bound(const T& obj) const;
    std::pair<iterator,iterator> equal_range(const T& obj) const;

    protected:
    friend class CRef<self,base_iterator>;
    void    erase(base_iterator& it);
    };

    template <class T>
    typename CRefSet<T>::iterator CRefSet<T>::begin() const
    {
    const base* pbase = this;
    return iterator( const_cast<self*>(this), const_cast<base*>( pbase )->begin() );
    }

    template <class T>
    typename CRefSet<T>::iterator CRefSet<T>::end() const
    {
    const base* pbase = this;
    return iterator( const_cast<self*>(this), const_cast<base*>( pbase )->end() ); 
    }

    template <class T>
    typename CRefSet<T>::iterator CRefSet<T>::insert(const T& obj)
    {
    std::pair<base_iterator,bool> result = base::insert( std::make_pair( obj, SRefObj() ) );
    base_iterator it = result.first;
    if ( result.second ) //new element
        {   
        base_iterator pos = it;
        base_iterator endpos = base::end();
        while( ++pos != endpos )
            {   
            ++(pos->second.m_id);
            }   
        }   
    return iterator( this, it );
    }

    template <class T>
    void CRefSet<T>::erase(base_iterator& it)
    {
    if ( base::begin() == it )
        {   
        return;
        }
    base_iterator pos = it;
    base_iterator endpos = base::end();
    while ( ++pos != endpos )
        {
        --(pos->second.m_id);
        }
    base::erase( it );
    }

    template <class T>
    typename CRefSet<T>::iterator CRefSet<T>::find(const T& obj) const
    {
    const base* pbase = this;
    return iterator( const_cast<self*>(this), const_cast<base*>(pbase)->find( obj ) );
    }

    template <class T>
    typename CRefSet<T>::iterator CRefSet<T>::lower_bound(const T& obj) const
    {
    const base* pbase = this;
    return iterator( const_cast<self*>(this), const_cast<base*>(pbase)->lower_bound( obj ) );
    }

    template <class T>
    typename CRefSet<T>::iterator CRefSet<T>::upper_bound(const T& obj) const
    {
    const base* pbase = this;
    return iterator( const_cast<self*>(this), const_cast<base*>(pbase)->upper_bound( obj ) );
    }

    template <class T>
    std::pair<typename CRefSet<T>::iterator, typename CRefSet<T>::iterator> CRefSet<T>::equal_range(const T& obj) const
    {
    self* pthis = const_cast<self*>( this );
    const base* pbase = this;
    std::pair<base_iterator,base_iterator> result = const_cast<base*>( pbase )->equal_range( obj );
    return std::make_pair( iterator( pthis, result.first ), iterator( pthis, result.second ) );
    }

    }
}

#endif

