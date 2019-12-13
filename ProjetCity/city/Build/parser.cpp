// A Bison parser, made by GNU Bison 3.3.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hpp"


// Unqualified %code blocks.
#line 29 "parser/parser.yy" // lalr1.cc:435

    #include <iostream>
    #include <string>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex

#line 56 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:435


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 151 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:510

  /// Build a parser object.
   Parser :: Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 5: // num
        value.move< double > (std::move (that.value));
        break;

      case 58: // COORD
      case 59: // NODE
      case 71: // expression
        value.move< int > (std::move (that.value));
        break;

      case 6: // id_maison
      case 7: // id_var
      case 8: // hex_RGB
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 5: // num
        value.copy< double > (YY_MOVE (that.value));
        break;

      case 58: // COORD
      case 59: // NODE
      case 71: // expression
        value.copy< int > (YY_MOVE (that.value));
        break;

      case 6: // id_maison
      case 7: // id_var
      case 8: // hex_RGB
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 5: // num
        value.move< double > (YY_MOVE (s.value));
        break;

      case 58: // COORD
      case 59: // NODE
      case 71: // expression
        value.move< int > (YY_MOVE (s.value));
        break;

      case 6: // id_maison
      case 7: // id_var
      case 8: // hex_RGB
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
   Parser ::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser ::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

   Parser ::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

   Parser ::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
   Parser ::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
   Parser ::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
   Parser ::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_number_type
   Parser ::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 5: // num
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case 58: // COORD
      case 59: // NODE
      case 71: // expression
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 6: // id_maison
      case 7: // id_var
      case 8: // hex_RGB
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 5: // num
        value.move< double > (YY_MOVE (that.value));
        break;

      case 58: // COORD
      case 59: // NODE
      case 71: // expression
        value.move< int > (YY_MOVE (that.value));
        break;

      case 6: // id_maison
      case 7: // id_var
      case 8: // hex_RGB
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 5: // num
        value.move< double > (that.value);
        break;

      case 58: // COORD
      case 59: // NODE
      case 71: // expression
        value.move< int > (that.value);
        break;

      case 6: // id_maison
      case 7: // id_var
      case 8: // hex_RGB
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 5: // num
        yylhs.value.emplace< double > ();
        break;

      case 58: // COORD
      case 59: // NODE
      case 71: // expression
        yylhs.value.emplace< int > ();
        break;

      case 6: // id_maison
      case 7: // id_var
      case 8: // hex_RGB
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 3:
#line 89 "parser/parser.yy" // lalr1.cc:919
    {
        YYACCEPT;
    }
#line 727 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 4:
#line 94 "parser/parser.yy" // lalr1.cc:919
    {
        std::cout << "#-> " << yystack_[0].value.as < int > () << std::endl;
    }
#line 735 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 5:
#line 97 "parser/parser.yy" // lalr1.cc:919
    {
		//Last rule    	
    }
#line 743 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 6:
#line 101 "parser/parser.yy" // lalr1.cc:919
    {
		//Rayon=$2
	}
#line 751 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 7:
#line 104 "parser/parser.yy" // lalr1.cc:919
    {
		//Rayon=5
	}
#line 759 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 15:
#line 121 "parser/parser.yy" // lalr1.cc:919
    {
		//return coord
	}
#line 767 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 16:
#line 127 "parser/parser.yy" // lalr1.cc:919
    {}
#line 773 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 17:
#line 128 "parser/parser.yy" // lalr1.cc:919
    {}
#line 779 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 18:
#line 129 "parser/parser.yy" // lalr1.cc:919
    {
		//These Return a graph node
	}
#line 787 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 19:
#line 134 "parser/parser.yy" // lalr1.cc:919
    {
		//Makes House at random xyz
	}
#line 795 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 20:
#line 137 "parser/parser.yy" // lalr1.cc:919
    {
		//Makes House at xyz
	}
