#ifndef CREFH
#define CREFH

namespace libmsdoc
{
    namespace internal
    {
    template <class C, class base>
    class CRef:
        public base
    {
    protected:
    friend class C::self;
    C*      m_container;

            CRef(C* container, const base& it);
    bool    IsSet() const;
    void    Link();
    void    UnLink();
    int     id() const;

    public:
    typedef typename base::value_type::first_type   value_type;
    typedef typename base::difference_type          difference_type;
    typedef typename base::iterator_category        iterator_category;
    typedef const value_type*                       pointer;
    typedef pointer                                 const_pointer;
    typedef const value_type&                       reference;
    typedef reference                               const_reference;

    typedef     CRef<C,base> self;
                CRef();
                CRef(const self& origin);
                ~CRef();

    pointer     operator -> () const;
    reference   operator *  () const;

    self        operator ++ (int);
    self        operator -- (int);
    self&       operator ++ ();
    self&       operator -- ();

    self&       operator =  (const self& rvalue);
    };

    template <class C, class base>
    CRef<C,base>::CRef():
        m_container( NULL )
    {
    }

    template <class C, class base>
    CRef<C,base>::CRef(C* container, const base& it):
        base( it ), m_container( container )
    {
    Link();
    }
    
    template <class C, class base>
    CRef<C,base>::CRef(const self& origin):
        base( origin ), m_container( origin.m_container )
    {
    Link();
    }

    template <class C, class base>
    CRef<C,base>::~CRef()
    {
    UnLink();
    }

    template <class C, class base>
    bool CRef<C,base>::IsSet() const
    {
    return NULL != base::_M_node;
    }

    template <class C, class base>
    void CRef<C,base>::Link()
    {
    if ( IsSet() )
        {
        ++(base::operator ->()->second.m_refs);
        }
    }

    template <class C, class base>
    void CRef<C,base>::UnLink()
    {
    if ( IsSet() )
        {
        int refs = --(base::operator ->()->second.m_refs);
        if ( 0 == refs )
            {
            m_container->erase( *this );
            }
        }
    }

    template <class C, class base>
    int CRef<C,base>::id() const
    {
    return base::operator -> () ->second.m_id;
    }

    template <class C, class base>
    typename CRef<C,base>::pointer CRef<C,base>::operator -> () const
    {
    return &base::operator -> ()->first;
    }

    template <class C, class base>
    typename CRef<C,base>::reference CRef<C,base>::operator * () const
    {
    return base::operator -> ()->first;
    }

    template <class C, class base>
    CRef<C,base> CRef<C,base>::operator ++ (int)
    {
    self result( *this );
    UnLink();
    base::operator ++ ();
    Link();
    return result;
    }

    template <class C, class base>
    CRef<C,base> CRef<C,base>::operator -- (int)
    {
    self result( *this );
    UnLink();
    base::operator -- ();
    Link();
    return result;
    }

    template <class C, class base>
    CRef<C,base>& CRef<C,base>::operator ++ ()
    {
    base next = *this;
    ++next;
    UnLink();
    base::operator = ( next );
    Link();
    return *this;
    }

    template <class C, class base>
    CRef<C,base>& CRef<C,base>::operator -- ()
    {
    base previous = *this;
    --previous;
    UnLink();
    base::operator = ( previous );
    Link();
    return *this;
    }

    template <class C, class base>
    CRef<C,base>& CRef<C,base>::operator =  (const CRef<C,base>& rvalue)
    {
    rvalue.Link();
    UnLink();
    base::operator = ( rvalue );
    m_container = rvalue.m_container;
    return *this;
    }

    }
}

#endif