#line 803 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 21:
#line 140 "parser/parser.yy" // lalr1.cc:919
    {}
#line 809 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 22:
#line 143 "parser/parser.yy" // lalr1.cc:919
    {
		//Unamed House
	}
#line 817 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 23:
#line 146 "parser/parser.yy" // lalr1.cc:919
    {
		//House name = id_maison
	}
#line 825 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 24:
#line 151 "parser/parser.yy" // lalr1.cc:919
    {}
#line 831 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 25:
#line 152 "parser/parser.yy" // lalr1.cc:919
    {}
#line 837 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 26:
#line 153 "parser/parser.yy" // lalr1.cc:919
    {}
#line 843 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 27:
#line 154 "parser/parser.yy" // lalr1.cc:919
    {}
#line 849 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 28:
#line 155 "parser/parser.yy" // lalr1.cc:919
    {}
#line 855 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 30:
#line 156 "parser/parser.yy" // lalr1.cc:919
    {}
#line 861 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 31:
#line 157 "parser/parser.yy" // lalr1.cc:919
    {}
#line 867 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 32:
#line 158 "parser/parser.yy" // lalr1.cc:919
    {}
#line 873 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 33:
#line 161 "parser/parser.yy" // lalr1.cc:919
    {}
#line 879 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 34:
#line 164 "parser/parser.yy" // lalr1.cc:919
    {}
#line 885 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 35:
#line 165 "parser/parser.yy" // lalr1.cc:919
    {}
#line 891 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 36:
#line 169 "parser/parser.yy" // lalr1.cc:919
    {}
#line 897 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 37:
#line 172 "parser/parser.yy" // lalr1.cc:919
    {}
#line 903 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 38:
#line 173 "parser/parser.yy" // lalr1.cc:919
    {}
#line 909 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 40:
#line 176 "parser/parser.yy" // lalr1.cc:919
    {}
#line 915 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 41:
#line 177 "parser/parser.yy" // lalr1.cc:919
    {}
#line 921 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 42:
#line 180 "parser/parser.yy" // lalr1.cc:919
    {}
#line 927 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 43:
#line 181 "parser/parser.yy" // lalr1.cc:919
    {}
#line 933 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 44:
#line 182 "parser/parser.yy" // lalr1.cc:919
    {}
#line 939 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 45:
#line 184 "parser/parser.yy" // lalr1.cc:919
    {}
#line 945 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 47:
#line 190 "parser/parser.yy" // lalr1.cc:919
    {
        yylhs.value.as < int > () = yystack_[0].value.as < double > ();
    }
#line 953 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 48:
#line 193 "parser/parser.yy" // lalr1.cc:919
    {

    }
#line 961 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 49:
#line 196 "parser/parser.yy" // lalr1.cc:919
    {
        yylhs.value.as < int > () = yystack_[1].value.as < int > ();
    }
#line 969 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 50:
#line 199 "parser/parser.yy" // lalr1.cc:919
    {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () + yystack_[0].value.as < int > ();
    }
#line 977 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 51:
#line 202 "parser/parser.yy" // lalr1.cc:919
    {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () - yystack_[0].value.as < int > ();
    }
#line 985 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 52:
#line 205 "parser/parser.yy" // lalr1.cc:919
    {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () * yystack_[0].value.as < int > ();
    }
#line 993 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 53:
#line 208 "parser/parser.yy" // lalr1.cc:919
    {
        yylhs.value.as < int > () = yystack_[2].value.as < int > () / yystack_[0].value.as < int > ();
    }
#line 1001 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;

  case 54:
#line 211 "parser/parser.yy" // lalr1.cc:919
    {
        yylhs.value.as < int > () = - yystack_[0].value.as < int > ();
    }
#line 1009 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
    break;


#line 1013 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:919
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char  Parser ::yypact_ninf_ = -50;

  const signed char  Parser ::yytable_ninf_ = -29;

  const signed char
   Parser ::yypact_[] =
  {
      23,     4,   -50,   -50,   -35,    -3,    -3,    31,    33,   113,
     -50,    -3,    -4,   -50,    19,   -50,    23,    -3,    -3,    -3,
      -3,    88,    76,   -50,   -50,    -7,    -7,   -50,   -50,   -50,
     -10,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -3,    20,    -3,     6,    48,   -50,     8,
     -50,   -50,   -50,   -50,    -3,   -50,    14,    -3,   -50,    56,
     -50,    57,   -13,    49,   -50,    58,   -50,   -50,    -3,     0,
     -50,   101,    -3,    36,   -50,    76,   -50,   113,    -3,    74,
      64,    -1,   -50,    63,   -50,    44,   -50,     8,   113,   -50,
     -50,   -50,    76,   107,    39,   -50,    70,    -3,    -1,   -50,
     -50,   -50,   -50,    41,    76,    76,   -50,    84,   -50,    62,
      46,    60,    -3,    59,   -50,   -50,   -50,    97,    76,   -50,
      72,   -50
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,     0,    47,    48,     7,     0,     0,     0,     0,     4,
       3,     0,     0,    54,     0,     1,     0,     0,     0,     0,
       0,     0,     9,    49,     2,    51,    50,    52,    53,     6,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    19,
      11,    12,    13,    14,     0,    16,     0,     0,    18,    27,
      23,     0,     0,     0,    31,     0,    30,    32,     0,     0,
      38,     0,     0,     0,     5,     9,    20,    36,     0,     0,
       0,     0,    34,     0,    24,     0,    25,     0,    39,    40,
      41,    37,     9,     0,     0,     8,     0,     0,     0,    21,
      35,    33,    26,     0,     9,     9,    17,     0,    29,    46,
       0,     0,     0,     0,    42,    43,    44,     0,     9,    15,
       0,    45
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -50,    68,   -50,   -50,   -49,   -50,   -40,   -17,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,    -5
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
      -1,     7,     8,    12,    46,    47,    58,    59,    48,    49,
      50,    80,    86,    84,    51,    52,    91,    53,   114,     9
  };

  const signed char
   Parser ::yytable_[] =
  {
      13,    14,     2,    82,     3,    55,    21,    10,    89,    76,
      11,    56,    25,    26,    27,    28,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    95,     1,     2,    90,
       3,    15,     4,    19,    20,     5,    16,    83,    71,    22,
      73,    54,     6,   103,    57,    57,    60,   102,    72,    77,
      74,    75,    79,    57,    85,   110,   111,    17,    18,    19,
      20,     5,    78,    88,    99,    23,    94,    93,     6,   120,
     -28,    81,    87,    96,    17,    18,    19,    20,    98,   100,
     101,   108,   105,    30,    24,   109,    31,    32,   113,    33,
     115,    34,   107,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   118,    44,   116,    45,     0,   117,    17,    18,
      19,    20,    17,    18,    19,    20,   121,     0,     0,   106,
       0,    97,    17,    18,    19,    20,    17,    18,    19,    20,
       0,   112,     0,     0,    29,    17,    18,    19,    20,    17,
      18,    19,    20,   119,    92,    17,    18,    19,    20,     0,
     104,    17,    18,    19,    20
  };

  const signed char
   Parser ::yycheck_[] =
  {
       5,     6,     5,    16,     7,     6,    11,     3,     8,    49,
      45,    12,    17,    18,    19,    20,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    75,     4,     5,    69,
       7,     0,     9,    40,    41,    38,     3,    50,    43,    43,
      45,    51,    45,    92,    45,    45,     6,    87,    28,    54,
      44,     3,    57,    45,     5,   104,   105,    38,    39,    40,
      41,    38,    48,    68,    81,    46,    30,    72,    45,   118,
      14,    14,    14,    78,    38,    39,    40,    41,    14,    16,
      36,    98,    43,     7,    16,    44,    10,    11,    26,    13,
      44,    15,    97,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    43,    27,    44,    29,    -1,   112,    38,    39,
      40,    41,    38,    39,    40,    41,    44,    -1,    -1,    49,
      -1,    47,    38,    39,    40,    41,    38,    39,    40,    41,
      -1,    47,    -1,    -1,    46,    38,    39,    40,    41,    38,
      39,    40,    41,    46,    43,    38,    39,    40,    41,    -1,
      43,    38,    39,    40,    41
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     4,     5,     7,     9,    38,    45,    53,    54,    71,
       3,    45,    55,    71,    71,     0,     3,    38,    39,    40,
      41,    71,    43,    46,    53,    71,    71,    71,    71,    46,
       7,    10,    11,    13,    15,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    27,    29,    56,    57,    60,    61,
      62,    66,    67,    69,    51,     6,    12,    45,    58,    59,
       6,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    71,    28,    71,    44,     3,    58,    71,    48,    71,
      63,    14,    16,    50,    65,     5,    64,    14,    71,     8,
      58,    68,    43,    71,    30,    56,    71,    47,    14,    59,
      16,    36,    58,    56,    43,    43,    49,    71,    59,    44,
      56,    56,    47,    26,    70,    44,    44,    71,    43,    46,
      56,    44
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    57,    57,    57,    58,    59,    59,    59,    60,
      60,    60,    61,    61,    62,    62,    62,    62,    63,    62,
      62,    62,    62,    64,    65,    65,    66,    67,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    71,    71,    71,
      71,    71,    71,    71,    71
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     3,     2,     1,     5,     3,     0,     3,     0,
       1,     1,     1,     1,     1,     7,     1,     4,     1,     1,
       2,     4,     1,     2,     3,     3,     4,     2,     0,     5,
       2,     2,     2,     2,     1,     2,     3,     3,     2,     3,
       1,     1,     6,     6,     6,     4,     0,     1,     1,     3,
       3,     3,     3,     3,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "$end", "error", "$undefined", "NL", "END", "num", "id_maison",
  "id_var", "hex_RGB", "Construire", "Detruire", "Maison", "maison",
  "Route", "arrow", "Tourner", "horaire", "Orienter", "Orientation",
  "Deplacer", "Position", "Voisinage", "Voisin", "Coloriser", "Couleur",
  "Si", "Sinon", "Tant", "que", "Repeter", "fois", "Pour", "eq", "ne",
  "inf", "sup", "degree", "f_void", "'-'", "'+'", "'*'", "'/'", "NEG",
  "'{'", "'}'", "'('", "')'", "','", "'['", "']'", "'!'", "'='", "$accept",
  "programme", "function", "RAYON", "STATEMENTS", "STATEMENT", "COORD",
  "NODE", "BASE", "HOUSE", "MANAGE", "$@1", "DEGREE", "HORAIRE", "VAR",
  "KEVIN", "COLOR", "CONDLOOP", "SINON", "expression", YY_NULLPTR
  };


  const unsigned char
   Parser ::yyrline_[] =
  {
       0,    88,    88,    89,    94,    97,   101,   104,   109,   110,
     113,   114,   115,   116,   117,   121,   127,   128,   129,   134,
     137,   140,   143,   146,   151,   152,   153,   154,   155,   155,
     156,   157,   158,   161,   164,   165,   169,   172,   173,   174,
     176,   177,   180,   181,   182,   184,   185,   190,   193,   196,
     199,   202,   205,   208,   211
  };

  // Print the state stack on the debug stream.
  void
   Parser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   Parser ::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

   Parser ::token_number_type
   Parser ::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,     2,     2,     2,     2,
      45,    46,    40,    39,    47,    38,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    42
    };
    const unsigned user_token_number_max_ = 293;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1442 "/home/melon/University/S5/TLC/ProjetCity/city/Build/parser.cpp" // lalr1.cc:1242
#line 215 "parser/parser.yy" // lalr1.cc:1243


void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
