// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   parser6_lex



#include "dhcp6_parser.h"


// Unqualified %code blocks.
#line 34 "dhcp6_parser.yy"

#include <dhcp6/parser_context.h>

#line 52 "dhcp6_parser.cc"


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


// Enable debugging if requested.
#if PARSER6_DEBUG

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
      yy_stack_print_ ();                \
  } while (false)

#else // !PARSER6_DEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !PARSER6_DEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 14 "dhcp6_parser.yy"
namespace isc { namespace dhcp {
#line 145 "dhcp6_parser.cc"

  /// Build a parser object.
  Dhcp6Parser::Dhcp6Parser (isc::dhcp::Parser6Context& ctx_yyarg)
#if PARSER6_DEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      ctx (ctx_yyarg)
  {}

  Dhcp6Parser::~Dhcp6Parser ()
  {}

  Dhcp6Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  Dhcp6Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Dhcp6Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Dhcp6Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Dhcp6Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Dhcp6Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Dhcp6Parser::symbol_kind_type
  Dhcp6Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Dhcp6Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Dhcp6Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.YY_MOVE_OR_COPY< ElementPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.YY_MOVE_OR_COPY< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "constant string"
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

  Dhcp6Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.move< ElementPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.move< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Dhcp6Parser::stack_symbol_type&
  Dhcp6Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.copy< ElementPtr > (that.value);
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.copy< int64_t > (that.value);
        break;

      case symbol_kind::S_STRING: // "constant string"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Dhcp6Parser::stack_symbol_type&
  Dhcp6Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        value.move< ElementPtr > (that.value);
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INTEGER: // "integer"
        value.move< int64_t > (that.value);
        break;

      case symbol_kind::S_STRING: // "constant string"
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
  Dhcp6Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if PARSER6_DEBUG
  template <typename Base>
  void
  Dhcp6Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_STRING: // "constant string"
#line 296 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 404 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_INTEGER: // "integer"
#line 296 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < int64_t > (); }
#line 410 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_FLOAT: // "floating point"
#line 296 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < double > (); }
#line 416 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
#line 296 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < bool > (); }
#line 422 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_value: // value
#line 296 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 428 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_map_value: // map_value
#line 296 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 434 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
#line 296 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 440 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_db_type: // db_type
#line 296 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 446 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_on_fail_mode: // on_fail_mode
#line 296 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 452 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_hr_mode: // hr_mode
#line 296 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 458 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_duid_type: // duid_type
#line 296 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 464 "dhcp6_parser.cc"
        break;

      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
#line 296 "dhcp6_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 470 "dhcp6_parser.cc"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  Dhcp6Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Dhcp6Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Dhcp6Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if PARSER6_DEBUG
  std::ostream&
  Dhcp6Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Dhcp6Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Dhcp6Parser::debug_level_type
  Dhcp6Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Dhcp6Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // PARSER6_DEBUG

  Dhcp6Parser::state_type
  Dhcp6Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Dhcp6Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Dhcp6Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Dhcp6Parser::operator() ()
  {
    return parse ();
  }

  int
  Dhcp6Parser::parse ()
  {
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
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (ctx));
            yyla.move (yylookahead);
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
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
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
      case symbol_kind::S_duid_type: // duid_type
      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
        yylhs.value.emplace< ElementPtr > ();
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_FLOAT: // "floating point"
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INTEGER: // "integer"
        yylhs.value.emplace< int64_t > ();
        break;

      case symbol_kind::S_STRING: // "constant string"
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
  case 2: // $@1: %empty
#line 305 "dhcp6_parser.yy"
                     { ctx.ctx_ = ctx.NO_KEYWORD; }
#line 750 "dhcp6_parser.cc"
    break;

  case 4: // $@2: %empty
#line 306 "dhcp6_parser.yy"
                      { ctx.ctx_ = ctx.CONFIG; }
#line 756 "dhcp6_parser.cc"
    break;

  case 6: // $@3: %empty
#line 307 "dhcp6_parser.yy"
                 { ctx.ctx_ = ctx.DHCP6; }
#line 762 "dhcp6_parser.cc"
    break;

  case 8: // $@4: %empty
#line 308 "dhcp6_parser.yy"
                       { ctx.ctx_ = ctx.INTERFACES_CONFIG; }
#line 768 "dhcp6_parser.cc"
    break;

  case 10: // $@5: %empty
#line 309 "dhcp6_parser.yy"
                   { ctx.ctx_ = ctx.SUBNET6; }
#line 774 "dhcp6_parser.cc"
    break;

  case 12: // $@6: %empty
#line 310 "dhcp6_parser.yy"
                 { ctx.ctx_ = ctx.POOLS; }
#line 780 "dhcp6_parser.cc"
    break;

  case 14: // $@7: %empty
#line 311 "dhcp6_parser.yy"
                   { ctx.ctx_ = ctx.PD_POOLS; }
#line 786 "dhcp6_parser.cc"
    break;

  case 16: // $@8: %empty
#line 312 "dhcp6_parser.yy"
                       { ctx.ctx_ = ctx.RESERVATIONS; }
#line 792 "dhcp6_parser.cc"
    break;

  case 18: // $@9: %empty
#line 313 "dhcp6_parser.yy"
                       { ctx.ctx_ = ctx.DHCP6; }
#line 798 "dhcp6_parser.cc"
    break;

  case 20: // $@10: %empty
#line 314 "dhcp6_parser.yy"
                      { ctx.ctx_ = ctx.OPTION_DEF; }
#line 804 "dhcp6_parser.cc"
    break;

  case 22: // $@11: %empty
#line 315 "dhcp6_parser.yy"
                       { ctx.ctx_ = ctx.OPTION_DATA; }
#line 810 "dhcp6_parser.cc"
    break;

  case 24: // $@12: %empty
#line 316 "dhcp6_parser.yy"
                         { ctx.ctx_ = ctx.HOOKS_LIBRARIES; }
#line 816 "dhcp6_parser.cc"
    break;

  case 26: // $@13: %empty
#line 317 "dhcp6_parser.yy"
                     { ctx.ctx_ = ctx.DHCP_DDNS; }
#line 822 "dhcp6_parser.cc"
    break;

  case 28: // $@14: %empty
#line 318 "dhcp6_parser.yy"
                          { ctx.ctx_ = ctx.CONFIG_CONTROL; }
#line 828 "dhcp6_parser.cc"
    break;

  case 30: // value: "integer"
#line 326 "dhcp6_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location))); }
#line 834 "dhcp6_parser.cc"
    break;

  case 31: // value: "floating point"
#line 327 "dhcp6_parser.yy"
             { yylhs.value.as < ElementPtr > () = ElementPtr(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location))); }
#line 840 "dhcp6_parser.cc"
    break;

  case 32: // value: "boolean"
#line 328 "dhcp6_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location))); }
#line 846 "dhcp6_parser.cc"
    break;

  case 33: // value: "constant string"
#line 329 "dhcp6_parser.yy"
              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location))); }
#line 852 "dhcp6_parser.cc"
    break;

  case 34: // value: "null"
#line 330 "dhcp6_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new NullElement(ctx.loc2pos(yystack_[0].location))); }
#line 858 "dhcp6_parser.cc"
    break;

  case 35: // value: map2
#line 331 "dhcp6_parser.yy"
            { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 864 "dhcp6_parser.cc"
    break;

  case 36: // value: list_generic
#line 332 "dhcp6_parser.yy"
                    { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 870 "dhcp6_parser.cc"
    break;

  case 37: // sub_json: value
#line 335 "dhcp6_parser.yy"
                {
    // Push back the JSON value on the stack
    ctx.stack_.push_back(yystack_[0].value.as < ElementPtr > ());
}
#line 879 "dhcp6_parser.cc"
    break;

  case 38: // $@15: %empty
#line 340 "dhcp6_parser.yy"
                     {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 890 "dhcp6_parser.cc"
    break;

  case 39: // map2: "{" $@15 map_content "}"
#line 345 "dhcp6_parser.yy"
                             {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.
}
#line 900 "dhcp6_parser.cc"
    break;

  case 40: // map_value: map2
#line 351 "dhcp6_parser.yy"
                { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 906 "dhcp6_parser.cc"
    break;

  case 43: // not_empty_map: "constant string" ":" value
#line 358 "dhcp6_parser.yy"
                                  {
                  // map containing a single entry
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 916 "dhcp6_parser.cc"
    break;

  case 44: // not_empty_map: not_empty_map "," "constant string" ":" value
#line 363 "dhcp6_parser.yy"
                                                      {
                  // map consisting of a shorter map followed by
                  // comma and string:value
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 927 "dhcp6_parser.cc"
    break;

  case 45: // not_empty_map: not_empty_map ","
#line 369 "dhcp6_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 935 "dhcp6_parser.cc"
    break;

  case 46: // $@16: %empty
#line 374 "dhcp6_parser.yy"
                              {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 944 "dhcp6_parser.cc"
    break;

  case 47: // list_generic: "[" $@16 list_content "]"
#line 377 "dhcp6_parser.yy"
                               {
    // list parsing complete. Put any sanity checking here
}
#line 952 "dhcp6_parser.cc"
    break;

  case 50: // not_empty_list: value
#line 385 "dhcp6_parser.yy"
                      {
                  // List consisting of a single element.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 961 "dhcp6_parser.cc"
    break;

  case 51: // not_empty_list: not_empty_list "," value
#line 389 "dhcp6_parser.yy"
                                           {
                  // List ending with , and a value.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 970 "dhcp6_parser.cc"
    break;

  case 52: // not_empty_list: not_empty_list ","
#line 393 "dhcp6_parser.yy"
                                     {
                  ctx.warnAboutExtraCommas(yystack_[0].location);
                  }
#line 978 "dhcp6_parser.cc"
    break;

  case 53: // $@17: %empty
#line 399 "dhcp6_parser.yy"
                              {
    // List parsing about to start
}
#line 986 "dhcp6_parser.cc"
    break;

  case 54: // list_strings: "[" $@17 list_strings_content "]"
#line 401 "dhcp6_parser.yy"
                                       {
    // list parsing complete. Put any sanity checking here
    //ctx.stack_.pop_back();
}
#line 995 "dhcp6_parser.cc"
    break;

  case 57: // not_empty_list_strings: "constant string"
#line 410 "dhcp6_parser.yy"
                               {
                          ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
                          ctx.stack_.back()->add(s);
                          }
#line 1004 "dhcp6_parser.cc"
    break;

  case 58: // not_empty_list_strings: not_empty_list_strings "," "constant string"
#line 414 "dhcp6_parser.yy"
                                                            {
                          ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
                          ctx.stack_.back()->add(s);
                          }
#line 1013 "dhcp6_parser.cc"
    break;

  case 59: // not_empty_list_strings: not_empty_list_strings ","
#line 418 "dhcp6_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 1021 "dhcp6_parser.cc"
    break;

  case 60: // unknown_map_entry: "constant string" ":"
#line 428 "dhcp6_parser.yy"
                                {
    const std::string& where = ctx.contextName();
    const std::string& keyword = yystack_[1].value.as < std::string > ();
    error(yystack_[1].location,
          "got unexpected keyword \"" + keyword + "\" in " + where + " map.");
}
#line 1032 "dhcp6_parser.cc"
    break;

  case 61: // $@18: %empty
#line 437 "dhcp6_parser.yy"
                           {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1043 "dhcp6_parser.cc"
    break;

  case 62: // syntax_map: "{" $@18 global_object "}"
#line 442 "dhcp6_parser.yy"
                               {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.

    // Dhcp6 is required
    ctx.require("Dhcp6", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
}
#line 1056 "dhcp6_parser.cc"
    break;

  case 63: // $@19: %empty
#line 452 "dhcp6_parser.yy"
                     {
    // This code is executed when we're about to start parsing
    // the content of the map
    // Prevent against duplicate.
    ctx.unique("Dhcp6", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("Dhcp6", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.DHCP6);
}
#line 1071 "dhcp6_parser.cc"
    break;

  case 64: // global_object: "Dhcp6" $@19 ":" "{" global_params "}"
#line 461 "dhcp6_parser.yy"
                                                    {
    // No global parameter is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1081 "dhcp6_parser.cc"
    break;

  case 66: // global_object_comma: global_object ","
#line 469 "dhcp6_parser.yy"
                                         {
    ctx.warnAboutExtraCommas(yystack_[0].location);
}
#line 1089 "dhcp6_parser.cc"
    break;

  case 67: // $@20: %empty
#line 475 "dhcp6_parser.yy"
                          {
    // Parse the Dhcp6 map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1099 "dhcp6_parser.cc"
    break;

  case 68: // sub_dhcp6: "{" $@20 global_params "}"
#line 479 "dhcp6_parser.yy"
                               {
    // No global parameter is required
    // parsing completed
}
#line 1108 "dhcp6_parser.cc"
    break;

  case 71: // global_params: global_params ","
#line 486 "dhcp6_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 1116 "dhcp6_parser.cc"
    break;

  case 137: // $@21: %empty
#line 560 "dhcp6_parser.yy"
                               {
    ctx.unique("data-directory", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1125 "dhcp6_parser.cc"
    break;

  case 138: // data_directory: "data-directory" $@21 ":" "constant string"
#line 563 "dhcp6_parser.yy"
               {
    ElementPtr datadir(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("data-directory", datadir);
    ctx.leave();
}
#line 1135 "dhcp6_parser.cc"
    break;

  case 139: // preferred_lifetime: "preferred-lifetime" ":" "integer"
#line 569 "dhcp6_parser.yy"
                                                     {
    ctx.unique("preferred-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("preferred-lifetime", prf);
}
#line 1145 "dhcp6_parser.cc"
    break;

  case 140: // min_preferred_lifetime: "min-preferred-lifetime" ":" "integer"
#line 575 "dhcp6_parser.yy"
                                                             {
    ctx.unique("min-preferred-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("min-preferred-lifetime", prf);
}
#line 1155 "dhcp6_parser.cc"
    break;

  case 141: // max_preferred_lifetime: "max-preferred-lifetime" ":" "integer"
#line 581 "dhcp6_parser.yy"
                                                             {
    ctx.unique("max-preferred-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-preferred-lifetime", prf);
}
#line 1165 "dhcp6_parser.cc"
    break;

  case 142: // valid_lifetime: "valid-lifetime" ":" "integer"
#line 587 "dhcp6_parser.yy"
                                             {
    ctx.unique("valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("valid-lifetime", prf);
}
#line 1175 "dhcp6_parser.cc"
    break;

  case 143: // min_valid_lifetime: "min-valid-lifetime" ":" "integer"
#line 593 "dhcp6_parser.yy"
                                                     {
    ctx.unique("min-valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("min-valid-lifetime", prf);
}
#line 1185 "dhcp6_parser.cc"
    break;

  case 144: // max_valid_lifetime: "max-valid-lifetime" ":" "integer"
#line 599 "dhcp6_parser.yy"
                                                     {
    ctx.unique("max-valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-valid-lifetime", prf);
}
#line 1195 "dhcp6_parser.cc"
    break;

  case 145: // renew_timer: "renew-timer" ":" "integer"
#line 605 "dhcp6_parser.yy"
                                       {
    ctx.unique("renew-timer", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("renew-timer", prf);
}
#line 1205 "dhcp6_parser.cc"
    break;

  case 146: // rebind_timer: "rebind-timer" ":" "integer"
#line 611 "dhcp6_parser.yy"
                                         {
    ctx.unique("rebind-timer", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("rebind-timer", prf);
}
#line 1215 "dhcp6_parser.cc"
    break;

  case 147: // calculate_tee_times: "calculate-tee-times" ":" "boolean"
#line 617 "dhcp6_parser.yy"
                                                       {
    ctx.unique("calculate-tee-times", ctx.loc2pos(yystack_[2].location));
    ElementPtr ctt(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("calculate-tee-times", ctt);
}
#line 1225 "dhcp6_parser.cc"
    break;

  case 148: // t1_percent: "t1-percent" ":" "floating point"
#line 623 "dhcp6_parser.yy"
                                   {
    ctx.unique("t1-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr t1(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("t1-percent", t1);
}
#line 1235 "dhcp6_parser.cc"
    break;

  case 149: // t2_percent: "t2-percent" ":" "floating point"
#line 629 "dhcp6_parser.yy"
                                   {
    ctx.unique("t2-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr t2(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("t2-percent", t2);
}
#line 1245 "dhcp6_parser.cc"
    break;

  case 150: // cache_threshold: "cache-threshold" ":" "floating point"
#line 635 "dhcp6_parser.yy"
                                             {
    ctx.unique("cache-threshold", ctx.loc2pos(yystack_[2].location));
    ElementPtr ct(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cache-threshold", ct);
}
#line 1255 "dhcp6_parser.cc"
    break;

  case 151: // cache_max_age: "cache-max-age" ":" "integer"
#line 641 "dhcp6_parser.yy"
                                           {
    ctx.unique("cache-max-age", ctx.loc2pos(yystack_[2].location));
    ElementPtr cm(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cache-max-age", cm);
}
#line 1265 "dhcp6_parser.cc"
    break;

  case 152: // decline_probation_period: "decline-probation-period" ":" "integer"
#line 647 "dhcp6_parser.yy"
                                                                 {
    ctx.unique("decline-probation-period", ctx.loc2pos(yystack_[2].location));
    ElementPtr dpp(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("decline-probation-period", dpp);
}
#line 1275 "dhcp6_parser.cc"
    break;

  case 153: // ddns_send_updates: "ddns-send-updates" ":" "boolean"
#line 653 "dhcp6_parser.yy"
                                                   {
    ctx.unique("ddns-send-updates", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-send-updates", b);
}
#line 1285 "dhcp6_parser.cc"
    break;

  case 154: // ddns_override_no_update: "ddns-override-no-update" ":" "boolean"
#line 659 "dhcp6_parser.yy"
                                                               {
    ctx.unique("ddns-override-no-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-override-no-update", b);
}
#line 1295 "dhcp6_parser.cc"
    break;

  case 155: // ddns_override_client_update: "ddns-override-client-update" ":" "boolean"
#line 665 "dhcp6_parser.yy"
                                                                       {
    ctx.unique("ddns-override-client-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-override-client-update", b);
}
#line 1305 "dhcp6_parser.cc"
    break;

  case 156: // $@22: %empty
#line 671 "dhcp6_parser.yy"
                                                   {
    ctx.unique("ddns-replace-client-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.REPLACE_CLIENT_NAME);
}
#line 1314 "dhcp6_parser.cc"
    break;

  case 157: // ddns_replace_client_name: "ddns-replace-client-name" $@22 ":" ddns_replace_client_name_value
#line 674 "dhcp6_parser.yy"
                                       {
    ctx.stack_.back()->set("ddns-replace-client-name", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1323 "dhcp6_parser.cc"
    break;

  case 158: // ddns_replace_client_name_value: "when-present"
#line 680 "dhcp6_parser.yy"
                 {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("when-present", ctx.loc2pos(yystack_[0].location)));
      }
#line 1331 "dhcp6_parser.cc"
    break;

  case 159: // ddns_replace_client_name_value: "never"
#line 683 "dhcp6_parser.yy"
          {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("never", ctx.loc2pos(yystack_[0].location)));
      }
#line 1339 "dhcp6_parser.cc"
    break;

  case 160: // ddns_replace_client_name_value: "always"
#line 686 "dhcp6_parser.yy"
           {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("always", ctx.loc2pos(yystack_[0].location)));
      }
#line 1347 "dhcp6_parser.cc"
    break;

  case 161: // ddns_replace_client_name_value: "when-not-present"
#line 689 "dhcp6_parser.yy"
                     {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("when-not-present", ctx.loc2pos(yystack_[0].location)));
      }
#line 1355 "dhcp6_parser.cc"
    break;

  case 162: // ddns_replace_client_name_value: "boolean"
#line 692 "dhcp6_parser.yy"
            {
      error(yystack_[0].location, "boolean values for the replace-client-name are "
                "no longer supported");
      }
#line 1364 "dhcp6_parser.cc"
    break;

  case 163: // $@23: %empty
#line 698 "dhcp6_parser.yy"
                                             {
    ctx.unique("ddns-generated-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1373 "dhcp6_parser.cc"
    break;

  case 164: // ddns_generated_prefix: "ddns-generated-prefix" $@23 ":" "constant string"
#line 701 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-generated-prefix", s);
    ctx.leave();
}
#line 1383 "dhcp6_parser.cc"
    break;

  case 165: // $@24: %empty
#line 707 "dhcp6_parser.yy"
                                               {
    ctx.unique("ddns-qualifying-suffix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1392 "dhcp6_parser.cc"
    break;

  case 166: // ddns_qualifying_suffix: "ddns-qualifying-suffix" $@24 ":" "constant string"
#line 710 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-qualifying-suffix", s);
    ctx.leave();
}
#line 1402 "dhcp6_parser.cc"
    break;

  case 167: // ddns_update_on_renew: "ddns-update-on-renew" ":" "boolean"
#line 716 "dhcp6_parser.yy"
                                                         {
    ctx.unique("ddns-update-on-renew", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-update-on-renew", b);
}
#line 1412 "dhcp6_parser.cc"
    break;

  case 168: // ddns_use_conflict_resolution: "ddns-use-conflict-resolution" ":" "boolean"
#line 722 "dhcp6_parser.yy"
                                                                         {
    ctx.unique("ddns-use-conflict-resolution", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-use-conflict-resolution", b);
}
#line 1422 "dhcp6_parser.cc"
    break;

  case 169: // $@25: %empty
#line 728 "dhcp6_parser.yy"
                                     {
    ctx.unique("hostname-char-set", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1431 "dhcp6_parser.cc"
    break;

  case 170: // hostname_char_set: "hostname-char-set" $@25 ":" "constant string"
#line 731 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-set", s);
    ctx.leave();
}
#line 1441 "dhcp6_parser.cc"
    break;

  case 171: // $@26: %empty
#line 737 "dhcp6_parser.yy"
                                                     {
    ctx.unique("hostname-char-replacement", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1450 "dhcp6_parser.cc"
    break;

  case 172: // hostname_char_replacement: "hostname-char-replacement" $@26 ":" "constant string"
#line 740 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-replacement", s);
    ctx.leave();
}
#line 1460 "dhcp6_parser.cc"
    break;

  case 173: // store_extended_info: "store-extended-info" ":" "boolean"
#line 746 "dhcp6_parser.yy"
                                                       {
    ctx.unique("store-extended-info", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("store-extended-info", b);
}
#line 1470 "dhcp6_parser.cc"
    break;

  case 174: // statistic_default_sample_count: "statistic-default-sample-count" ":" "integer"
#line 752 "dhcp6_parser.yy"
                                                                             {
    ctx.unique("statistic-default-sample-count", ctx.loc2pos(yystack_[2].location));
    ElementPtr count(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("statistic-default-sample-count", count);
}
#line 1480 "dhcp6_parser.cc"
    break;

  case 175: // statistic_default_sample_age: "statistic-default-sample-age" ":" "integer"
#line 758 "dhcp6_parser.yy"
                                                                         {
    ctx.unique("statistic-default-sample-age", ctx.loc2pos(yystack_[2].location));
    ElementPtr age(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("statistic-default-sample-age", age);
}
#line 1490 "dhcp6_parser.cc"
    break;

  case 176: // $@27: %empty
#line 764 "dhcp6_parser.yy"
                       {
    ctx.unique("server-tag", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1499 "dhcp6_parser.cc"
    break;

  case 177: // server_tag: "server-tag" $@27 ":" "constant string"
#line 767 "dhcp6_parser.yy"
               {
    ElementPtr stag(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-tag", stag);
    ctx.leave();
}
#line 1509 "dhcp6_parser.cc"
    break;

  case 178: // parked_packet_limit: "parked-packet-limit" ":" "integer"
#line 773 "dhcp6_parser.yy"
                                                       {
    ctx.unique("parked-packet-limit", ctx.loc2pos(yystack_[2].location));
    ElementPtr ppl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("parked-packet-limit", ppl);
}
#line 1519 "dhcp6_parser.cc"
    break;

  case 179: // early_global_reservations_lookup: "early-global-reservations-lookup" ":" "boolean"
#line 779 "dhcp6_parser.yy"
                                                                                 {
    ctx.unique("early-global-reservations-lookup", ctx.loc2pos(yystack_[2].location));
    ElementPtr early(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("early-global-reservations-lookup", early);
}
#line 1529 "dhcp6_parser.cc"
    break;

  case 180: // ip_reservations_unique: "ip-reservations-unique" ":" "boolean"
#line 785 "dhcp6_parser.yy"
                                                             {
    ctx.unique("ip-reservations-unique", ctx.loc2pos(yystack_[2].location));
    ElementPtr unique(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-reservations-unique", unique);
}
#line 1539 "dhcp6_parser.cc"
    break;

  case 181: // reservations_lookup_first: "reservations-lookup-first" ":" "boolean"
#line 791 "dhcp6_parser.yy"
                                                                   {
    ctx.unique("reservations-lookup-first", ctx.loc2pos(yystack_[2].location));
    ElementPtr first(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-lookup-first", first);
}
#line 1549 "dhcp6_parser.cc"
    break;

  case 182: // $@28: %empty
#line 797 "dhcp6_parser.yy"
                                     {
    ctx.unique("interfaces-config", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interfaces-config", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.INTERFACES_CONFIG);
}
#line 1561 "dhcp6_parser.cc"
    break;

  case 183: // interfaces_config: "interfaces-config" $@28 ":" "{" interfaces_config_params "}"
#line 803 "dhcp6_parser.yy"
                                                               {
    // No interfaces config param is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1571 "dhcp6_parser.cc"
    break;

  case 184: // $@29: %empty
#line 809 "dhcp6_parser.yy"
                                {
    // Parse the interfaces-config map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1581 "dhcp6_parser.cc"
    break;

  case 185: // sub_interfaces6: "{" $@29 interfaces_config_params "}"
#line 813 "dhcp6_parser.yy"
                                          {
    // No interfaces config param is required
    // parsing completed
}
#line 1590 "dhcp6_parser.cc"
    break;

  case 188: // interfaces_config_params: interfaces_config_params ","
#line 820 "dhcp6_parser.yy"
                                                         {
                            ctx.warnAboutExtraCommas(yystack_[0].location);
                            }
#line 1598 "dhcp6_parser.cc"
    break;

  case 197: // $@30: %empty
#line 835 "dhcp6_parser.yy"
                            {
    ctx.unique("interfaces", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interfaces", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1610 "dhcp6_parser.cc"
    break;

  case 198: // interfaces_list: "interfaces" $@30 ":" list_strings
#line 841 "dhcp6_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1619 "dhcp6_parser.cc"
    break;

  case 199: // re_detect: "re-detect" ":" "boolean"
#line 846 "dhcp6_parser.yy"
                                   {
    ctx.unique("re-detect", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("re-detect", b);
}
#line 1629 "dhcp6_parser.cc"
    break;

  case 200: // service_sockets_require_all: "service-sockets-require-all" ":" "boolean"
#line 852 "dhcp6_parser.yy"
                                                                       {
    ctx.unique("service-sockets-require-all", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-require-all", b);
}
#line 1639 "dhcp6_parser.cc"
    break;

  case 201: // service_sockets_retry_wait_time: "service-sockets-retry-wait-time" ":" "integer"
#line 858 "dhcp6_parser.yy"
                                                                               {
    ctx.unique("service-sockets-retry-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-retry-wait-time", n);
}
#line 1649 "dhcp6_parser.cc"
    break;

  case 202: // service_sockets_max_retries: "service-sockets-max-retries" ":" "integer"
#line 864 "dhcp6_parser.yy"
                                                                       {
    ctx.unique("service-sockets-max-retries", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-max-retries", n);
}
#line 1659 "dhcp6_parser.cc"
    break;

  case 203: // $@31: %empty
#line 870 "dhcp6_parser.yy"
                               {
    ctx.unique("lease-database", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lease-database", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.LEASE_DATABASE);
}
#line 1671 "dhcp6_parser.cc"
    break;

  case 204: // lease_database: "lease-database" $@31 ":" "{" database_map_params "}"
#line 876 "dhcp6_parser.yy"
                                                          {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1682 "dhcp6_parser.cc"
    break;

  case 205: // $@32: %empty
#line 883 "dhcp6_parser.yy"
                               {
    ctx.unique("hosts-database", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hosts-database", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.HOSTS_DATABASE);
}
#line 1694 "dhcp6_parser.cc"
    break;

  case 206: // hosts_database: "hosts-database" $@32 ":" "{" database_map_params "}"
#line 889 "dhcp6_parser.yy"
                                                          {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1705 "dhcp6_parser.cc"
    break;

  case 207: // $@33: %empty
#line 896 "dhcp6_parser.yy"
                                 {
    ctx.unique("hosts-databases", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hosts-databases", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOSTS_DATABASE);
}
#line 1717 "dhcp6_parser.cc"
    break;

  case 208: // hosts_databases: "hosts-databases" $@33 ":" "[" database_list "]"
#line 902 "dhcp6_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1726 "dhcp6_parser.cc"
    break;

  case 213: // not_empty_database_list: not_empty_database_list ","
#line 913 "dhcp6_parser.yy"
                                                       {
                           ctx.warnAboutExtraCommas(yystack_[0].location);
                           }
#line 1734 "dhcp6_parser.cc"
    break;

  case 214: // $@34: %empty
#line 918 "dhcp6_parser.yy"
                         {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1744 "dhcp6_parser.cc"
    break;

  case 215: // database: "{" $@34 database_map_params "}"
#line 922 "dhcp6_parser.yy"
                                     {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 1754 "dhcp6_parser.cc"
    break;

  case 218: // database_map_params: database_map_params ","
#line 930 "dhcp6_parser.yy"
                                               {
                       ctx.warnAboutExtraCommas(yystack_[0].location);
                       }
#line 1762 "dhcp6_parser.cc"
    break;

  case 238: // $@35: %empty
#line 956 "dhcp6_parser.yy"
                    {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DATABASE_TYPE);
}
#line 1771 "dhcp6_parser.cc"
    break;

  case 239: // database_type: "type" $@35 ":" db_type
#line 959 "dhcp6_parser.yy"
                {
    ctx.stack_.back()->set("type", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1780 "dhcp6_parser.cc"
    break;

  case 240: // db_type: "memfile"
#line 964 "dhcp6_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("memfile", ctx.loc2pos(yystack_[0].location))); }
#line 1786 "dhcp6_parser.cc"
    break;

  case 241: // db_type: "mysql"
#line 965 "dhcp6_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("mysql", ctx.loc2pos(yystack_[0].location))); }
#line 1792 "dhcp6_parser.cc"
    break;

  case 242: // db_type: "postgresql"
#line 966 "dhcp6_parser.yy"
                    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("postgresql", ctx.loc2pos(yystack_[0].location))); }
#line 1798 "dhcp6_parser.cc"
    break;

  case 243: // $@36: %empty
#line 969 "dhcp6_parser.yy"
           {
    ctx.unique("user", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1807 "dhcp6_parser.cc"
    break;

  case 244: // user: "user" $@36 ":" "constant string"
#line 972 "dhcp6_parser.yy"
               {
    ElementPtr user(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("user", user);
    ctx.leave();
}
#line 1817 "dhcp6_parser.cc"
    break;

  case 245: // $@37: %empty
#line 978 "dhcp6_parser.yy"
                   {
    ctx.unique("password", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1826 "dhcp6_parser.cc"
    break;

  case 246: // password: "password" $@37 ":" "constant string"
#line 981 "dhcp6_parser.yy"
               {
    ElementPtr pwd(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("password", pwd);
    ctx.leave();
}
#line 1836 "dhcp6_parser.cc"
    break;

  case 247: // $@38: %empty
#line 987 "dhcp6_parser.yy"
           {
    ctx.unique("host", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1845 "dhcp6_parser.cc"
    break;

  case 248: // host: "host" $@38 ":" "constant string"
#line 990 "dhcp6_parser.yy"
               {
    ElementPtr h(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("host", h);
    ctx.leave();
}
#line 1855 "dhcp6_parser.cc"
    break;

  case 249: // port: "port" ":" "integer"
#line 996 "dhcp6_parser.yy"
                         {
    ctx.unique("port", ctx.loc2pos(yystack_[2].location));
    ElementPtr p(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("port", p);
}
#line 1865 "dhcp6_parser.cc"
    break;

  case 250: // $@39: %empty
#line 1002 "dhcp6_parser.yy"
           {
    ctx.unique("name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1874 "dhcp6_parser.cc"
    break;

  case 251: // name: "name" $@39 ":" "constant string"
#line 1005 "dhcp6_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("name", name);
    ctx.leave();
}
#line 1884 "dhcp6_parser.cc"
    break;

  case 252: // persist: "persist" ":" "boolean"
#line 1011 "dhcp6_parser.yy"
                               {
    ctx.unique("persist", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("persist", n);
}
#line 1894 "dhcp6_parser.cc"
    break;

  case 253: // lfc_interval: "lfc-interval" ":" "integer"
#line 1017 "dhcp6_parser.yy"
                                         {
    ctx.unique("lfc-interval", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lfc-interval", n);
}
#line 1904 "dhcp6_parser.cc"
    break;

  case 254: // readonly: "readonly" ":" "boolean"
#line 1023 "dhcp6_parser.yy"
                                 {
    ctx.unique("readonly", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("readonly", n);
}
#line 1914 "dhcp6_parser.cc"
    break;

  case 255: // connect_timeout: "connect-timeout" ":" "integer"
#line 1029 "dhcp6_parser.yy"
                                               {
    ctx.unique("connect-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("connect-timeout", n);
}
#line 1924 "dhcp6_parser.cc"
    break;

  case 256: // reconnect_wait_time: "reconnect-wait-time" ":" "integer"
#line 1035 "dhcp6_parser.yy"
                                                       {
    ctx.unique("reconnect-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reconnect-wait-time", n);
}
#line 1934 "dhcp6_parser.cc"
    break;

  case 257: // $@40: %empty
#line 1041 "dhcp6_parser.yy"
                 {
    ctx.unique("on-fail", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DATABASE_ON_FAIL);
}
#line 1943 "dhcp6_parser.cc"
    break;

  case 258: // on_fail: "on-fail" $@40 ":" on_fail_mode
#line 1044 "dhcp6_parser.yy"
                     {
    ctx.stack_.back()->set("on-fail", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1952 "dhcp6_parser.cc"
    break;

  case 259: // on_fail_mode: "stop-retry-exit"
#line 1049 "dhcp6_parser.yy"
                              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("stop-retry-exit", ctx.loc2pos(yystack_[0].location))); }
#line 1958 "dhcp6_parser.cc"
    break;

  case 260: // on_fail_mode: "serve-retry-exit"
#line 1050 "dhcp6_parser.yy"
                               { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("serve-retry-exit", ctx.loc2pos(yystack_[0].location))); }
#line 1964 "dhcp6_parser.cc"
    break;

  case 261: // on_fail_mode: "serve-retry-continue"
#line 1051 "dhcp6_parser.yy"
                                   { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("serve-retry-continue", ctx.loc2pos(yystack_[0].location))); }
#line 1970 "dhcp6_parser.cc"
    break;

  case 262: // max_row_errors: "max-row-errors" ":" "integer"
#line 1054 "dhcp6_parser.yy"
                                             {
    ctx.unique("max-row-errors", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-row-errors", n);
}
#line 1980 "dhcp6_parser.cc"
    break;

  case 263: // max_reconnect_tries: "max-reconnect-tries" ":" "integer"
#line 1060 "dhcp6_parser.yy"
                                                       {
    ctx.unique("max-reconnect-tries", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reconnect-tries", n);
}
#line 1990 "dhcp6_parser.cc"
    break;

  case 264: // $@41: %empty
#line 1066 "dhcp6_parser.yy"
                           {
    ctx.unique("trust-anchor", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1999 "dhcp6_parser.cc"
    break;

  case 265: // trust_anchor: "trust-anchor" $@41 ":" "constant string"
#line 1069 "dhcp6_parser.yy"
               {
    ElementPtr ca(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("trust-anchor", ca);
    ctx.leave();
}
#line 2009 "dhcp6_parser.cc"
    break;

  case 266: // $@42: %empty
#line 1075 "dhcp6_parser.yy"
                     {
    ctx.unique("cert-file", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2018 "dhcp6_parser.cc"
    break;

  case 267: // cert_file: "cert-file" $@42 ":" "constant string"
#line 1078 "dhcp6_parser.yy"
               {
    ElementPtr cert(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cert-file", cert);
    ctx.leave();
}
#line 2028 "dhcp6_parser.cc"
    break;

  case 268: // $@43: %empty
#line 1084 "dhcp6_parser.yy"
                   {
    ctx.unique("key-file", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2037 "dhcp6_parser.cc"
    break;

  case 269: // key_file: "key-file" $@43 ":" "constant string"
#line 1087 "dhcp6_parser.yy"
               {
    ElementPtr key(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("key-file", key);
    ctx.leave();
}
#line 2047 "dhcp6_parser.cc"
    break;

  case 270: // $@44: %empty
#line 1093 "dhcp6_parser.yy"
                         {
    ctx.unique("cipher-list", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2056 "dhcp6_parser.cc"
    break;

  case 271: // cipher_list: "cipher-list" $@44 ":" "constant string"
#line 1096 "dhcp6_parser.yy"
               {
    ElementPtr cl(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cipher-list", cl);
    ctx.leave();
}
#line 2066 "dhcp6_parser.cc"
    break;

  case 272: // $@45: %empty
#line 1102 "dhcp6_parser.yy"
                             {
    ctx.unique("sanity-checks", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sanity-checks", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.SANITY_CHECKS);
}
#line 2078 "dhcp6_parser.cc"
    break;

  case 273: // sanity_checks: "sanity-checks" $@45 ":" "{" sanity_checks_params "}"
#line 1108 "dhcp6_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2087 "dhcp6_parser.cc"
    break;

  case 276: // sanity_checks_params: sanity_checks_params ","
#line 1115 "dhcp6_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 2095 "dhcp6_parser.cc"
    break;

  case 279: // $@46: %empty
#line 1124 "dhcp6_parser.yy"
                           {
    ctx.unique("lease-checks", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2104 "dhcp6_parser.cc"
    break;

  case 280: // lease_checks: "lease-checks" $@46 ":" "constant string"
#line 1127 "dhcp6_parser.yy"
               {

    if ( (string(yystack_[0].value.as < std::string > ()) == "none") ||
         (string(yystack_[0].value.as < std::string > ()) == "warn") ||
         (string(yystack_[0].value.as < std::string > ()) == "fix") ||
         (string(yystack_[0].value.as < std::string > ()) == "fix-del") ||
         (string(yystack_[0].value.as < std::string > ()) == "del")) {
        ElementPtr user(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
        ctx.stack_.back()->set("lease-checks", user);
        ctx.leave();
    } else {
        error(yystack_[0].location, "Unsupported 'lease-checks value: " + string(yystack_[0].value.as < std::string > ()) +
              ", supported values are: none, warn, fix, fix-del, del");
    }
}
#line 2124 "dhcp6_parser.cc"
    break;

  case 281: // $@47: %empty
#line 1143 "dhcp6_parser.yy"
                                           {
    ctx.unique("extended-info-checks", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2133 "dhcp6_parser.cc"
    break;

  case 282: // extended_info_checks: "extended-info-checks" $@47 ":" "constant string"
#line 1146 "dhcp6_parser.yy"
               {

    if ( (string(yystack_[0].value.as < std::string > ()) == "none") ||
         (string(yystack_[0].value.as < std::string > ()) == "fix") ||
         (string(yystack_[0].value.as < std::string > ()) == "strict") ||
         (string(yystack_[0].value.as < std::string > ()) == "pedantic")) {
        ElementPtr user(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
        ctx.stack_.back()->set("extended-info-checks", user);
        ctx.leave();
    } else {
        error(yystack_[0].location, "Unsupported 'extended-info-checks value: " + string(yystack_[0].value.as < std::string > ()) +
              ", supported values are: none, fix, strict, pedantic");
    }
}
#line 2152 "dhcp6_parser.cc"
    break;

  case 283: // $@48: %empty
#line 1161 "dhcp6_parser.yy"
                         {
    ctx.unique("mac-sources", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("mac-sources", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.MAC_SOURCES);
}
#line 2164 "dhcp6_parser.cc"
    break;

  case 284: // mac_sources: "mac-sources" $@48 ":" "[" mac_sources_list "]"
#line 1167 "dhcp6_parser.yy"
                                                         {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2173 "dhcp6_parser.cc"
    break;

  case 287: // mac_sources_list: mac_sources_list ","
#line 1174 "dhcp6_parser.yy"
                                         {
                    ctx.warnAboutExtraCommas(yystack_[0].location);
                    }
#line 2181 "dhcp6_parser.cc"
    break;

  case 290: // duid_id: "duid"
#line 1183 "dhcp6_parser.yy"
              {
    ElementPtr duid(new StringElement("duid", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(duid);
}
#line 2190 "dhcp6_parser.cc"
    break;

  case 291: // string_id: "constant string"
#line 1188 "dhcp6_parser.yy"
                  {
    ElementPtr duid(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(duid);
}
#line 2199 "dhcp6_parser.cc"
    break;

  case 292: // $@49: %empty
#line 1193 "dhcp6_parser.yy"
                                                           {
    ctx.unique("host-reservation-identifiers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("host-reservation-identifiers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOST_RESERVATION_IDENTIFIERS);
}
#line 2211 "dhcp6_parser.cc"
    break;

  case 293: // host_reservation_identifiers: "host-reservation-identifiers" $@49 ":" "[" host_reservation_identifiers_list "]"
#line 1199 "dhcp6_parser.yy"
                                                                          {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2220 "dhcp6_parser.cc"
    break;

  case 296: // host_reservation_identifiers_list: host_reservation_identifiers_list ","
#line 1206 "dhcp6_parser.yy"
                                              {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 2228 "dhcp6_parser.cc"
    break;

  case 300: // hw_address_id: "hw-address"
#line 1216 "dhcp6_parser.yy"
                          {
    ElementPtr hwaddr(new StringElement("hw-address", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(hwaddr);
}
#line 2237 "dhcp6_parser.cc"
    break;

  case 301: // flex_id: "flex-id"
#line 1221 "dhcp6_parser.yy"
                 {
    ElementPtr flex_id(new StringElement("flex-id", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(flex_id);
}
#line 2246 "dhcp6_parser.cc"
    break;

  case 302: // $@50: %empty
#line 1228 "dhcp6_parser.yy"
                                               {
    ctx.unique("relay-supplied-options", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("relay-supplied-options", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2258 "dhcp6_parser.cc"
    break;

  case 303: // relay_supplied_options: "relay-supplied-options" $@50 ":" "[" list_content "]"
#line 1234 "dhcp6_parser.yy"
                                                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2267 "dhcp6_parser.cc"
    break;

  case 304: // $@51: %empty
#line 1241 "dhcp6_parser.yy"
                                           {
    ctx.unique("multi-threading", ctx.loc2pos(yystack_[0].location));
    ElementPtr mt(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("multi-threading", mt);
    ctx.stack_.push_back(mt);
    ctx.enter(ctx.DHCP_MULTI_THREADING);
}
#line 2279 "dhcp6_parser.cc"
    break;

  case 305: // dhcp_multi_threading: "multi-threading" $@51 ":" "{" multi_threading_params "}"
#line 1247 "dhcp6_parser.yy"
                                                             {
    // The enable parameter is required.
    ctx.require("enable-multi-threading", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2290 "dhcp6_parser.cc"
    break;

  case 308: // multi_threading_params: multi_threading_params ","
#line 1256 "dhcp6_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 2298 "dhcp6_parser.cc"
    break;

  case 315: // enable_multi_threading: "enable-multi-threading" ":" "boolean"
#line 1269 "dhcp6_parser.yy"
                                                             {
    ctx.unique("enable-multi-threading", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-multi-threading", b);
}
#line 2308 "dhcp6_parser.cc"
    break;

  case 316: // thread_pool_size: "thread-pool-size" ":" "integer"
#line 1275 "dhcp6_parser.yy"
                                                 {
    ctx.unique("thread-pool-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("thread-pool-size", prf);
}
#line 2318 "dhcp6_parser.cc"
    break;

  case 317: // packet_queue_size: "packet-queue-size" ":" "integer"
#line 1281 "dhcp6_parser.yy"
                                                   {
    ctx.unique("packet-queue-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("packet-queue-size", prf);
}
#line 2328 "dhcp6_parser.cc"
    break;

  case 318: // $@52: %empty
#line 1287 "dhcp6_parser.yy"
                                 {
    ctx.unique("hooks-libraries", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hooks-libraries", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOOKS_LIBRARIES);
}
#line 2340 "dhcp6_parser.cc"
    break;

  case 319: // hooks_libraries: "hooks-libraries" $@52 ":" "[" hooks_libraries_list "]"
#line 1293 "dhcp6_parser.yy"
                                                             {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2349 "dhcp6_parser.cc"
    break;

  case 324: // not_empty_hooks_libraries_list: not_empty_hooks_libraries_list ","
#line 1304 "dhcp6_parser.yy"
                                           {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 2357 "dhcp6_parser.cc"
    break;

  case 325: // $@53: %empty
#line 1309 "dhcp6_parser.yy"
                              {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2367 "dhcp6_parser.cc"
    break;

  case 326: // hooks_library: "{" $@53 hooks_params "}"
#line 1313 "dhcp6_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2377 "dhcp6_parser.cc"
    break;

  case 327: // $@54: %empty
#line 1319 "dhcp6_parser.yy"
                                  {
    // Parse the hooks-libraries list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2387 "dhcp6_parser.cc"
    break;

  case 328: // sub_hooks_library: "{" $@54 hooks_params "}"
#line 1323 "dhcp6_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2397 "dhcp6_parser.cc"
    break;

  case 331: // hooks_params: hooks_params ","
#line 1331 "dhcp6_parser.yy"
                                 {
                ctx.warnAboutExtraCommas(yystack_[0].location);
                }
#line 2405 "dhcp6_parser.cc"
    break;

  case 335: // $@55: %empty
#line 1341 "dhcp6_parser.yy"
                 {
    ctx.unique("library", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2414 "dhcp6_parser.cc"
    break;

  case 336: // library: "library" $@55 ":" "constant string"
#line 1344 "dhcp6_parser.yy"
               {
    ElementPtr lib(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("library", lib);
    ctx.leave();
}
#line 2424 "dhcp6_parser.cc"
    break;

  case 337: // $@56: %empty
#line 1350 "dhcp6_parser.yy"
                       {
    ctx.unique("parameters", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2433 "dhcp6_parser.cc"
    break;

  case 338: // parameters: "parameters" $@56 ":" map_value
#line 1353 "dhcp6_parser.yy"
                  {
    ctx.stack_.back()->set("parameters", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2442 "dhcp6_parser.cc"
    break;

  case 339: // $@57: %empty
#line 1359 "dhcp6_parser.yy"
                                                     {
    ctx.unique("expired-leases-processing", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("expired-leases-processing", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.EXPIRED_LEASES_PROCESSING);
}
#line 2454 "dhcp6_parser.cc"
    break;

  case 340: // expired_leases_processing: "expired-leases-processing" $@57 ":" "{" expired_leases_params "}"
#line 1365 "dhcp6_parser.yy"
                                                            {
    // No expired lease parameter is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2464 "dhcp6_parser.cc"
    break;

  case 343: // expired_leases_params: expired_leases_params ","
#line 1373 "dhcp6_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 2472 "dhcp6_parser.cc"
    break;

  case 350: // reclaim_timer_wait_time: "reclaim-timer-wait-time" ":" "integer"
#line 1386 "dhcp6_parser.yy"
                                                               {
    ctx.unique("reclaim-timer-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reclaim-timer-wait-time", value);
}
#line 2482 "dhcp6_parser.cc"
    break;

  case 351: // flush_reclaimed_timer_wait_time: "flush-reclaimed-timer-wait-time" ":" "integer"
#line 1392 "dhcp6_parser.yy"
                                                                               {
    ctx.unique("flush-reclaimed-timer-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush-reclaimed-timer-wait-time", value);
}
#line 2492 "dhcp6_parser.cc"
    break;

  case 352: // hold_reclaimed_time: "hold-reclaimed-time" ":" "integer"
#line 1398 "dhcp6_parser.yy"
                                                       {
    ctx.unique("hold-reclaimed-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hold-reclaimed-time", value);
}
#line 2502 "dhcp6_parser.cc"
    break;

  case 353: // max_reclaim_leases: "max-reclaim-leases" ":" "integer"
#line 1404 "dhcp6_parser.yy"
                                                     {
    ctx.unique("max-reclaim-leases", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reclaim-leases", value);
}
#line 2512 "dhcp6_parser.cc"
    break;

  case 354: // max_reclaim_time: "max-reclaim-time" ":" "integer"
#line 1410 "dhcp6_parser.yy"
                                                 {
    ctx.unique("max-reclaim-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reclaim-time", value);
}
#line 2522 "dhcp6_parser.cc"
    break;

  case 355: // unwarned_reclaim_cycles: "unwarned-reclaim-cycles" ":" "integer"
#line 1416 "dhcp6_parser.yy"
                                                               {
    ctx.unique("unwarned-reclaim-cycles", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("unwarned-reclaim-cycles", value);
}
#line 2532 "dhcp6_parser.cc"
    break;

  case 356: // $@58: %empty
#line 1425 "dhcp6_parser.yy"
                      {
    ctx.unique("subnet6", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("subnet6", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.SUBNET6);
}
#line 2544 "dhcp6_parser.cc"
    break;

  case 357: // subnet6_list: "subnet6" $@58 ":" "[" subnet6_list_content "]"
#line 1431 "dhcp6_parser.yy"
                                                             {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2553 "dhcp6_parser.cc"
    break;

  case 362: // not_empty_subnet6_list: not_empty_subnet6_list ","
#line 1445 "dhcp6_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 2561 "dhcp6_parser.cc"
    break;

  case 363: // $@59: %empty
#line 1454 "dhcp6_parser.yy"
                        {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2571 "dhcp6_parser.cc"
    break;

  case 364: // subnet6: "{" $@59 subnet6_params "}"
#line 1458 "dhcp6_parser.yy"
                                {
    // Once we reached this place, the subnet parsing is now complete.
    // If we want to, we can implement default values here.
    // In particular we can do things like this:
    // if (!ctx.stack_.back()->get("interface")) {
    //     ctx.stack_.back()->set("interface", StringElement("loopback"));
    // }
    //
    // We can also stack up one level (Dhcp6) and copy over whatever
    // global parameters we want to:
    // if (!ctx.stack_.back()->get("renew-timer")) {
    //     ElementPtr renew = ctx_stack_[...].get("renew-timer");
    //     if (renew) {
    //         ctx.stack_.back()->set("renew-timer", renew);
    //     }
    // }

    // The subnet subnet6 parameter is required
    ctx.require("subnet", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2597 "dhcp6_parser.cc"
    break;

  case 365: // $@60: %empty
#line 1480 "dhcp6_parser.yy"
                            {
    // Parse the subnet6 list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2607 "dhcp6_parser.cc"
    break;

  case 366: // sub_subnet6: "{" $@60 subnet6_params "}"
#line 1484 "dhcp6_parser.yy"
                                {
    // The subnet subnet6 parameter is required
    ctx.require("subnet", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2617 "dhcp6_parser.cc"
    break;

  case 369: // subnet6_params: subnet6_params ","
#line 1493 "dhcp6_parser.yy"
                                     {
                  ctx.warnAboutExtraCommas(yystack_[0].location);
                  }
#line 2625 "dhcp6_parser.cc"
    break;

  case 413: // $@61: %empty
#line 1544 "dhcp6_parser.yy"
               {
    ctx.unique("subnet", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2634 "dhcp6_parser.cc"
    break;

  case 414: // subnet: "subnet" $@61 ":" "constant string"
#line 1547 "dhcp6_parser.yy"
               {
    ElementPtr subnet(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("subnet", subnet);
    ctx.leave();
}
#line 2644 "dhcp6_parser.cc"
    break;

  case 415: // $@62: %empty
#line 1553 "dhcp6_parser.yy"
                     {
    ctx.unique("interface", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2653 "dhcp6_parser.cc"
    break;

  case 416: // interface: "interface" $@62 ":" "constant string"
#line 1556 "dhcp6_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interface", iface);
    ctx.leave();
}
#line 2663 "dhcp6_parser.cc"
    break;

  case 417: // $@63: %empty
#line 1562 "dhcp6_parser.yy"
                           {
    ctx.unique("interface-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2672 "dhcp6_parser.cc"
    break;

  case 418: // interface_id: "interface-id" $@63 ":" "constant string"
#line 1565 "dhcp6_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interface-id", iface);
    ctx.leave();
}
#line 2682 "dhcp6_parser.cc"
    break;

  case 419: // $@64: %empty
#line 1571 "dhcp6_parser.yy"
                           {
    ctx.unique("client-class", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2691 "dhcp6_parser.cc"
    break;

  case 420: // client_class: "client-class" $@64 ":" "constant string"
#line 1574 "dhcp6_parser.yy"
               {
    ElementPtr cls(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-class", cls);
    ctx.leave();
}
#line 2701 "dhcp6_parser.cc"
    break;

  case 421: // $@65: %empty
#line 1580 "dhcp6_parser.yy"
                                               {
    ctx.unique("require-client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr c(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("require-client-classes", c);
    ctx.stack_.push_back(c);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2713 "dhcp6_parser.cc"
    break;

  case 422: // require_client_classes: "require-client-classes" $@65 ":" list_strings
#line 1586 "dhcp6_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2722 "dhcp6_parser.cc"
    break;

  case 423: // reservations_global: "reservations-global" ":" "boolean"
#line 1591 "dhcp6_parser.yy"
                                                       {
    ctx.unique("reservations-global", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-global", b);
}
#line 2732 "dhcp6_parser.cc"
    break;

  case 424: // reservations_in_subnet: "reservations-in-subnet" ":" "boolean"
#line 1597 "dhcp6_parser.yy"
                                                             {
    ctx.unique("reservations-in-subnet", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-in-subnet", b);
}
#line 2742 "dhcp6_parser.cc"
    break;

  case 425: // reservations_out_of_pool: "reservations-out-of-pool" ":" "boolean"
#line 1603 "dhcp6_parser.yy"
                                                                 {
    ctx.unique("reservations-out-of-pool", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-out-of-pool", b);
}
#line 2752 "dhcp6_parser.cc"
    break;

  case 426: // $@66: %empty
#line 1609 "dhcp6_parser.yy"
                                   {
    ctx.unique("reservation-mode", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.RESERVATION_MODE);
}
#line 2761 "dhcp6_parser.cc"
    break;

  case 427: // reservation_mode: "reservation-mode" $@66 ":" hr_mode
#line 1612 "dhcp6_parser.yy"
                {
    ctx.stack_.back()->set("reservation-mode", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2770 "dhcp6_parser.cc"
    break;

  case 428: // hr_mode: "disabled"
#line 1617 "dhcp6_parser.yy"
                  { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("disabled", ctx.loc2pos(yystack_[0].location))); }
#line 2776 "dhcp6_parser.cc"
    break;

  case 429: // hr_mode: "out-of-pool"
#line 1618 "dhcp6_parser.yy"
                     { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("out-of-pool", ctx.loc2pos(yystack_[0].location))); }
#line 2782 "dhcp6_parser.cc"
    break;

  case 430: // hr_mode: "global"
#line 1619 "dhcp6_parser.yy"
                { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("global", ctx.loc2pos(yystack_[0].location))); }
#line 2788 "dhcp6_parser.cc"
    break;

  case 431: // hr_mode: "all"
#line 1620 "dhcp6_parser.yy"
             { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("all", ctx.loc2pos(yystack_[0].location))); }
#line 2794 "dhcp6_parser.cc"
    break;

  case 432: // id: "id" ":" "integer"
#line 1623 "dhcp6_parser.yy"
                     {
    ctx.unique("id", ctx.loc2pos(yystack_[2].location));
    ElementPtr id(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("id", id);
}
#line 2804 "dhcp6_parser.cc"
    break;

  case 433: // rapid_commit: "rapid-commit" ":" "boolean"
#line 1629 "dhcp6_parser.yy"
                                         {
    ctx.unique("rapid-commit", ctx.loc2pos(yystack_[2].location));
    ElementPtr rc(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("rapid-commit", rc);
}
#line 2814 "dhcp6_parser.cc"
    break;

  case 434: // $@67: %empty
#line 1637 "dhcp6_parser.yy"
                                 {
    ctx.unique("shared-networks", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("shared-networks", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.SHARED_NETWORK);
}
#line 2826 "dhcp6_parser.cc"
    break;

  case 435: // shared_networks: "shared-networks" $@67 ":" "[" shared_networks_content "]"
#line 1643 "dhcp6_parser.yy"
                                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2835 "dhcp6_parser.cc"
    break;

  case 440: // shared_networks_list: shared_networks_list ","
#line 1656 "dhcp6_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 2843 "dhcp6_parser.cc"
    break;

  case 441: // $@68: %empty
#line 1661 "dhcp6_parser.yy"
                               {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2853 "dhcp6_parser.cc"
    break;

  case 442: // shared_network: "{" $@68 shared_network_params "}"
#line 1665 "dhcp6_parser.yy"
                                       {
    ctx.stack_.pop_back();
}
#line 2861 "dhcp6_parser.cc"
    break;

  case 445: // shared_network_params: shared_network_params ","
#line 1671 "dhcp6_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 2869 "dhcp6_parser.cc"
    break;

  case 486: // $@69: %empty
#line 1722 "dhcp6_parser.yy"
                            {
    ctx.unique("option-def", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("option-def", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OPTION_DEF);
}
#line 2881 "dhcp6_parser.cc"
    break;

  case 487: // option_def_list: "option-def" $@69 ":" "[" option_def_list_content "]"
#line 1728 "dhcp6_parser.yy"
                                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2890 "dhcp6_parser.cc"
    break;

  case 488: // $@70: %empty
#line 1736 "dhcp6_parser.yy"
                                    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2899 "dhcp6_parser.cc"
    break;

  case 489: // sub_option_def_list: "{" $@70 option_def_list "}"
#line 1739 "dhcp6_parser.yy"
                                 {
    // parsing completed
}
#line 2907 "dhcp6_parser.cc"
    break;

  case 494: // not_empty_option_def_list: not_empty_option_def_list ","
#line 1751 "dhcp6_parser.yy"
                                                           {
                             ctx.warnAboutExtraCommas(yystack_[0].location);
                             }
#line 2915 "dhcp6_parser.cc"
    break;

  case 495: // $@71: %empty
#line 1758 "dhcp6_parser.yy"
                                 {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2925 "dhcp6_parser.cc"
    break;

  case 496: // option_def_entry: "{" $@71 option_def_params "}"
#line 1762 "dhcp6_parser.yy"
                                   {
    // The name, code and type option def parameters are required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("code", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2937 "dhcp6_parser.cc"
    break;

  case 497: // $@72: %empty
#line 1773 "dhcp6_parser.yy"
                               {
    // Parse the option-def list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2947 "dhcp6_parser.cc"
    break;

  case 498: // sub_option_def: "{" $@72 option_def_params "}"
#line 1777 "dhcp6_parser.yy"
                                   {
    // The name, code and type option def parameters are required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("code", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2959 "dhcp6_parser.cc"
    break;

  case 503: // not_empty_option_def_params: not_empty_option_def_params ","
#line 1793 "dhcp6_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 2967 "dhcp6_parser.cc"
    break;

  case 515: // code: "code" ":" "integer"
#line 1812 "dhcp6_parser.yy"
                         {
    ctx.unique("code", ctx.loc2pos(yystack_[2].location));
    ElementPtr code(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("code", code);
}
#line 2977 "dhcp6_parser.cc"
    break;

  case 517: // $@73: %empty
#line 1820 "dhcp6_parser.yy"
                      {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2986 "dhcp6_parser.cc"
    break;

  case 518: // option_def_type: "type" $@73 ":" "constant string"
#line 1823 "dhcp6_parser.yy"
               {
    ElementPtr prf(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("type", prf);
    ctx.leave();
}
#line 2996 "dhcp6_parser.cc"
    break;

  case 519: // $@74: %empty
#line 1829 "dhcp6_parser.yy"
                                      {
    ctx.unique("record-types", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3005 "dhcp6_parser.cc"
    break;

  case 520: // option_def_record_types: "record-types" $@74 ":" "constant string"
#line 1832 "dhcp6_parser.yy"
               {
    ElementPtr rtypes(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("record-types", rtypes);
    ctx.leave();
}
#line 3015 "dhcp6_parser.cc"
    break;

  case 521: // $@75: %empty
#line 1838 "dhcp6_parser.yy"
             {
    ctx.unique("space", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3024 "dhcp6_parser.cc"
    break;

  case 522: // space: "space" $@75 ":" "constant string"
#line 1841 "dhcp6_parser.yy"
               {
    ElementPtr space(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("space", space);
    ctx.leave();
}
#line 3034 "dhcp6_parser.cc"
    break;

  case 524: // $@76: %empty
#line 1849 "dhcp6_parser.yy"
                                    {
    ctx.unique("encapsulate", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3043 "dhcp6_parser.cc"
    break;

  case 525: // option_def_encapsulate: "encapsulate" $@76 ":" "constant string"
#line 1852 "dhcp6_parser.yy"
               {
    ElementPtr encap(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("encapsulate", encap);
    ctx.leave();
}
#line 3053 "dhcp6_parser.cc"
    break;

  case 526: // option_def_array: "array" ":" "boolean"
#line 1858 "dhcp6_parser.yy"
                                      {
    ctx.unique("array", ctx.loc2pos(yystack_[2].location));
    ElementPtr array(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("array", array);
}
#line 3063 "dhcp6_parser.cc"
    break;

  case 527: // $@77: %empty
#line 1868 "dhcp6_parser.yy"
                              {
    ctx.unique("option-data", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("option-data", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OPTION_DATA);
}
#line 3075 "dhcp6_parser.cc"
    break;

  case 528: // option_data_list: "option-data" $@77 ":" "[" option_data_list_content "]"
#line 1874 "dhcp6_parser.yy"
                                                                 {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3084 "dhcp6_parser.cc"
    break;

  case 533: // not_empty_option_data_list: not_empty_option_data_list ","
#line 1889 "dhcp6_parser.yy"
                                                             {
                              ctx.warnAboutExtraCommas(yystack_[0].location);
                              }
#line 3092 "dhcp6_parser.cc"
    break;

  case 534: // $@78: %empty
#line 1896 "dhcp6_parser.yy"
                                  {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3102 "dhcp6_parser.cc"
    break;

  case 535: // option_data_entry: "{" $@78 option_data_params "}"
#line 1900 "dhcp6_parser.yy"
                                    {
    /// @todo: the code or name parameters are required.
    ctx.stack_.pop_back();
}
#line 3111 "dhcp6_parser.cc"
    break;

  case 536: // $@79: %empty
#line 1908 "dhcp6_parser.yy"
                                {
    // Parse the option-data list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3121 "dhcp6_parser.cc"
    break;

  case 537: // sub_option_data: "{" $@79 option_data_params "}"
#line 1912 "dhcp6_parser.yy"
                                    {
    /// @todo: the code or name parameters are required.
    // parsing completed
}
#line 3130 "dhcp6_parser.cc"
    break;

  case 542: // not_empty_option_data_params: not_empty_option_data_params ","
#line 1928 "dhcp6_parser.yy"
                                         {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3138 "dhcp6_parser.cc"
    break;

  case 554: // $@80: %empty
#line 1949 "dhcp6_parser.yy"
                       {
    ctx.unique("data", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3147 "dhcp6_parser.cc"
    break;

  case 555: // option_data_data: "data" $@80 ":" "constant string"
#line 1952 "dhcp6_parser.yy"
               {
    ElementPtr data(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("data", data);
    ctx.leave();
}
#line 3157 "dhcp6_parser.cc"
    break;

  case 558: // option_data_csv_format: "csv-format" ":" "boolean"
#line 1962 "dhcp6_parser.yy"
                                                 {
    ctx.unique("csv-format", ctx.loc2pos(yystack_[2].location));
    ElementPtr space(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("csv-format", space);
}
#line 3167 "dhcp6_parser.cc"
    break;

  case 559: // option_data_always_send: "always-send" ":" "boolean"
#line 1968 "dhcp6_parser.yy"
                                                   {
    ctx.unique("always-send", ctx.loc2pos(yystack_[2].location));
    ElementPtr persist(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("always-send", persist);
}
#line 3177 "dhcp6_parser.cc"
    break;

  case 560: // option_data_never_send: "never-send" ":" "boolean"
#line 1974 "dhcp6_parser.yy"
                                                 {
    ctx.unique("never-send", ctx.loc2pos(yystack_[2].location));
    ElementPtr persist(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("never-send", persist);
}
#line 3187 "dhcp6_parser.cc"
    break;

  case 561: // $@81: %empty
#line 1983 "dhcp6_parser.yy"
                  {
    ctx.unique("pools", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pools", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.POOLS);
}
#line 3199 "dhcp6_parser.cc"
    break;

  case 562: // pools_list: "pools" $@81 ":" "[" pools_list_content "]"
#line 1989 "dhcp6_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3208 "dhcp6_parser.cc"
    break;

  case 567: // not_empty_pools_list: not_empty_pools_list ","
#line 2002 "dhcp6_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 3216 "dhcp6_parser.cc"
    break;

  case 568: // $@82: %empty
#line 2007 "dhcp6_parser.yy"
                                {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3226 "dhcp6_parser.cc"
    break;

  case 569: // pool_list_entry: "{" $@82 pool_params "}"
#line 2011 "dhcp6_parser.yy"
                             {
    // The pool parameter is required.
    ctx.require("pool", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3236 "dhcp6_parser.cc"
    break;

  case 570: // $@83: %empty
#line 2017 "dhcp6_parser.yy"
                          {
    // Parse the pool list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3246 "dhcp6_parser.cc"
    break;

  case 571: // sub_pool6: "{" $@83 pool_params "}"
#line 2021 "dhcp6_parser.yy"
                             {
    // The pool parameter is required.
    ctx.require("pool", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 3256 "dhcp6_parser.cc"
    break;

  case 574: // pool_params: pool_params ","
#line 2029 "dhcp6_parser.yy"
                               {
               ctx.warnAboutExtraCommas(yystack_[0].location);
               }
#line 3264 "dhcp6_parser.cc"
    break;

  case 582: // $@84: %empty
#line 2043 "dhcp6_parser.yy"
                 {
    ctx.unique("pool", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3273 "dhcp6_parser.cc"
    break;

  case 583: // pool_entry: "pool" $@84 ":" "constant string"
#line 2046 "dhcp6_parser.yy"
               {
    ElementPtr pool(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pool", pool);
    ctx.leave();
}
#line 3283 "dhcp6_parser.cc"
    break;

  case 584: // $@85: %empty
#line 2052 "dhcp6_parser.yy"
                           {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3291 "dhcp6_parser.cc"
    break;

  case 585: // user_context: "user-context" $@85 ":" map_value
#line 2054 "dhcp6_parser.yy"
                  {
    ElementPtr parent = ctx.stack_.back();
    ElementPtr user_context = yystack_[0].value.as < ElementPtr > ();
    ConstElementPtr old = parent->get("user-context");

    // Handle already existing user context
    if (old) {
        // Check if it was a comment or a duplicate
        if ((old->size() != 1) || !old->contains("comment")) {
            std::stringstream msg;
            msg << "duplicate user-context entries (previous at "
                << old->getPosition().str() << ")";
            error(yystack_[3].location, msg.str());
        }
        // Merge the comment
        user_context->set("comment", old->get("comment"));
    }

    // Set the user context
    parent->set("user-context", user_context);
    ctx.leave();
}
#line 3318 "dhcp6_parser.cc"
    break;

  case 586: // $@86: %empty
#line 2077 "dhcp6_parser.yy"
                 {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3326 "dhcp6_parser.cc"
    break;

  case 587: // comment: "comment" $@86 ":" "constant string"
#line 2079 "dhcp6_parser.yy"
               {
    ElementPtr parent = ctx.stack_.back();
    ElementPtr user_context(new MapElement(ctx.loc2pos(yystack_[3].location)));
    ElementPtr comment(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    user_context->set("comment", comment);

    // Handle already existing user context
    ConstElementPtr old = parent->get("user-context");
    if (old) {
        // Check for duplicate comment
        if (old->contains("comment")) {
            std::stringstream msg;
            msg << "duplicate user-context/comment entries (previous at "
                << old->getPosition().str() << ")";
            error(yystack_[3].location, msg.str());
        }
        // Merge the user context in the comment
        merge(user_context, old);
    }

    // Set the user context
    parent->set("user-context", user_context);
    ctx.leave();
}
#line 3355 "dhcp6_parser.cc"
    break;

  case 588: // $@87: %empty
#line 2107 "dhcp6_parser.yy"
                        {
    ctx.unique("pd-pools", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pd-pools", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.PD_POOLS);
}
#line 3367 "dhcp6_parser.cc"
    break;

  case 589: // pd_pools_list: "pd-pools" $@87 ":" "[" pd_pools_list_content "]"
#line 2113 "dhcp6_parser.yy"
                                                              {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3376 "dhcp6_parser.cc"
    break;

  case 594: // not_empty_pd_pools_list: not_empty_pd_pools_list ","
#line 2126 "dhcp6_parser.yy"
                                                       {
                           ctx.warnAboutExtraCommas(yystack_[0].location);
                           }
#line 3384 "dhcp6_parser.cc"
    break;

  case 595: // $@88: %empty
#line 2131 "dhcp6_parser.yy"
                              {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3394 "dhcp6_parser.cc"
    break;

  case 596: // pd_pool_entry: "{" $@88 pd_pool_params "}"
#line 2135 "dhcp6_parser.yy"
                                {
    // The prefix, prefix len and delegated len parameters are required.
    ctx.require("prefix", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("prefix-len", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("delegated-len", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3406 "dhcp6_parser.cc"
    break;

  case 597: // $@89: %empty
#line 2143 "dhcp6_parser.yy"
                            {
    // Parse the pd-pool list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3416 "dhcp6_parser.cc"
    break;

  case 598: // sub_pd_pool: "{" $@89 pd_pool_params "}"
#line 2147 "dhcp6_parser.yy"
                                {
    // The prefix, prefix len and delegated len parameters are required.
    ctx.require("prefix", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("prefix-len", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("delegated-len", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 3428 "dhcp6_parser.cc"
    break;

  case 601: // pd_pool_params: pd_pool_params ","
#line 2157 "dhcp6_parser.yy"
                                     {
                  ctx.warnAboutExtraCommas(yystack_[0].location);
                  }
#line 3436 "dhcp6_parser.cc"
    break;

  case 613: // $@90: %empty
#line 2175 "dhcp6_parser.yy"
                  {
    ctx.unique("prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3445 "dhcp6_parser.cc"
    break;

  case 614: // pd_prefix: "prefix" $@90 ":" "constant string"
#line 2178 "dhcp6_parser.yy"
               {
    ElementPtr prf(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("prefix", prf);
    ctx.leave();
}
#line 3455 "dhcp6_parser.cc"
    break;

  case 615: // pd_prefix_len: "prefix-len" ":" "integer"
#line 2184 "dhcp6_parser.yy"
                                        {
    ctx.unique("prefix-len", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("prefix-len", prf);
}
#line 3465 "dhcp6_parser.cc"
    break;

  case 616: // $@91: %empty
#line 2190 "dhcp6_parser.yy"
                                 {
    ctx.unique("excluded-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3474 "dhcp6_parser.cc"
    break;

  case 617: // excluded_prefix: "excluded-prefix" $@91 ":" "constant string"
#line 2193 "dhcp6_parser.yy"
               {
    ElementPtr prf(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("excluded-prefix", prf);
    ctx.leave();
}
#line 3484 "dhcp6_parser.cc"
    break;

  case 618: // excluded_prefix_len: "excluded-prefix-len" ":" "integer"
#line 2199 "dhcp6_parser.yy"
                                                       {
    ctx.unique("excluded-prefix-len", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("excluded-prefix-len", prf);
}
#line 3494 "dhcp6_parser.cc"
    break;

  case 619: // pd_delegated_len: "delegated-len" ":" "integer"
#line 2205 "dhcp6_parser.yy"
                                              {
    ctx.unique("delegated-len", ctx.loc2pos(yystack_[2].location));
    ElementPtr deleg(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("delegated-len", deleg);
}
#line 3504 "dhcp6_parser.cc"
    break;

  case 620: // $@92: %empty
#line 2214 "dhcp6_parser.yy"
                           {
    ctx.unique("reservations", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.RESERVATIONS);
}
#line 3516 "dhcp6_parser.cc"
    break;

  case 621: // reservations: "reservations" $@92 ":" "[" reservations_list "]"
#line 2220 "dhcp6_parser.yy"
                                                          {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3525 "dhcp6_parser.cc"
    break;

  case 626: // not_empty_reservations_list: not_empty_reservations_list ","
#line 2231 "dhcp6_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 3533 "dhcp6_parser.cc"
    break;

  case 627: // $@93: %empty
#line 2236 "dhcp6_parser.yy"
                            {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3543 "dhcp6_parser.cc"
    break;

  case 628: // reservation: "{" $@93 reservation_params "}"
#line 2240 "dhcp6_parser.yy"
                                    {
    /// @todo: an identifier parameter is required.
    ctx.stack_.pop_back();
}
#line 3552 "dhcp6_parser.cc"
    break;

  case 629: // $@94: %empty
#line 2245 "dhcp6_parser.yy"
                                {
    // Parse the reservations list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3562 "dhcp6_parser.cc"
    break;

  case 630: // sub_reservation: "{" $@94 reservation_params "}"
#line 2249 "dhcp6_parser.yy"
                                    {
    /// @todo: an identifier parameter is required.
    // parsing completed
}
#line 3571 "dhcp6_parser.cc"
    break;

  case 635: // not_empty_reservation_params: not_empty_reservation_params ","
#line 2260 "dhcp6_parser.yy"
                                         {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3579 "dhcp6_parser.cc"
    break;

  case 647: // $@95: %empty
#line 2279 "dhcp6_parser.yy"
                           {
    ctx.unique("ip-addresses", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-addresses", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3591 "dhcp6_parser.cc"
    break;

  case 648: // ip_addresses: "ip-addresses" $@95 ":" list_strings
#line 2285 "dhcp6_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3600 "dhcp6_parser.cc"
    break;

  case 649: // $@96: %empty
#line 2290 "dhcp6_parser.yy"
                   {
    ctx.unique("prefixes", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("prefixes", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3612 "dhcp6_parser.cc"
    break;

  case 650: // prefixes: "prefixes" $@96 ":" list_strings
#line 2296 "dhcp6_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3621 "dhcp6_parser.cc"
    break;

  case 651: // $@97: %empty
#line 2301 "dhcp6_parser.yy"
           {
    ctx.unique("duid", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3630 "dhcp6_parser.cc"
    break;

  case 652: // duid: "duid" $@97 ":" "constant string"
#line 2304 "dhcp6_parser.yy"
               {
    ElementPtr d(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("duid", d);
    ctx.leave();
}
#line 3640 "dhcp6_parser.cc"
    break;

  case 653: // $@98: %empty
#line 2310 "dhcp6_parser.yy"
                       {
    ctx.unique("hw-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3649 "dhcp6_parser.cc"
    break;

  case 654: // hw_address: "hw-address" $@98 ":" "constant string"
#line 2313 "dhcp6_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hw-address", hw);
    ctx.leave();
}
#line 3659 "dhcp6_parser.cc"
    break;

  case 655: // $@99: %empty
#line 2319 "dhcp6_parser.yy"
                   {
    ctx.unique("hostname", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3668 "dhcp6_parser.cc"
    break;

  case 656: // hostname: "hostname" $@99 ":" "constant string"
#line 2322 "dhcp6_parser.yy"
               {
    ElementPtr host(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname", host);
    ctx.leave();
}
#line 3678 "dhcp6_parser.cc"
    break;

  case 657: // $@100: %empty
#line 2328 "dhcp6_parser.yy"
                       {
    ctx.unique("flex-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3687 "dhcp6_parser.cc"
    break;

  case 658: // flex_id_value: "flex-id" $@100 ":" "constant string"
#line 2331 "dhcp6_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flex-id", hw);
    ctx.leave();
}
#line 3697 "dhcp6_parser.cc"
    break;

  case 659: // $@101: %empty
#line 2337 "dhcp6_parser.yy"
                                           {
    ctx.unique("client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr c(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-classes", c);
    ctx.stack_.push_back(c);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3709 "dhcp6_parser.cc"
    break;

  case 660: // reservation_client_classes: "client-classes" $@101 ":" list_strings
#line 2343 "dhcp6_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3718 "dhcp6_parser.cc"
    break;

  case 661: // $@102: %empty
#line 2351 "dhcp6_parser.yy"
             {
    ctx.unique("relay", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("relay", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.RELAY);
}
#line 3730 "dhcp6_parser.cc"
    break;

  case 662: // relay: "relay" $@102 ":" "{" relay_map "}"
#line 2357 "dhcp6_parser.yy"
                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3739 "dhcp6_parser.cc"
    break;

  case 665: // $@103: %empty
#line 2366 "dhcp6_parser.yy"
                       {
    ctx.unique("ip-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3748 "dhcp6_parser.cc"
    break;

  case 666: // ip_address: "ip-address" $@103 ":" "constant string"
#line 2369 "dhcp6_parser.yy"
               {
    ElementPtr addr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-address", addr);
    ctx.leave();
}
#line 3758 "dhcp6_parser.cc"
    break;

  case 667: // $@104: %empty
#line 2378 "dhcp6_parser.yy"
                               {
    ctx.unique("client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-classes", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.CLIENT_CLASSES);
}
#line 3770 "dhcp6_parser.cc"
    break;

  case 668: // client_classes: "client-classes" $@104 ":" "[" client_classes_list "]"
#line 2384 "dhcp6_parser.yy"
                                                            {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3779 "dhcp6_parser.cc"
    break;

  case 671: // client_classes_list: client_classes_list ","
#line 2391 "dhcp6_parser.yy"
                                               {
                       ctx.warnAboutExtraCommas(yystack_[0].location);
                       }
#line 3787 "dhcp6_parser.cc"
    break;

  case 672: // $@105: %empty
#line 2396 "dhcp6_parser.yy"
                                   {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3797 "dhcp6_parser.cc"
    break;

  case 673: // client_class_entry: "{" $@105 client_class_params "}"
#line 2400 "dhcp6_parser.yy"
                                     {
    // The name client class parameter is required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3807 "dhcp6_parser.cc"
    break;

  case 678: // not_empty_client_class_params: not_empty_client_class_params ","
#line 2412 "dhcp6_parser.yy"
                                          {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3815 "dhcp6_parser.cc"
    break;

  case 694: // $@106: %empty
#line 2435 "dhcp6_parser.yy"
                        {
    ctx.unique("test", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3824 "dhcp6_parser.cc"
    break;

  case 695: // client_class_test: "test" $@106 ":" "constant string"
#line 2438 "dhcp6_parser.yy"
               {
    ElementPtr test(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("test", test);
    ctx.leave();
}
#line 3834 "dhcp6_parser.cc"
    break;

  case 696: // $@107: %empty
#line 2444 "dhcp6_parser.yy"
                                          {
    ctx.unique("template-test", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3843 "dhcp6_parser.cc"
    break;

  case 697: // client_class_template_test: "template-test" $@107 ":" "constant string"
#line 2447 "dhcp6_parser.yy"
               {
    ElementPtr template_test(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("template-test", template_test);
    ctx.leave();
}
#line 3853 "dhcp6_parser.cc"
    break;

  case 698: // only_if_required: "only-if-required" ":" "boolean"
#line 2453 "dhcp6_parser.yy"
                                                 {
    ctx.unique("only-if-required", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("only-if-required", b);
}
#line 3863 "dhcp6_parser.cc"
    break;

  case 699: // $@108: %empty
#line 2462 "dhcp6_parser.yy"
                     {
    ctx.unique("server-id", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-id", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.SERVER_ID);
}
#line 3875 "dhcp6_parser.cc"
    break;

  case 700: // server_id: "server-id" $@108 ":" "{" server_id_params "}"
#line 2468 "dhcp6_parser.yy"
                                                       {
    // The type parameter is required.
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3886 "dhcp6_parser.cc"
    break;

  case 703: // server_id_params: server_id_params ","
#line 2477 "dhcp6_parser.yy"
                                         {
                    ctx.warnAboutExtraCommas(yystack_[0].location);
                    }
#line 3894 "dhcp6_parser.cc"
    break;

  case 713: // $@109: %empty
#line 2493 "dhcp6_parser.yy"
                     {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DUID_TYPE);
}
#line 3903 "dhcp6_parser.cc"
    break;

  case 714: // server_id_type: "type" $@109 ":" duid_type
#line 2496 "dhcp6_parser.yy"
                  {
    ctx.stack_.back()->set("type", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 3912 "dhcp6_parser.cc"
    break;

  case 715: // duid_type: "LLT"
#line 2501 "dhcp6_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("LLT", ctx.loc2pos(yystack_[0].location))); }
#line 3918 "dhcp6_parser.cc"
    break;

  case 716: // duid_type: "EN"
#line 2502 "dhcp6_parser.yy"
              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("EN", ctx.loc2pos(yystack_[0].location))); }
#line 3924 "dhcp6_parser.cc"
    break;

  case 717: // duid_type: "LL"
#line 2503 "dhcp6_parser.yy"
              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("LL", ctx.loc2pos(yystack_[0].location))); }
#line 3930 "dhcp6_parser.cc"
    break;

  case 718: // htype: "htype" ":" "integer"
#line 2506 "dhcp6_parser.yy"
                           {
    ctx.unique("htype", ctx.loc2pos(yystack_[2].location));
    ElementPtr htype(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("htype", htype);
}
#line 3940 "dhcp6_parser.cc"
    break;

  case 719: // $@110: %empty
#line 2512 "dhcp6_parser.yy"
                       {
    ctx.unique("identifier", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3949 "dhcp6_parser.cc"
    break;

  case 720: // identifier: "identifier" $@110 ":" "constant string"
#line 2515 "dhcp6_parser.yy"
               {
    ElementPtr id(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("identifier", id);
    ctx.leave();
}
#line 3959 "dhcp6_parser.cc"
    break;

  case 721: // time: "time" ":" "integer"
#line 2521 "dhcp6_parser.yy"
                         {
    ctx.unique("time", ctx.loc2pos(yystack_[2].location));
    ElementPtr time(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("time", time);
}
#line 3969 "dhcp6_parser.cc"
    break;

  case 722: // enterprise_id: "enterprise-id" ":" "integer"
#line 2527 "dhcp6_parser.yy"
                                           {
    ctx.unique("enterprise-id", ctx.loc2pos(yystack_[2].location));
    ElementPtr time(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enterprise-id", time);
}
#line 3979 "dhcp6_parser.cc"
    break;

  case 723: // dhcp4o6_port: "dhcp4o6-port" ":" "integer"
#line 2535 "dhcp6_parser.yy"
                                         {
    ctx.unique("dhcp4o6-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr time(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp4o6-port", time);
}
#line 3989 "dhcp6_parser.cc"
    break;

  case 724: // $@111: %empty
#line 2543 "dhcp6_parser.yy"
                               {
    ctx.unique("control-socket", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("control-socket", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.CONTROL_SOCKET);
}
#line 4001 "dhcp6_parser.cc"
    break;

  case 725: // control_socket: "control-socket" $@111 ":" "{" control_socket_params "}"
#line 2549 "dhcp6_parser.yy"
                                                            {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4010 "dhcp6_parser.cc"
    break;

  case 728: // control_socket_params: control_socket_params ","
#line 2556 "dhcp6_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 4018 "dhcp6_parser.cc"
    break;

  case 734: // $@112: %empty
#line 2568 "dhcp6_parser.yy"
                         {
    ctx.unique("socket-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4027 "dhcp6_parser.cc"
    break;

  case 735: // socket_type: "socket-type" $@112 ":" "constant string"
#line 2571 "dhcp6_parser.yy"
               {
    ElementPtr stype(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-type", stype);
    ctx.leave();
}
#line 4037 "dhcp6_parser.cc"
    break;

  case 736: // $@113: %empty
#line 2577 "dhcp6_parser.yy"
                         {
    ctx.unique("socket-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4046 "dhcp6_parser.cc"
    break;

  case 737: // socket_name: "socket-name" $@113 ":" "constant string"
#line 2580 "dhcp6_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-name", name);
    ctx.leave();
}
#line 4056 "dhcp6_parser.cc"
    break;

  case 738: // $@114: %empty
#line 2589 "dhcp6_parser.yy"
                                       {
    ctx.unique("dhcp-queue-control", ctx.loc2pos(yystack_[0].location));
    ElementPtr qc(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp-queue-control", qc);
    ctx.stack_.push_back(qc);
    ctx.enter(ctx.DHCP_QUEUE_CONTROL);
}
#line 4068 "dhcp6_parser.cc"
    break;

  case 739: // dhcp_queue_control: "dhcp-queue-control" $@114 ":" "{" queue_control_params "}"
#line 2595 "dhcp6_parser.yy"
                                                           {
    // The enable queue parameter is required.
    ctx.require("enable-queue", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4079 "dhcp6_parser.cc"
    break;

  case 742: // queue_control_params: queue_control_params ","
#line 2604 "dhcp6_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 4087 "dhcp6_parser.cc"
    break;

  case 749: // enable_queue: "enable-queue" ":" "boolean"
#line 2617 "dhcp6_parser.yy"
                                         {
    ctx.unique("enable-queue", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-queue", b);
}
#line 4097 "dhcp6_parser.cc"
    break;

  case 750: // $@115: %empty
#line 2623 "dhcp6_parser.yy"
                       {
    ctx.unique("queue-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4106 "dhcp6_parser.cc"
    break;

  case 751: // queue_type: "queue-type" $@115 ":" "constant string"
#line 2626 "dhcp6_parser.yy"
               {
    ElementPtr qt(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("queue-type", qt);
    ctx.leave();
}
#line 4116 "dhcp6_parser.cc"
    break;

  case 752: // capacity: "capacity" ":" "integer"
#line 2632 "dhcp6_parser.yy"
                                 {
    ctx.unique("capacity", ctx.loc2pos(yystack_[2].location));
    ElementPtr c(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("capacity", c);
}
#line 4126 "dhcp6_parser.cc"
    break;

  case 753: // $@116: %empty
#line 2638 "dhcp6_parser.yy"
                            {
    ctx.unique(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4135 "dhcp6_parser.cc"
    break;

  case 754: // arbitrary_map_entry: "constant string" $@116 ":" value
#line 2641 "dhcp6_parser.yy"
              {
    ctx.stack_.back()->set(yystack_[3].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4144 "dhcp6_parser.cc"
    break;

  case 755: // $@117: %empty
#line 2648 "dhcp6_parser.yy"
                     {
    ctx.unique("dhcp-ddns", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp-ddns", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.DHCP_DDNS);
}
#line 4156 "dhcp6_parser.cc"
    break;

  case 756: // dhcp_ddns: "dhcp-ddns" $@117 ":" "{" dhcp_ddns_params "}"
#line 2654 "dhcp6_parser.yy"
                                                       {
    // The enable updates DHCP DDNS parameter is required.
    ctx.require("enable-updates", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4167 "dhcp6_parser.cc"
    break;

  case 757: // $@118: %empty
#line 2661 "dhcp6_parser.yy"
                              {
    // Parse the dhcp-ddns map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 4177 "dhcp6_parser.cc"
    break;

  case 758: // sub_dhcp_ddns: "{" $@118 dhcp_ddns_params "}"
#line 2665 "dhcp6_parser.yy"
                                  {
    // The enable updates DHCP DDNS parameter is required.
    ctx.require("enable-updates", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 4187 "dhcp6_parser.cc"
    break;

  case 761: // dhcp_ddns_params: dhcp_ddns_params ","
#line 2673 "dhcp6_parser.yy"
                                         {
                    ctx.warnAboutExtraCommas(yystack_[0].location);
                    }
#line 4195 "dhcp6_parser.cc"
    break;

  case 780: // enable_updates: "enable-updates" ":" "boolean"
#line 2698 "dhcp6_parser.yy"
                                             {
    ctx.unique("enable-updates", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-updates", b);
}
#line 4205 "dhcp6_parser.cc"
    break;

  case 781: // $@119: %empty
#line 2705 "dhcp6_parser.yy"
                                         {
    ctx.unique("qualifying-suffix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4214 "dhcp6_parser.cc"
    break;

  case 782: // dep_qualifying_suffix: "qualifying-suffix" $@119 ":" "constant string"
#line 2708 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("qualifying-suffix", s);
    ctx.leave();
}
#line 4224 "dhcp6_parser.cc"
    break;

  case 783: // $@120: %empty
#line 2714 "dhcp6_parser.yy"
                     {
    ctx.unique("server-ip", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4233 "dhcp6_parser.cc"
    break;

  case 784: // server_ip: "server-ip" $@120 ":" "constant string"
#line 2717 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-ip", s);
    ctx.leave();
}
#line 4243 "dhcp6_parser.cc"
    break;

  case 785: // server_port: "server-port" ":" "integer"
#line 2723 "dhcp6_parser.yy"
                                       {
    ctx.unique("server-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-port", i);
}
#line 4253 "dhcp6_parser.cc"
    break;

  case 786: // $@121: %empty
#line 2729 "dhcp6_parser.yy"
                     {
    ctx.unique("sender-ip", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4262 "dhcp6_parser.cc"
    break;

  case 787: // sender_ip: "sender-ip" $@121 ":" "constant string"
#line 2732 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sender-ip", s);
    ctx.leave();
}
#line 4272 "dhcp6_parser.cc"
    break;

  case 788: // sender_port: "sender-port" ":" "integer"
#line 2738 "dhcp6_parser.yy"
                                       {
    ctx.unique("sender-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sender-port", i);
}
#line 4282 "dhcp6_parser.cc"
    break;

  case 789: // max_queue_size: "max-queue-size" ":" "integer"
#line 2744 "dhcp6_parser.yy"
                                             {
    ctx.unique("max-queue-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-queue-size", i);
}
#line 4292 "dhcp6_parser.cc"
    break;

  case 790: // $@122: %empty
#line 2750 "dhcp6_parser.yy"
                           {
    ctx.unique("ncr-protocol", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_PROTOCOL);
}
#line 4301 "dhcp6_parser.cc"
    break;

  case 791: // ncr_protocol: "ncr-protocol" $@122 ":" ncr_protocol_value
#line 2753 "dhcp6_parser.yy"
                           {
    ctx.stack_.back()->set("ncr-protocol", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4310 "dhcp6_parser.cc"
    break;

  case 792: // ncr_protocol_value: "UDP"
#line 2759 "dhcp6_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("UDP", ctx.loc2pos(yystack_[0].location))); }
#line 4316 "dhcp6_parser.cc"
    break;

  case 793: // ncr_protocol_value: "TCP"
#line 2760 "dhcp6_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("TCP", ctx.loc2pos(yystack_[0].location))); }
#line 4322 "dhcp6_parser.cc"
    break;

  case 794: // $@123: %empty
#line 2763 "dhcp6_parser.yy"
                       {
    ctx.unique("ncr-format", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_FORMAT);
}
#line 4331 "dhcp6_parser.cc"
    break;

  case 795: // ncr_format: "ncr-format" $@123 ":" "JSON"
#line 2766 "dhcp6_parser.yy"
             {
    ElementPtr json(new StringElement("JSON", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ncr-format", json);
    ctx.leave();
}
#line 4341 "dhcp6_parser.cc"
    break;

  case 796: // dep_override_no_update: "override-no-update" ":" "boolean"
#line 2773 "dhcp6_parser.yy"
                                                         {
    ctx.unique("override-no-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("override-no-update", b);
}
#line 4351 "dhcp6_parser.cc"
    break;

  case 797: // dep_override_client_update: "override-client-update" ":" "boolean"
#line 2780 "dhcp6_parser.yy"
                                                                 {
    ctx.unique("override-client-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("override-client-update", b);
}
#line 4361 "dhcp6_parser.cc"
    break;

  case 798: // $@124: %empty
#line 2787 "dhcp6_parser.yy"
                                             {
    ctx.unique("replace-client-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.REPLACE_CLIENT_NAME);
}
#line 4370 "dhcp6_parser.cc"
    break;

  case 799: // dep_replace_client_name: "replace-client-name" $@124 ":" ddns_replace_client_name_value
#line 2790 "dhcp6_parser.yy"
                                       {
    ctx.stack_.back()->set("replace-client-name", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4379 "dhcp6_parser.cc"
    break;

  case 800: // $@125: %empty
#line 2796 "dhcp6_parser.yy"
                                       {
    ctx.unique("generated-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4388 "dhcp6_parser.cc"
    break;

  case 801: // dep_generated_prefix: "generated-prefix" $@125 ":" "constant string"
#line 2799 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("generated-prefix", s);
    ctx.leave();
}
#line 4398 "dhcp6_parser.cc"
    break;

  case 802: // $@126: %empty
#line 2806 "dhcp6_parser.yy"
                                         {
    ctx.unique("hostname-char-set", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4407 "dhcp6_parser.cc"
    break;

  case 803: // dep_hostname_char_set: "hostname-char-set" $@126 ":" "constant string"
#line 2809 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-set", s);
    ctx.leave();
}
#line 4417 "dhcp6_parser.cc"
    break;

  case 804: // $@127: %empty
#line 2816 "dhcp6_parser.yy"
                                                         {
    ctx.unique("hostname-char-replacement", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4426 "dhcp6_parser.cc"
    break;

  case 805: // dep_hostname_char_replacement: "hostname-char-replacement" $@127 ":" "constant string"
#line 2819 "dhcp6_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-replacement", s);
    ctx.leave();
}
#line 4436 "dhcp6_parser.cc"
    break;

  case 806: // $@128: %empty
#line 2828 "dhcp6_parser.yy"
                               {
    ctx.unique("config-control", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-control", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.CONFIG_CONTROL);
}
#line 4448 "dhcp6_parser.cc"
    break;

  case 807: // config_control: "config-control" $@128 ":" "{" config_control_params "}"
#line 2834 "dhcp6_parser.yy"
                                                            {
    // No config control params are required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4458 "dhcp6_parser.cc"
    break;

  case 808: // $@129: %empty
#line 2840 "dhcp6_parser.yy"
                                   {
    // Parse the config-control map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 4468 "dhcp6_parser.cc"
    break;

  case 809: // sub_config_control: "{" $@129 config_control_params "}"
#line 2844 "dhcp6_parser.yy"
                                       {
    // No config_control params are required
    // parsing completed
}
#line 4477 "dhcp6_parser.cc"
    break;

  case 812: // config_control_params: config_control_params ","
#line 2852 "dhcp6_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 4485 "dhcp6_parser.cc"
    break;

  case 815: // $@130: %empty
#line 2862 "dhcp6_parser.yy"
                                   {
    ctx.unique("config-databases", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-databases", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.CONFIG_DATABASE);
}
#line 4497 "dhcp6_parser.cc"
    break;

  case 816: // config_databases: "config-databases" $@130 ":" "[" database_list "]"
#line 2868 "dhcp6_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4506 "dhcp6_parser.cc"
    break;

  case 817: // config_fetch_wait_time: "config-fetch-wait-time" ":" "integer"
#line 2873 "dhcp6_parser.yy"
                                                             {
    ctx.unique("config-fetch-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-fetch-wait-time", value);
}
#line 4516 "dhcp6_parser.cc"
    break;

  case 818: // $@131: %empty
#line 2881 "dhcp6_parser.yy"
                 {
    ctx.unique("loggers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("loggers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.LOGGERS);
}
#line 4528 "dhcp6_parser.cc"
    break;

  case 819: // loggers: "loggers" $@131 ":" "[" loggers_entries "]"
#line 2887 "dhcp6_parser.yy"
                                                         {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4537 "dhcp6_parser.cc"
    break;

  case 822: // loggers_entries: loggers_entries ","
#line 2896 "dhcp6_parser.yy"
                                       {
                   ctx.warnAboutExtraCommas(yystack_[0].location);
                   }
#line 4545 "dhcp6_parser.cc"
    break;

  case 823: // $@132: %empty
#line 2902 "dhcp6_parser.yy"
                             {
    ElementPtr l(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(l);
    ctx.stack_.push_back(l);
}
#line 4555 "dhcp6_parser.cc"
    break;

  case 824: // logger_entry: "{" $@132 logger_params "}"
#line 2906 "dhcp6_parser.yy"
                               {
    ctx.stack_.pop_back();
}
#line 4563 "dhcp6_parser.cc"
    break;

  case 827: // logger_params: logger_params ","
#line 2912 "dhcp6_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 4571 "dhcp6_parser.cc"
    break;

  case 835: // debuglevel: "debuglevel" ":" "integer"
#line 2926 "dhcp6_parser.yy"
                                     {
    ctx.unique("debuglevel", ctx.loc2pos(yystack_[2].location));
    ElementPtr dl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("debuglevel", dl);
}
#line 4581 "dhcp6_parser.cc"
    break;

  case 836: // $@133: %empty
#line 2932 "dhcp6_parser.yy"
                   {
    ctx.unique("severity", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4590 "dhcp6_parser.cc"
    break;

  case 837: // severity: "severity" $@133 ":" "constant string"
#line 2935 "dhcp6_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("severity", sev);
    ctx.leave();
}
#line 4600 "dhcp6_parser.cc"
    break;

  case 838: // $@134: %empty
#line 2941 "dhcp6_parser.yy"
                                    {
    ctx.unique("output_options", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output_options", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OUTPUT_OPTIONS);
}
#line 4612 "dhcp6_parser.cc"
    break;

  case 839: // output_options_list: "output_options" $@134 ":" "[" output_options_list_content "]"
#line 2947 "dhcp6_parser.yy"
                                                                    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4621 "dhcp6_parser.cc"
    break;

  case 842: // output_options_list_content: output_options_list_content ","
#line 2954 "dhcp6_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 4629 "dhcp6_parser.cc"
    break;

  case 843: // $@135: %empty
#line 2959 "dhcp6_parser.yy"
                             {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 4639 "dhcp6_parser.cc"
    break;

  case 844: // output_entry: "{" $@135 output_params_list "}"
#line 2963 "dhcp6_parser.yy"
                                    {
    ctx.stack_.pop_back();
}
#line 4647 "dhcp6_parser.cc"
    break;

  case 847: // output_params_list: output_params_list ","
#line 2969 "dhcp6_parser.yy"
                                             {
                      ctx.warnAboutExtraCommas(yystack_[0].location);
                      }
#line 4655 "dhcp6_parser.cc"
    break;

  case 853: // $@136: %empty
#line 2981 "dhcp6_parser.yy"
               {
    ctx.unique("output", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4664 "dhcp6_parser.cc"
    break;

  case 854: // output: "output" $@136 ":" "constant string"
#line 2984 "dhcp6_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output", sev);
    ctx.leave();
}
#line 4674 "dhcp6_parser.cc"
    break;

  case 855: // flush: "flush" ":" "boolean"
#line 2990 "dhcp6_parser.yy"
                           {
    ctx.unique("flush", ctx.loc2pos(yystack_[2].location));
    ElementPtr flush(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush", flush);
}
#line 4684 "dhcp6_parser.cc"
    break;

  case 856: // maxsize: "maxsize" ":" "integer"
#line 2996 "dhcp6_parser.yy"
                               {
    ctx.unique("maxsize", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxsize(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxsize", maxsize);
}
#line 4694 "dhcp6_parser.cc"
    break;

  case 857: // maxver: "maxver" ":" "integer"
#line 3002 "dhcp6_parser.yy"
                             {
    ctx.unique("maxver", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxver(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxver", maxver);
}
#line 4704 "dhcp6_parser.cc"
    break;

  case 858: // $@137: %empty
#line 3008 "dhcp6_parser.yy"
                 {
    ctx.unique("pattern", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4713 "dhcp6_parser.cc"
    break;

  case 859: // pattern: "pattern" $@137 ":" "constant string"
#line 3011 "dhcp6_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pattern", sev);
    ctx.leave();
}
#line 4723 "dhcp6_parser.cc"
    break;

  case 860: // $@138: %empty
#line 3017 "dhcp6_parser.yy"
                             {
    ctx.unique("compatibility", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("compatibility", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.COMPATIBILITY);
}
#line 4735 "dhcp6_parser.cc"
    break;

  case 861: // compatibility: "compatibility" $@138 ":" "{" compatibility_params "}"
#line 3023 "dhcp6_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4744 "dhcp6_parser.cc"
    break;

  case 864: // compatibility_params: compatibility_params ","
#line 3030 "dhcp6_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 4752 "dhcp6_parser.cc"
    break;

  case 867: // lenient_option_parsing: "lenient-option-parsing" ":" "boolean"
#line 3039 "dhcp6_parser.yy"
                                                             {
    ctx.unique("lenient-option-parsing", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lenient-option-parsing", b);
}
#line 4762 "dhcp6_parser.cc"
    break;


#line 4766 "dhcp6_parser.cc"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
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
    YY_STACK_PRINT ();
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
  Dhcp6Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Dhcp6Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Dhcp6Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Dhcp6Parser::context.
  Dhcp6Parser::context::context (const Dhcp6Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Dhcp6Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Dhcp6Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Dhcp6Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short Dhcp6Parser::yypact_ninf_ = -1002;

  const signed char Dhcp6Parser::yytable_ninf_ = -1;

  const short
  Dhcp6Parser::yypact_[] =
  {
     616, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002,    39,    29,    70,    82,   138,
     144,   175,   184,   192,   203,   240,   249,   253,   262,   269,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,    29,  -172,
      76,   266,    35,   684,    19,   -30,   306,   -25,   130,   143,
     -86,   465,   112, -1002,    90,   231,   129,   274,   290, -1002,
      99, -1002, -1002, -1002, -1002, -1002, -1002, -1002,   295,   299,
     305,   338,   341,   357,   360,   367,   369,   380,   402,   408,
     415,   418, -1002,   425,   432,   434,   435,   436, -1002, -1002,
   -1002,   437,   438,   439, -1002, -1002, -1002,   441, -1002, -1002,
   -1002, -1002,   442,   443,   444, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,   453, -1002, -1002, -1002, -1002, -1002,
   -1002,   454,   456,   457, -1002, -1002,   458, -1002,   120, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002,   460,   461,   464,   467, -1002,
     126, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,   468,   469, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,   141, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,   189,
   -1002, -1002, -1002, -1002, -1002,   470, -1002,   471,   476, -1002,
   -1002, -1002, -1002, -1002, -1002,   190, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,   302,   466, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,   473, -1002, -1002,   478, -1002, -1002, -1002,
     479, -1002, -1002,   480,   481, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,   485,   486,
     487, -1002, -1002, -1002, -1002,   491,   490, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
     204, -1002, -1002, -1002,   498, -1002, -1002,   501, -1002,   502,
     503, -1002, -1002,   504,   505, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002,   238, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
     506,   250, -1002, -1002, -1002, -1002,    29,    29, -1002,   282,
     509, -1002, -1002,   512,   514,   516,   517,   520,   522,    43,
     314,   315,   317,   319,   320,   321,   322,   278,   324,   325,
     328,   332,   334,   545,   336,   337,   340,   343,   348,   548,
     549,   550,   349,   350,   351,   565,   566,   571,   363,   572,
     575,   576,   577,   366,   370,   371,   581,   584,   587,   588,
     589,   591,   593,   594,   595,   386,   599,   601,   604,   605,
     606,   608,   398,   399,   400,   613,   615, -1002,   266, -1002,
     617,   409,   411,   412,   427,    35, -1002,   618,   619,   620,
     638,   639,   430,   429,   642,   643,   646,   684, -1002,   647,
      19, -1002,   648,   440,   649,   446,   447,   -30, -1002,   651,
     653,   654,   658,   659,   660,   661, -1002,   306, -1002,   662,
     663,   455,   664,   667,   668,   459, -1002,   130,   669,   463,
     472,   474, -1002,   143,   670,   672,   -51, -1002,   475,   673,
     676,   483,   677,   484,   488,   678,   679,   492,   493,   680,
     681,   682,   683,   465, -1002,   685,   496,   112, -1002, -1002,
   -1002,   691,   692,   499,   694,   704,   706,   707,   710, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,   507, -1002, -1002, -1002, -1002, -1002,  -123,
     508,   510, -1002, -1002, -1002,   712,   713,   714, -1002,   717,
     718,   511,     5, -1002, -1002, -1002,   721,   722,   723,   737,
     724,   740,   741,   750,   751, -1002,   753,   754,   755,   761,
     534,   556, -1002, -1002, -1002,   765,   764, -1002,   768, -1002,
   -1002, -1002, -1002, -1002,   770,   771,   564,   578,   582, -1002,
   -1002,   768,   583,   772, -1002,   585, -1002,   586, -1002,   590,
   -1002, -1002, -1002,   768,   768,   768,   592,   596,   597,   598,
   -1002,   600,   621, -1002,   622,   623,   624, -1002, -1002,   625,
   -1002, -1002, -1002, -1002,   626,   718, -1002, -1002,   627,   628,
   -1002,   629, -1002, -1002,    91,   610, -1002, -1002,  -123,   630,
     631,   632, -1002,   773, -1002, -1002,    29,   266, -1002,   112,
      35,   135,   135,   782, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,   783,   790,   793,   794, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002,   -91,    29,   259,   281,   797,
     801,   805,   254,    89,    42,   194,   198,   465, -1002, -1002,
     822,  -118, -1002, -1002,   823,   824, -1002, -1002, -1002, -1002,
   -1002,   -81, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002,   782, -1002,   251,   263,   267, -1002, -1002, -1002, -1002,
     828,   829,   842,   843,   844,   845,   846, -1002,   847, -1002,
   -1002, -1002, -1002, -1002,   276, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,   277, -1002,   848,   849, -1002, -1002,
     850,   852, -1002, -1002,   851,   855, -1002, -1002,   853,   857,
   -1002, -1002,   856,   858, -1002, -1002, -1002,    34, -1002, -1002,
   -1002,   859, -1002, -1002, -1002,    97, -1002, -1002, -1002, -1002,
   -1002,   289, -1002, -1002, -1002, -1002,   140, -1002, -1002,   860,
     861, -1002, -1002,   863,   867, -1002,   868,   869,   870,   871,
     872,   873,   293, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002,   874,   875,   876, -1002, -1002, -1002, -1002,   297,
   -1002, -1002, -1002, -1002, -1002, -1002,   877,   878,   879, -1002,
     303, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002,   304, -1002, -1002, -1002,   880, -1002,   881, -1002,
   -1002, -1002,   346, -1002, -1002, -1002, -1002, -1002,   352, -1002,
     227, -1002,   882, -1002,   362, -1002, -1002,   640, -1002,   865,
     884, -1002, -1002,   883,   885, -1002, -1002, -1002,   886, -1002,
     887, -1002, -1002, -1002,   888,   891,   892,   894,   686,   674,
     687,   675,   688,   689,   690,   895,   693,   901,   902,   904,
     905,   135, -1002, -1002,   135, -1002,   782,   684, -1002,   783,
     130, -1002,   790,   143, -1002,   793,  1299, -1002,   794,   -91,
   -1002, -1002,   259, -1002,   906,   907,   281, -1002,   153,   797,
   -1002,   306, -1002,   801,   -86, -1002,   805,   698,   699,   700,
     701,   702,   703,   254, -1002,   914,   915,   708,   709,   711,
      89, -1002,   705,   715,   716,    42, -1002,   916,   920,   194,
   -1002,   719,   922,   720,   923,   198, -1002, -1002,   155,   822,
   -1002,   725,  -118, -1002, -1002,   925,   929,    19, -1002,   823,
     -30, -1002,   824,   924, -1002, -1002,   149,   650,   726,   727,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002,   121, -1002,   729,
     730,   731,   732, -1002,   364, -1002,   379, -1002,   928, -1002,
     930, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,   396, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002,   734,   735, -1002,
   -1002, -1002,   933, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,   942,   948, -1002, -1002, -1002, -1002,
   -1002, -1002,   945, -1002,   397, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,    73,   743, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,   745,   746, -1002, -1002,   749, -1002,    29,
   -1002, -1002,   950, -1002, -1002, -1002, -1002, -1002,   406, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002,   752,   407, -1002,
     410, -1002,   756, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002,  1299, -1002, -1002, -1002,   967,   968,   760, -1002,
     153, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002,   975,   769,   978,   155, -1002, -1002, -1002, -1002,
   -1002, -1002,   774,   778, -1002, -1002,   980, -1002,   780, -1002,
   -1002, -1002,   926, -1002, -1002,   280, -1002,    -6,   926, -1002,
   -1002,   997,   998,   999, -1002,   417, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,  1002,   792,   796,   800,  1018,    -6, -1002,
     811, -1002, -1002, -1002,   812, -1002, -1002, -1002
  };

  const short
  Dhcp6Parser::yydefact_[] =
  {
       0,     2,     4,     6,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    46,    38,    34,    33,    30,    31,    32,    37,     3,
      35,    36,    61,     5,    67,     7,   184,     9,   365,    11,
     570,    13,   597,    15,   629,    17,   488,    19,   497,    21,
     536,    23,   327,    25,   757,    27,   808,    29,    48,    41,
       0,     0,     0,     0,     0,     0,   631,     0,   499,   538,
       0,     0,     0,    50,     0,    49,     0,     0,    42,    63,
       0,    65,   137,   806,   182,   203,   205,   207,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,     0,     0,     0,     0,     0,   156,   163,
     165,     0,     0,     0,   356,   486,   527,     0,   434,   584,
     586,   426,     0,     0,     0,   283,   302,   292,   272,   667,
     620,   318,   339,   699,     0,   304,   724,   738,   755,   169,
     171,     0,     0,     0,   818,   860,     0,   136,     0,    69,
      72,    73,    74,    75,    76,    77,    78,    79,    80,   111,
     112,   113,   114,   115,    81,   119,   120,   121,   122,   123,
     124,   125,   126,   117,   118,   127,   128,   129,   106,   135,
     131,   132,   133,    84,    85,    86,    87,   103,    88,    90,
      89,   130,    94,    95,    82,   108,   109,   110,   107,    83,
      92,    93,   101,   102,   104,    91,    96,    97,    98,    99,
     100,   105,   116,   134,   197,     0,     0,     0,     0,   196,
       0,   186,   189,   190,   191,   192,   193,   194,   195,   561,
     588,   413,   415,   417,     0,     0,   421,   419,   661,   412,
     370,   371,   372,   373,   374,   375,   376,   377,   396,   397,
     398,   399,   400,   403,   404,   405,   406,   407,   408,   409,
     410,   401,   402,   411,     0,   367,   381,   382,   383,   386,
     387,   390,   391,   392,   389,   384,   385,   378,   379,   394,
     395,   380,   388,   393,   582,   581,   577,   578,   576,     0,
     572,   575,   579,   580,   613,     0,   616,     0,     0,   612,
     606,   607,   605,   610,   611,     0,   599,   602,   603,   608,
     609,   604,   659,   647,   649,   651,   653,   655,   657,   646,
     643,   644,   645,     0,   632,   633,   638,   639,   636,   640,
     641,   642,   637,     0,   517,   250,     0,   521,   519,   524,
       0,   513,   514,     0,   500,   501,   504,   516,   505,   506,
     507,   523,   508,   509,   510,   511,   512,   554,     0,     0,
       0,   552,   553,   556,   557,     0,   539,   540,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   335,   337,   332,
       0,   329,   333,   334,     0,   781,   783,     0,   786,     0,
       0,   790,   794,     0,     0,   798,   800,   802,   804,   779,
     777,   778,     0,   759,   762,   774,   763,   764,   765,   766,
     767,   768,   769,   770,   771,   772,   773,   775,   776,   815,
       0,     0,   810,   813,   814,    47,    52,     0,    39,    45,
       0,    66,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    71,    68,
       0,     0,     0,     0,     0,   188,   185,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   369,   366,     0,
     574,   571,     0,     0,     0,     0,     0,   601,   598,     0,
       0,     0,     0,     0,     0,     0,   630,   635,   489,     0,
       0,     0,     0,     0,     0,     0,   498,   503,     0,     0,
       0,     0,   537,   542,     0,     0,   331,   328,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   761,   758,     0,     0,   812,   809,    51,
      43,     0,     0,     0,     0,     0,     0,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,   174,   175,   153,   154,   155,     0,
       0,     0,   167,   168,   173,     0,     0,     0,   178,     0,
       0,     0,     0,   423,   424,   425,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   723,     0,     0,     0,     0,
       0,     0,   179,   180,   181,     0,     0,    70,     0,   199,
     200,   201,   202,   187,     0,     0,     0,     0,     0,   432,
     433,     0,     0,     0,   368,     0,   573,     0,   615,     0,
     618,   619,   600,     0,     0,     0,     0,     0,     0,     0,
     634,     0,     0,   515,     0,     0,     0,   526,   502,     0,
     558,   559,   560,   541,     0,     0,   330,   780,     0,     0,
     785,     0,   788,   789,     0,     0,   796,   797,     0,     0,
       0,     0,   760,     0,   817,   811,     0,     0,   138,     0,
       0,     0,     0,   209,   177,   158,   159,   160,   161,   162,
     157,   164,   166,   358,   490,   529,   436,    40,   585,   587,
     428,   429,   430,   431,   427,     0,    48,     0,     0,     0,
     622,   320,     0,     0,     0,     0,     0,     0,   170,   172,
       0,     0,    53,   198,   563,   590,   414,   416,   418,   422,
     420,     0,   583,   614,   617,   660,   648,   650,   652,   654,
     656,   658,   518,   251,   522,   520,   525,   555,   336,   338,
     782,   784,   787,   792,   793,   791,   795,   799,   801,   803,
     805,   209,    44,     0,     0,     0,   238,   243,   245,   247,
       0,     0,     0,     0,     0,     0,     0,   257,     0,   264,
     266,   268,   270,   237,     0,   216,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   230,   231,   232,   229,
     233,   234,   235,   236,     0,   214,     0,   210,   211,   363,
       0,   359,   360,   495,     0,   491,   492,   534,     0,   530,
     531,   441,     0,   437,   438,   290,   291,     0,   285,   288,
     289,     0,   300,   301,   297,     0,   294,   298,   299,   279,
     281,     0,   274,   277,   278,   672,     0,   669,   627,     0,
     623,   624,   325,     0,   321,   322,     0,     0,     0,     0,
       0,     0,     0,   341,   344,   345,   346,   347,   348,   349,
     713,   719,     0,     0,     0,   712,   709,   710,   711,     0,
     701,   704,   707,   705,   706,   708,     0,     0,     0,   314,
       0,   306,   309,   310,   311,   312,   313,   734,   736,   733,
     731,   732,     0,   726,   729,   730,     0,   750,     0,   753,
     746,   747,     0,   740,   743,   744,   745,   748,     0,   823,
       0,   820,     0,   866,     0,   862,   865,    55,   568,     0,
     564,   565,   595,     0,   591,   592,   665,   664,     0,   663,
       0,    64,   807,   183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   218,   204,   206,     0,   208,   213,     0,   357,   362,
     499,   487,   494,   538,   528,   533,     0,   435,   440,   287,
     284,   303,   296,   293,     0,     0,   276,   273,   674,   671,
     668,   631,   621,   626,     0,   319,   324,     0,     0,     0,
       0,     0,     0,   343,   340,     0,     0,     0,     0,     0,
     703,   700,     0,     0,     0,   308,   305,     0,     0,   728,
     725,     0,     0,     0,     0,   742,   739,   756,     0,   822,
     819,     0,   864,   861,    57,     0,    56,     0,   562,   567,
       0,   589,   594,     0,   662,   816,     0,     0,     0,     0,
     249,   252,   253,   254,   255,   263,   256,     0,   262,     0,
       0,     0,     0,   217,     0,   212,     0,   361,     0,   493,
       0,   532,   485,   460,   461,   462,   464,   465,   466,   450,
     451,   469,   470,   471,   472,   473,   476,   477,   478,   479,
     480,   481,   482,   483,   474,   475,   484,   446,   447,   448,
     449,   458,   459,   455,   456,   457,   454,   463,     0,   443,
     452,   467,   468,   453,   439,   286,   295,     0,     0,   275,
     694,   696,     0,   692,   686,   687,   688,   689,   690,   691,
     693,   683,   684,   685,     0,   675,   676,   679,   680,   681,
     682,   670,     0,   625,     0,   323,   350,   351,   352,   353,
     354,   355,   342,     0,     0,   718,   721,   722,   702,   315,
     316,   317,   307,     0,     0,   727,   749,     0,   752,     0,
     741,   838,     0,   836,   834,   828,   832,   833,     0,   825,
     830,   831,   829,   821,   867,   863,    54,    59,     0,   566,
       0,   593,     0,   240,   241,   242,   239,   244,   246,   248,
     259,   260,   261,   258,   265,   267,   269,   271,   215,   364,
     496,   535,   445,   442,   280,   282,     0,     0,     0,   673,
     678,   628,   326,   715,   716,   717,   714,   720,   735,   737,
     751,   754,     0,     0,     0,   827,   824,    58,   569,   596,
     666,   444,     0,     0,   698,   677,     0,   835,     0,   826,
     695,   697,     0,   837,   843,     0,   840,     0,   842,   839,
     853,     0,     0,     0,   858,     0,   845,   848,   849,   850,
     851,   852,   841,     0,     0,     0,     0,     0,   847,   844,
       0,   855,   856,   857,     0,   846,   854,   859
  };

  const short
  Dhcp6Parser::yypgoto_[] =
  {
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002,   -10, -1002,  -600, -1002,
     342, -1002, -1002, -1002, -1002,   273, -1002,  -586, -1002, -1002,
   -1002,   -71, -1002, -1002, -1002, -1002, -1002, -1002, -1002,   312,
     538, -1002, -1002,   -42,    11,    14,    17,    18,    28,   -31,
     -29,   -27,   -13,    31,    33,    41, -1002,    44,    45,    46,
      47, -1002,   333,    51, -1002,    57, -1002,    62,    63,    67,
   -1002,    69, -1002,    74, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002,   323,   527, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
     265, -1002,    65, -1002,  -710,    87, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002,   -46, -1002,  -752, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,    66,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002,    84,  -734, -1002,
   -1002, -1002, -1002,    72, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002,    49, -1002, -1002, -1002, -1002, -1002, -1002, -1002,    53,
   -1002, -1002, -1002,    64,   544, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002,    58, -1002, -1002, -1002, -1002, -1002, -1002, -1001,
   -1002, -1002, -1002,    93, -1002, -1002, -1002,    98,   602, -1002,
   -1002, -1000, -1002,  -999, -1002,    81, -1002,    83, -1002,    75,
      77,    79,    80, -1002, -1002, -1002,  -998, -1002, -1002, -1002,
   -1002,    88, -1002, -1002,  -145,  1041, -1002, -1002, -1002, -1002,
   -1002,   100, -1002, -1002, -1002,   101, -1002,   562, -1002,   -62,
   -1002, -1002, -1002, -1002, -1002,   -59, -1002, -1002, -1002, -1002,
   -1002,    -5, -1002, -1002, -1002,    95, -1002, -1002, -1002,   102,
   -1002,   560, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002,    37, -1002, -1002, -1002,    40,   603,
   -1002, -1002,   -60, -1002,     0, -1002, -1002, -1002, -1002, -1002,
      32, -1002, -1002, -1002,    38,   607, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,   -49, -1002, -1002, -1002,    92, -1002, -1002,
   -1002,    96, -1002,   609,   353, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,  -997, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002,   103, -1002, -1002, -1002,
    -140, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
      71, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,    78, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002,    61, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002,   365,   555, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002,   414,   552, -1002, -1002, -1002, -1002, -1002,
   -1002,    85, -1002, -1002,  -144, -1002, -1002, -1002, -1002, -1002,
   -1002,  -168, -1002, -1002,  -183, -1002, -1002, -1002, -1002, -1002,
   -1002, -1002, -1002, -1002, -1002,    68, -1002
  };

  const short
  Dhcp6Parser::yydefgoto_[] =
  {
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    83,    39,    40,    69,
     748,    87,    88,    41,    68,    84,    85,   773,   977,  1085,
    1086,   833,    43,    70,    90,   440,    91,    45,    71,   158,
     159,   160,   443,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   469,   740,   179,   470,   180,   471,   181,   182,   183,
     500,   184,   501,   185,   186,   187,   188,   463,   189,   190,
     191,   192,   193,   445,    47,    72,   230,   231,   232,   510,
     233,   234,   235,   236,   194,   446,   195,   447,   196,   448,
     856,   857,   858,  1014,   834,   835,   836,   994,  1246,   837,
     995,   838,   996,   839,   997,   840,   841,   550,   842,   843,
     844,   845,   846,   847,  1005,  1253,   848,   849,   850,  1007,
     851,  1008,   852,  1009,   853,  1010,   197,   489,   891,   892,
     893,  1034,   894,  1035,   198,   486,   877,   878,   879,   880,
     199,   488,   885,   886,   887,   888,   200,   487,   201,   496,
     940,   941,   942,   943,   944,   202,   492,   903,   904,   905,
    1044,    63,    80,   390,   391,   392,   564,   393,   565,   203,
     493,   912,   913,   914,   915,   916,   917,   918,   919,   204,
     475,   860,   861,   862,  1017,    49,    73,   274,   275,   276,
     519,   277,   520,   278,   521,   279,   525,   280,   524,   205,
     206,   207,   208,   482,   754,   285,   286,   209,   479,   872,
     873,   874,  1026,  1158,  1159,   210,   476,    57,    77,   864,
     865,   866,  1020,    59,    78,   353,   354,   355,   356,   357,
     358,   359,   549,   360,   553,   361,   552,   362,   363,   554,
     364,   211,   477,   868,   869,   870,  1023,    61,    79,   375,
     376,   377,   378,   379,   558,   380,   381,   382,   383,   384,
     288,   517,   979,   980,   981,  1087,    51,    74,   299,   300,
     301,   529,   212,   480,   213,   481,   291,   518,   983,   984,
     985,  1090,    53,    75,   315,   316,   317,   532,   318,   319,
     534,   320,   321,   214,   491,   899,   900,   901,  1041,    55,
      76,   333,   334,   335,   336,   540,   337,   541,   338,   542,
     339,   543,   340,   544,   341,   545,   342,   539,   293,   526,
     988,   989,  1093,   215,   490,   896,   897,  1038,  1184,  1185,
    1186,  1187,  1188,  1266,  1189,  1267,  1190,   216,   494,   929,
     930,   931,  1055,  1276,   932,   933,  1056,   934,   935,   217,
     218,   497,   952,   953,   954,  1067,   955,  1068,   219,   498,
     962,   963,   964,   965,  1072,   966,   967,  1074,   220,   499,
      65,    81,   412,   413,   414,   415,   569,   416,   570,   417,
     418,   572,   419,   420,   421,   575,   805,   422,   576,   423,
     424,   425,   579,   426,   580,   427,   581,   428,   582,   221,
     444,    67,    82,   431,   432,   433,   585,   434,   222,   505,
     970,   971,  1078,  1228,  1229,  1230,  1231,  1284,  1232,  1282,
    1305,  1306,  1307,  1315,  1316,  1317,  1323,  1318,  1319,  1320,
    1321,  1327,   223,   506,   974,   975,   976
  };

  const short
  Dhcp6Parser::yytable_[] =
  {
     157,   229,   249,   295,   309,   329,    38,   351,   371,   389,
     409,   926,   237,   289,   302,   313,   331,   373,   365,   385,
     374,   410,   854,   884,   292,  1148,  1149,  1150,  1157,  1163,
     747,   250,   352,   372,    31,   875,    32,  1029,    33,    30,
    1030,    86,   256,   323,   257,   126,   258,   387,   388,   125,
     986,   224,   225,   226,   227,   228,   735,   736,   737,   738,
     259,   304,   305,   306,   307,   308,   129,   130,   287,   298,
     312,   330,   238,   290,   303,   314,   332,    42,   366,   386,
     972,   411,   387,   388,   251,   779,    89,   252,   246,    44,
     253,   254,   247,   739,   126,   156,   435,   785,   786,   787,
    1032,   255,   441,  1033,   260,   747,   261,   442,   294,   750,
     751,   752,   753,   920,   262,   129,   130,   263,   264,   265,
     266,   821,   876,   508,   267,   429,   430,   156,   509,   515,
     268,   129,   130,   437,   516,   269,   270,   246,   129,   130,
     271,   247,   272,  1039,   527,    46,  1040,   273,   281,   528,
     282,    48,   283,   284,   344,   296,   310,   297,   311,   816,
    1250,  1251,  1252,   817,   818,   819,   820,   821,   822,   823,
     824,   825,   826,   827,  1243,  1244,  1245,   828,   829,   830,
     831,   832,    50,   156,  1310,   129,   130,  1311,  1312,  1313,
    1314,    52,   530,   537,   936,   937,   938,   531,   538,    54,
      98,    99,   100,   101,   102,   103,   345,   566,   346,   347,
      56,   345,   567,   348,   349,   350,  1273,  1274,  1275,   345,
     367,   346,   347,   368,   369,   370,   129,   130,   126,   345,
    1079,   345,   156,  1080,   436,   921,   922,   923,   924,   129,
     130,   583,    34,    35,    36,    37,   584,    58,   156,   129,
     130,   129,   130,   587,   508,   156,    60,   599,   588,   991,
      62,  1148,  1149,  1150,  1157,  1163,   587,   803,   804,    64,
     515,   992,  1170,  1171,  1172,   993,    66,    92,    93,  1011,
    1011,    94,   438,  1308,  1012,  1013,  1309,    95,    96,    97,
     129,   130,  1036,   439,   129,   130,  1053,  1037,   884,   449,
    1060,  1054,   156,   450,  1114,  1061,  1065,  1069,   926,   451,
     546,  1066,  1070,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   452,   156,  1221,   453,  1222,  1223,   156,  1075,
     947,   948,   127,   128,  1076,   583,   156,   956,   957,   958,
    1077,   454,   129,   130,   455,  1082,   156,  1011,   156,   131,
    1083,   456,  1258,   457,   132,   133,   134,   135,   136,   137,
     138,   126,   527,   139,   458,   875,   882,  1259,   883,   140,
     906,   907,   908,   909,   910,   911,   889,   890,   141,  1262,
     566,   142,   129,   130,  1263,  1272,   459,   156,   143,  1285,
     530,   959,   460,   537,  1286,  1288,   144,   145,  1289,   461,
    1328,   146,   462,   322,   147,  1329,   589,   590,   148,   464,
     323,   324,   325,   326,   327,   328,   465,   157,   466,   467,
     468,   472,   473,   474,   229,   478,   483,   484,   485,   149,
     150,   151,   152,   153,   154,   237,   249,   495,   502,   295,
     503,   504,   507,   155,   511,   512,   309,   289,   513,   547,
     302,   514,   522,   523,   533,   535,   329,   313,   292,   156,
     536,   548,   551,   555,   557,   250,   351,   331,   556,   559,
     560,   561,   371,   563,   607,   591,   256,   365,   257,   562,
     258,   373,   568,   385,   374,   571,   573,   574,   577,   578,
     586,   352,   409,   592,   259,   238,   593,   372,   594,   156,
     595,   596,   287,   410,   597,   298,   598,   290,   600,   601,
     303,   602,   312,   603,   604,   605,   606,   314,   251,   608,
     609,   252,   330,   610,   253,   254,   611,   332,   612,   613,
     614,   615,   619,   620,   621,   255,   616,   366,   260,   617,
     261,   129,   130,   386,   618,   622,   623,   624,   262,   625,
     626,   263,   264,   265,   266,   627,   629,   628,   267,   630,
     631,   632,   633,   411,   268,   636,   634,   635,   637,   269,
     270,   638,   639,   640,   271,   641,   272,   642,   643,   644,
     645,   273,   281,   646,   282,   647,   283,   284,   648,   649,
     650,   296,   651,   297,   652,   653,   654,   655,   310,   656,
     311,   658,   664,   665,   666,   659,   661,   660,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   662,   667,   668,   669,   670,   671,   672,   407,   408,
     673,   675,   677,   679,   678,   683,   157,   684,   685,   229,
     680,   681,   686,   687,   688,   689,   691,   692,   694,   693,
     237,   695,   696,   699,   704,   697,   705,   708,   156,   700,
     709,   711,   714,   715,   718,   719,   720,   721,   701,   723,
     702,   707,   925,   939,   949,   726,   409,   710,   712,   727,
     973,   729,   713,   927,   945,   950,   960,   410,   716,   717,
     724,   730,   728,   731,   732,   733,   812,   743,   744,   745,
     734,   741,   746,   742,   749,    32,   755,   756,   757,   759,
     238,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   758,   760,   761,   768,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   762,   763,   126,
     764,   765,   766,   928,   946,   951,   961,   411,   767,   769,
     770,   771,   239,   772,   240,   774,   775,   776,   811,   781,
     129,   130,   241,   242,   243,   244,   245,   131,   806,   855,
     859,   777,   132,   133,   134,   778,   780,   863,   782,   783,
     867,   871,   246,   784,   895,   788,   247,   140,   898,   789,
     790,   791,   902,   792,   248,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   969,
     978,   982,   998,   999,   793,   794,   795,   796,   797,   798,
     800,   801,   802,   808,   809,   810,  1000,  1001,  1002,  1003,
    1004,  1006,  1016,  1084,  1015,  1019,  1018,  1021,  1022,  1024,
    1025,  1028,  1027,  1247,  1043,  1031,  1042,   149,   150,  1045,
    1046,  1088,  1047,  1048,  1049,  1050,  1051,  1052,  1057,  1058,
    1059,  1062,  1063,  1064,  1071,  1073,  1081,  1089,  1092,  1091,
    1101,  1103,  1096,  1095,  1094,  1097,  1098,   156,  1099,  1107,
    1100,  1102,  1104,  1105,  1106,  1109,  1110,  1108,  1111,  1112,
    1167,  1168,  1196,  1197,  1198,  1199,  1200,  1201,  1203,  1204,
    1213,  1209,  1205,  1206,  1214,  1207,  1217,  1219,  1242,  1210,
    1211,  1236,  1237,  1304,  1218,  1216,  1260,  1268,  1261,  1248,
    1249,  1234,  1254,  1255,  1256,  1257,   249,  1264,  1265,   351,
    1269,  1270,   371,  1271,  1283,  1122,  1277,   289,  1278,  1279,
     365,   373,  1280,   385,   374,  1287,  1161,  1173,   292,  1290,
     329,  1292,  1293,   389,   352,   250,  1294,   372,  1182,  1296,
    1147,   331,  1298,  1297,  1123,  1302,   256,  1300,   257,   925,
     258,  1301,  1180,  1303,   939,  1129,  1174,  1130,   949,  1131,
     927,  1324,  1325,  1326,   259,   945,  1330,  1224,  1331,   950,
    1332,   973,   287,  1132,  1333,   960,   295,   290,  1226,   309,
     366,  1160,  1334,   386,  1336,  1337,  1162,   302,   251,   881,
     313,   252,  1225,  1181,   253,   254,   330,  1124,  1183,   813,
    1125,   332,   663,  1126,  1127,   255,   657,   799,   260,  1175,
     261,   807,  1176,   815,  1128,  1177,  1178,  1133,   262,  1134,
     928,   263,   264,   265,   266,   946,  1179,  1135,   267,   951,
    1136,  1137,  1138,  1139,   268,   961,   990,  1140,  1227,   269,
     270,  1115,   298,  1141,   271,   312,   272,   303,  1142,  1143,
     314,   273,   281,  1144,   282,  1145,   283,   284,  1113,  1195,
    1146,  1153,  1169,  1154,  1166,  1155,  1156,  1151,  1194,  1152,
     706,  1202,  1117,  1165,  1212,  1116,  1164,  1291,   343,   698,
    1121,  1118,  1119,   703,  1241,  1120,  1239,  1238,  1240,   674,
    1295,  1208,   968,   676,   987,  1193,  1220,  1192,   722,   725,
    1322,  1299,  1191,   814,   682,  1335,     0,  1215,     0,     0,
    1235,     0,     0,     0,     0,     0,   690,     0,     0,     0,
       0,     0,     0,     0,  1233,     0,     0,     0,   296,     0,
     297,   310,     0,   311,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1122,     0,     0,     0,     0,     0,     0,     0,  1173,
       0,     0,  1161,     0,     0,     0,     0,     0,     0,  1281,
    1182,     0,     0,     0,  1224,     0,  1147,     0,     0,     0,
    1123,     0,     0,     0,  1180,  1226,     0,     0,  1174,     0,
       0,  1129,     0,  1130,     0,  1131,     0,     0,     0,  1225,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1132,
       0,     0,     0,     0,     0,     0,     0,  1160,     0,     0,
       0,     0,  1162,     0,     0,  1181,     0,     0,     0,     0,
    1183,     0,     0,  1124,     0,     0,  1125,     0,     0,  1126,
    1127,  1175,     0,     0,  1176,  1227,     0,  1177,  1178,     0,
    1128,     0,     0,  1133,     0,  1134,     0,     0,  1179,     0,
       0,     0,     0,  1135,     0,     0,  1136,  1137,  1138,  1139,
       0,     0,     0,  1140,     0,     0,     0,     0,     0,  1141,
       0,     0,     0,     0,  1142,  1143,     0,     0,     0,  1144,
       0,  1145,     0,     0,     0,     0,  1146,  1153,     0,  1154,
       0,  1155,  1156,  1151,     0,  1152,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   126,   345,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,   130,     0,   242,   243,
       0,   245,   131,     0,     0,     0,     0,   132,   133,   134,
       0,     0,     0,     0,     0,     0,     0,   246,     0,     0,
       0,   247,     0,     0,     0,     0,     0,     0,     0,   248,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156
  };

  const short
  Dhcp6Parser::yycheck_[] =
  {
      71,    72,    73,    74,    75,    76,    16,    78,    79,    80,
      81,   763,    72,    73,    74,    75,    76,    79,    78,    79,
      79,    81,   732,   757,    73,  1026,  1026,  1026,  1026,  1026,
     630,    73,    78,    79,     5,   126,     7,     3,     9,     0,
       6,   213,    73,   124,    73,    75,    73,   133,   134,    74,
     131,    16,    17,    18,    19,    20,   179,   180,   181,   182,
      73,    91,    92,    93,    94,    95,    96,    97,    73,    74,
      75,    76,    72,    73,    74,    75,    76,     7,    78,    79,
     198,    81,   133,   134,    73,   671,    10,    73,   118,     7,
      73,    73,   122,   216,    75,   213,     6,   683,   684,   685,
       3,    73,     3,     6,    73,   705,    73,     8,    89,   104,
     105,   106,   107,    24,    73,    96,    97,    73,    73,    73,
      73,    32,   213,     3,    73,    13,    14,   213,     8,     3,
      73,    96,    97,     4,     8,    73,    73,   118,    96,    97,
      73,   122,    73,     3,     3,     7,     6,    73,    73,     8,
      73,     7,    73,    73,    24,    74,    75,    74,    75,    24,
      39,    40,    41,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    25,    26,    27,    42,    43,    44,
      45,    46,     7,   213,   190,    96,    97,   193,   194,   195,
     196,     7,     3,     3,   152,   153,   154,     8,     8,     7,
      47,    48,    49,    50,    51,    52,    76,     3,    78,    79,
       7,    76,     8,    83,    84,    85,   143,   144,   145,    76,
      77,    78,    79,    80,    81,    82,    96,    97,    75,    76,
       3,    76,   213,     6,     3,   146,   147,   148,   149,    96,
      97,     3,   213,   214,   215,   216,     8,     7,   213,    96,
      97,    96,    97,     3,     3,   213,     7,   214,     8,     8,
       7,  1262,  1262,  1262,  1262,  1262,     3,   176,   177,     7,
       3,     8,   119,   120,   121,     8,     7,    11,    12,     3,
       3,    15,     8,     3,     8,     8,     6,    21,    22,    23,
      96,    97,     3,     3,    96,    97,     3,     8,  1032,     4,
       3,     8,   213,     4,  1014,     8,     3,     3,  1060,     4,
       8,     8,     8,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,     4,   213,   189,     4,   191,   192,   213,     3,
     156,   157,    86,    87,     8,     3,   213,   159,   160,   161,
       8,     4,    96,    97,     4,     3,   213,     3,   213,   103,
       8,     4,     8,     4,   108,   109,   110,   111,   112,   113,
     114,    75,     3,   117,     4,   126,   127,     8,   129,   123,
     136,   137,   138,   139,   140,   141,   115,   116,   132,     3,
       3,   135,    96,    97,     8,     8,     4,   213,   142,     3,
       3,   213,     4,     3,     8,     8,   150,   151,     8,     4,
       3,   155,     4,   117,   158,     8,   436,   437,   162,     4,
     124,   125,   126,   127,   128,   129,     4,   508,     4,     4,
       4,     4,     4,     4,   515,     4,     4,     4,     4,   183,
     184,   185,   186,   187,   188,   515,   527,     4,     4,   530,
       4,     4,     4,   197,     4,     4,   537,   527,     4,     3,
     530,     4,     4,     4,     4,     4,   547,   537,   527,   213,
       4,     8,     4,     4,     3,   527,   557,   547,     8,     4,
       4,     4,   563,     3,   216,   213,   527,   557,   527,     8,
     527,   563,     4,   563,   563,     4,     4,     4,     4,     4,
       4,   557,   583,     4,   527,   515,     4,   563,     4,   213,
       4,     4,   527,   583,     4,   530,     4,   527,   214,   214,
     530,   214,   537,   214,   214,   214,   214,   537,   527,   215,
     215,   527,   547,   215,   527,   527,   214,   547,   214,     4,
     214,   214,     4,     4,     4,   527,   216,   557,   527,   216,
     527,    96,    97,   563,   216,   216,   216,   216,   527,     4,
       4,   527,   527,   527,   527,     4,     4,   214,   527,     4,
       4,     4,   216,   583,   527,     4,   216,   216,     4,   527,
     527,     4,     4,     4,   527,     4,   527,     4,     4,     4,
     214,   527,   527,     4,   527,     4,   527,   527,     4,     4,
       4,   530,     4,   530,   216,   216,   216,     4,   537,     4,
     537,     4,     4,     4,     4,   216,   214,   216,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   214,     4,     4,   214,   216,     4,     4,   183,   184,
       4,     4,     4,     4,   214,     4,   727,     4,     4,   730,
     214,   214,     4,     4,     4,     4,     4,     4,     4,   214,
     730,     4,     4,     4,     4,   216,     4,     4,   213,   216,
       4,     4,     4,     4,     4,     4,     4,     4,   216,     4,
     216,   216,   763,   764,   765,     4,   767,   214,   214,     7,
     771,     7,   214,   763,   764,   765,   766,   767,   216,   216,
     214,     7,   213,     7,     7,     5,   726,     5,     5,     5,
     213,   213,     5,   213,   213,     7,     5,     5,     5,     5,
     730,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     7,     5,     5,   213,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     7,     7,    75,
       7,     7,     7,   763,   764,   765,   766,   767,     7,   213,
       5,     7,    88,     5,    90,     5,     5,   213,     5,     7,
      96,    97,    98,    99,   100,   101,   102,   103,   178,     7,
       7,   213,   108,   109,   110,   213,   213,     7,   213,   213,
       7,     7,   118,   213,     7,   213,   122,   123,     7,   213,
     213,   213,     7,   213,   130,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,     7,
       7,     7,     4,     4,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,     4,     4,     4,     4,
       4,     4,     3,   213,     6,     3,     6,     6,     3,     6,
       3,     3,     6,   213,     3,     6,     6,   183,   184,     6,
       3,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     3,     6,
     216,   216,     4,     6,     8,     4,     4,   213,     4,     4,
     214,   214,   214,   214,   214,     4,     4,   214,     4,     4,
       4,     4,   214,   214,   214,   214,   214,   214,     4,     4,
       4,   216,   214,   214,     4,   214,     4,     4,     4,   214,
     214,     6,     3,     7,   214,   216,     8,     4,     8,   213,
     213,   216,   213,   213,   213,   213,  1017,   213,   213,  1020,
       8,     3,  1023,     8,     4,  1026,   213,  1017,   213,   213,
    1020,  1023,   213,  1023,  1023,   213,  1026,  1038,  1017,   213,
    1041,     4,     4,  1044,  1020,  1017,   216,  1023,  1038,     4,
    1026,  1041,     4,   214,  1026,     5,  1017,   213,  1017,  1060,
    1017,   213,  1038,   213,  1065,  1026,  1038,  1026,  1069,  1026,
    1060,     4,     4,     4,  1017,  1065,     4,  1078,   216,  1069,
     214,  1082,  1017,  1026,   214,  1075,  1087,  1017,  1078,  1090,
    1020,  1026,     4,  1023,   213,   213,  1026,  1087,  1017,   756,
    1090,  1017,  1078,  1038,  1017,  1017,  1041,  1026,  1038,   727,
    1026,  1041,   515,  1026,  1026,  1017,   508,   705,  1017,  1038,
    1017,   718,  1038,   730,  1026,  1038,  1038,  1026,  1017,  1026,
    1060,  1017,  1017,  1017,  1017,  1065,  1038,  1026,  1017,  1069,
    1026,  1026,  1026,  1026,  1017,  1075,   811,  1026,  1078,  1017,
    1017,  1016,  1087,  1026,  1017,  1090,  1017,  1087,  1026,  1026,
    1090,  1017,  1017,  1026,  1017,  1026,  1017,  1017,  1011,  1046,
    1026,  1026,  1036,  1026,  1032,  1026,  1026,  1026,  1044,  1026,
     566,  1053,  1019,  1029,  1065,  1017,  1028,  1262,    77,   557,
    1025,  1020,  1022,   563,  1092,  1023,  1089,  1087,  1090,   527,
    1270,  1060,   767,   530,   781,  1043,  1075,  1041,   583,   587,
    1308,  1285,  1039,   729,   537,  1328,    -1,  1069,    -1,    -1,
    1082,    -1,    -1,    -1,    -1,    -1,   547,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1079,    -1,    -1,    -1,  1087,    -1,
    1087,  1090,    -1,  1090,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1270,
      -1,    -1,  1262,    -1,    -1,    -1,    -1,    -1,    -1,  1219,
    1270,    -1,    -1,    -1,  1285,    -1,  1262,    -1,    -1,    -1,
    1262,    -1,    -1,    -1,  1270,  1285,    -1,    -1,  1270,    -1,
      -1,  1262,    -1,  1262,    -1,  1262,    -1,    -1,    -1,  1285,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1262,    -1,    -1,
      -1,    -1,  1262,    -1,    -1,  1270,    -1,    -1,    -1,    -1,
    1270,    -1,    -1,  1262,    -1,    -1,  1262,    -1,    -1,  1262,
    1262,  1270,    -1,    -1,  1270,  1285,    -1,  1270,  1270,    -1,
    1262,    -1,    -1,  1262,    -1,  1262,    -1,    -1,  1270,    -1,
      -1,    -1,    -1,  1262,    -1,    -1,  1262,  1262,  1262,  1262,
      -1,    -1,    -1,  1262,    -1,    -1,    -1,    -1,    -1,  1262,
      -1,    -1,    -1,    -1,  1262,  1262,    -1,    -1,    -1,  1262,
      -1,  1262,    -1,    -1,    -1,    -1,  1262,  1262,    -1,  1262,
      -1,  1262,  1262,  1262,    -1,  1262,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,   100,
      -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213
  };

  const short
  Dhcp6Parser::yystos_[] =
  {
       0,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
       0,     5,     7,     9,   213,   214,   215,   216,   233,   234,
     235,   240,     7,   249,     7,   254,     7,   301,     7,   412,
       7,   493,     7,   509,     7,   526,     7,   444,     7,   450,
       7,   474,     7,   388,     7,   597,     7,   628,   241,   236,
     250,   255,   302,   413,   494,   510,   527,   445,   451,   475,
     389,   598,   629,   233,   242,   243,   213,   238,   239,    10,
     251,   253,    11,    12,    15,    21,    22,    23,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    86,    87,    96,
      97,   103,   108,   109,   110,   111,   112,   113,   114,   117,
     123,   132,   135,   142,   150,   151,   155,   158,   162,   183,
     184,   185,   186,   187,   188,   197,   213,   248,   256,   257,
     258,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   280,
     282,   284,   285,   286,   288,   290,   291,   292,   293,   295,
     296,   297,   298,   299,   311,   313,   315,   353,   361,   367,
     373,   375,   382,   396,   406,   426,   427,   428,   429,   434,
     442,   468,   499,   501,   520,   550,   564,   576,   577,   585,
     595,   626,   635,   659,    16,    17,    18,    19,    20,   248,
     303,   304,   305,   307,   308,   309,   310,   499,   501,    88,
      90,    98,    99,   100,   101,   102,   118,   122,   130,   248,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   274,   275,   276,   277,   280,   282,   284,
     285,   286,   288,   290,   414,   415,   416,   418,   420,   422,
     424,   426,   427,   428,   429,   432,   433,   468,   487,   499,
     501,   503,   520,   545,    89,   248,   422,   424,   468,   495,
     496,   497,   499,   501,    91,    92,    93,    94,    95,   248,
     422,   424,   468,   499,   501,   511,   512,   513,   515,   516,
     518,   519,   117,   124,   125,   126,   127,   128,   129,   248,
     468,   499,   501,   528,   529,   530,   531,   533,   535,   537,
     539,   541,   543,   442,    24,    76,    78,    79,    83,    84,
      85,   248,   333,   452,   453,   454,   455,   456,   457,   458,
     460,   462,   464,   465,   467,   499,   501,    77,    80,    81,
      82,   248,   333,   456,   462,   476,   477,   478,   479,   480,
     482,   483,   484,   485,   486,   499,   501,   133,   134,   248,
     390,   391,   392,   394,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   183,   184,   248,
     499,   501,   599,   600,   601,   602,   604,   606,   607,   609,
     610,   611,   614,   616,   617,   618,   620,   622,   624,    13,
      14,   630,   631,   632,   634,     6,     3,     4,     8,     3,
     252,     3,     8,   259,   627,   300,   312,   314,   316,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,   294,     4,     4,     4,     4,     4,   278,
     281,   283,     4,     4,     4,   407,   443,   469,     4,   435,
     500,   502,   430,     4,     4,     4,   362,   374,   368,   354,
     551,   521,   383,   397,   565,     4,   376,   578,   586,   596,
     287,   289,     4,     4,     4,   636,   660,     4,     3,     8,
     306,     4,     4,     4,     4,     3,     8,   488,   504,   417,
     419,   421,     4,     4,   425,   423,   546,     3,     8,   498,
       3,     8,   514,     4,   517,     4,     4,     3,     8,   544,
     532,   534,   536,   538,   540,   542,     8,     3,     8,   459,
     334,     4,   463,   461,   466,     4,     8,     3,   481,     4,
       4,     4,     8,     3,   393,   395,     3,     8,     4,   603,
     605,     4,   608,     4,     4,   612,   615,     4,     4,   619,
     621,   623,   625,     3,     8,   633,     4,     3,     8,   233,
     233,   213,     4,     4,     4,     4,     4,     4,     4,   214,
     214,   214,   214,   214,   214,   214,   214,   216,   215,   215,
     215,   214,   214,     4,   214,   214,   216,   216,   216,     4,
       4,     4,   216,   216,   216,     4,     4,     4,   214,     4,
       4,     4,     4,   216,   216,   216,     4,     4,     4,     4,
       4,     4,     4,     4,     4,   214,     4,     4,     4,     4,
       4,     4,   216,   216,   216,     4,     4,   257,     4,   216,
     216,   214,   214,   304,     4,     4,     4,     4,     4,   214,
     216,     4,     4,     4,   415,     4,   496,     4,   214,     4,
     214,   214,   512,     4,     4,     4,     4,     4,     4,     4,
     530,     4,     4,   214,     4,     4,     4,   216,   454,     4,
     216,   216,   216,   478,     4,     4,   391,   216,     4,     4,
     214,     4,   214,   214,     4,     4,   216,   216,     4,     4,
       4,     4,   600,     4,   214,   631,     4,     7,   213,     7,
       7,     7,     7,     5,   213,   179,   180,   181,   182,   216,
     279,   213,   213,     5,     5,     5,     5,   235,   237,   213,
     104,   105,   106,   107,   431,     5,     5,     5,     7,     5,
       5,     5,     7,     7,     7,     7,     7,     7,   213,   213,
       5,     7,     5,   244,     5,     5,   213,   213,   213,   244,
     213,     7,   213,   213,   213,   244,   244,   244,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   237,
     213,   213,   213,   176,   177,   613,   178,   279,   213,   213,
     213,     5,   233,   256,   630,   303,    24,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    42,    43,
      44,    45,    46,   248,   321,   322,   323,   326,   328,   330,
     332,   333,   335,   336,   337,   338,   339,   340,   343,   344,
     345,   347,   349,   351,   321,     7,   317,   318,   319,     7,
     408,   409,   410,     7,   446,   447,   448,     7,   470,   471,
     472,     7,   436,   437,   438,   126,   213,   363,   364,   365,
     366,   242,   127,   129,   365,   369,   370,   371,   372,   115,
     116,   355,   356,   357,   359,     7,   552,   553,     7,   522,
     523,   524,     7,   384,   385,   386,   136,   137,   138,   139,
     140,   141,   398,   399,   400,   401,   402,   403,   404,   405,
      24,   146,   147,   148,   149,   248,   335,   499,   501,   566,
     567,   568,   571,   572,   574,   575,   152,   153,   154,   248,
     377,   378,   379,   380,   381,   499,   501,   156,   157,   248,
     499,   501,   579,   580,   581,   583,   159,   160,   161,   213,
     499,   501,   587,   588,   589,   590,   592,   593,   599,     7,
     637,   638,   198,   248,   661,   662,   663,   245,     7,   489,
     490,   491,     7,   505,   506,   507,   131,   531,   547,   548,
     317,     8,     8,     8,   324,   327,   329,   331,     4,     4,
       4,     4,     4,     4,     4,   341,     4,   346,   348,   350,
     352,     3,     8,     8,   320,     6,     3,   411,     6,     3,
     449,     6,     3,   473,     6,     3,   439,     6,     3,     3,
       6,     6,     3,     6,   358,   360,     3,     8,   554,     3,
       6,   525,     6,     3,   387,     6,     3,     4,     4,     4,
       4,     4,     4,     3,     8,   569,   573,     4,     4,     4,
       3,     8,     4,     4,     4,     3,     8,   582,   584,     3,
       8,     4,   591,     4,   594,     3,     8,     8,   639,     3,
       6,     4,     3,     8,   213,   246,   247,   492,     6,     3,
     508,     6,     3,   549,     8,     6,     4,     4,     4,     4,
     214,   216,   214,   216,   214,   214,   214,     4,   214,     4,
       4,     4,     4,   322,   321,   319,   414,   410,   452,   448,
     476,   472,   248,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   274,   275,   276,   277,
     280,   282,   284,   285,   286,   288,   290,   333,   406,   418,
     420,   422,   424,   426,   427,   428,   429,   433,   440,   441,
     468,   499,   501,   545,   438,   364,   370,     4,     4,   356,
     119,   120,   121,   248,   260,   261,   262,   263,   264,   265,
     333,   468,   499,   501,   555,   556,   557,   558,   559,   561,
     563,   553,   528,   524,   390,   386,   214,   214,   214,   214,
     214,   214,   399,     4,     4,   214,   214,   214,   567,   216,
     214,   214,   378,     4,     4,   580,   216,     4,   214,     4,
     588,   189,   191,   192,   248,   333,   499,   501,   640,   641,
     642,   643,   645,   638,   216,   662,     6,     3,   495,   491,
     511,   507,     4,    25,    26,    27,   325,   213,   213,   213,
      39,    40,    41,   342,   213,   213,   213,   213,     8,     8,
       8,     8,     3,     8,   213,   213,   560,   562,     4,     8,
       3,     8,     8,   143,   144,   145,   570,   213,   213,   213,
     213,   233,   646,     4,   644,     3,     8,   213,     8,     8,
     213,   441,     4,     4,   216,   557,     4,   214,     4,   641,
     213,   213,     5,   213,     7,   647,   648,   649,     3,     6,
     190,   193,   194,   195,   196,   650,   651,   652,   654,   655,
     656,   657,   648,   653,     4,     4,     4,   658,     3,     8,
       4,   216,   214,   214,     4,   651,   213,   213
  };

  const short
  Dhcp6Parser::yyr1_[] =
  {
       0,   217,   219,   218,   220,   218,   221,   218,   222,   218,
     223,   218,   224,   218,   225,   218,   226,   218,   227,   218,
     228,   218,   229,   218,   230,   218,   231,   218,   232,   218,
     233,   233,   233,   233,   233,   233,   233,   234,   236,   235,
     237,   238,   238,   239,   239,   239,   241,   240,   242,   242,
     243,   243,   243,   245,   244,   246,   246,   247,   247,   247,
     248,   250,   249,   252,   251,   251,   253,   255,   254,   256,
     256,   256,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   259,   258,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   278,   277,   279,   279,
     279,   279,   279,   281,   280,   283,   282,   284,   285,   287,
     286,   289,   288,   290,   291,   292,   294,   293,   295,   296,
     297,   298,   300,   299,   302,   301,   303,   303,   303,   304,
     304,   304,   304,   304,   304,   304,   304,   306,   305,   307,
     308,   309,   310,   312,   311,   314,   313,   316,   315,   317,
     317,   318,   318,   318,   320,   319,   321,   321,   321,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   324,   323,
     325,   325,   325,   327,   326,   329,   328,   331,   330,   332,
     334,   333,   335,   336,   337,   338,   339,   341,   340,   342,
     342,   342,   343,   344,   346,   345,   348,   347,   350,   349,
     352,   351,   354,   353,   355,   355,   355,   356,   356,   358,
     357,   360,   359,   362,   361,   363,   363,   363,   364,   364,
     365,   366,   368,   367,   369,   369,   369,   370,   370,   370,
     371,   372,   374,   373,   376,   375,   377,   377,   377,   378,
     378,   378,   378,   378,   378,   379,   380,   381,   383,   382,
     384,   384,   385,   385,   385,   387,   386,   389,   388,   390,
     390,   390,   390,   391,   391,   393,   392,   395,   394,   397,
     396,   398,   398,   398,   399,   399,   399,   399,   399,   399,
     400,   401,   402,   403,   404,   405,   407,   406,   408,   408,
     409,   409,   409,   411,   410,   413,   412,   414,   414,   414,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   417,   416,   419,   418,   421,   420,   423,
     422,   425,   424,   426,   427,   428,   430,   429,   431,   431,
     431,   431,   432,   433,   435,   434,   436,   436,   437,   437,
     437,   439,   438,   440,   440,   440,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   443,   442,   445,   444,
     446,   446,   447,   447,   447,   449,   448,   451,   450,   452,
     452,   453,   453,   453,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   455,   456,   457,   459,   458,   461,
     460,   463,   462,   464,   466,   465,   467,   469,   468,   470,
     470,   471,   471,   471,   473,   472,   475,   474,   476,   476,
     477,   477,   477,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   479,   481,   480,   482,   483,   484,   485,
     486,   488,   487,   489,   489,   490,   490,   490,   492,   491,
     494,   493,   495,   495,   495,   496,   496,   496,   496,   496,
     496,   496,   498,   497,   500,   499,   502,   501,   504,   503,
     505,   505,   506,   506,   506,   508,   507,   510,   509,   511,
     511,   511,   512,   512,   512,   512,   512,   512,   512,   512,
     512,   512,   512,   514,   513,   515,   517,   516,   518,   519,
     521,   520,   522,   522,   523,   523,   523,   525,   524,   527,
     526,   528,   528,   529,   529,   529,   530,   530,   530,   530,
     530,   530,   530,   530,   530,   530,   530,   532,   531,   534,
     533,   536,   535,   538,   537,   540,   539,   542,   541,   544,
     543,   546,   545,   547,   547,   549,   548,   551,   550,   552,
     552,   552,   554,   553,   555,   555,   556,   556,   556,   557,
     557,   557,   557,   557,   557,   557,   557,   557,   557,   557,
     557,   557,   557,   558,   560,   559,   562,   561,   563,   565,
     564,   566,   566,   566,   567,   567,   567,   567,   567,   567,
     567,   567,   567,   569,   568,   570,   570,   570,   571,   573,
     572,   574,   575,   576,   578,   577,   579,   579,   579,   580,
     580,   580,   580,   580,   582,   581,   584,   583,   586,   585,
     587,   587,   587,   588,   588,   588,   588,   588,   588,   589,
     591,   590,   592,   594,   593,   596,   595,   598,   597,   599,
     599,   599,   600,   600,   600,   600,   600,   600,   600,   600,
     600,   600,   600,   600,   600,   600,   600,   600,   600,   600,
     601,   603,   602,   605,   604,   606,   608,   607,   609,   610,
     612,   611,   613,   613,   615,   614,   616,   617,   619,   618,
     621,   620,   623,   622,   625,   624,   627,   626,   629,   628,
     630,   630,   630,   631,   631,   633,   632,   634,   636,   635,
     637,   637,   637,   639,   638,   640,   640,   640,   641,   641,
     641,   641,   641,   641,   641,   642,   644,   643,   646,   645,
     647,   647,   647,   649,   648,   650,   650,   650,   651,   651,
     651,   651,   651,   653,   652,   654,   655,   656,   658,   657,
     660,   659,   661,   661,   661,   662,   662,   663
  };

  const signed char
  Dhcp6Parser::yyr2_[] =
  {
       0,     2,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     0,     1,     3,     5,     2,     0,     4,     0,     1,
       1,     3,     2,     0,     4,     0,     1,     1,     3,     2,
       2,     0,     4,     0,     6,     1,     2,     0,     4,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     0,     4,     1,     1,
       1,     1,     1,     0,     4,     0,     4,     3,     3,     0,
       4,     0,     4,     3,     3,     3,     0,     4,     3,     3,
       3,     3,     0,     6,     0,     4,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     3,
       3,     3,     3,     0,     6,     0,     6,     0,     6,     0,
       1,     1,     3,     2,     0,     4,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     1,     1,     0,     4,     0,     4,     0,     4,     3,
       0,     4,     3,     3,     3,     3,     3,     0,     4,     1,
       1,     1,     3,     3,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     6,     1,     3,     2,     1,     1,     0,
       4,     0,     4,     0,     6,     1,     3,     2,     1,     1,
       1,     1,     0,     6,     1,     3,     2,     1,     1,     1,
       1,     1,     0,     6,     0,     6,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     0,     6,
       0,     1,     1,     3,     2,     0,     4,     0,     4,     1,
       3,     2,     1,     1,     1,     0,     4,     0,     4,     0,
       6,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     0,     6,     0,     1,
       1,     3,     2,     0,     4,     0,     4,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     3,     3,     3,     0,     4,     1,     1,
       1,     1,     3,     3,     0,     6,     0,     1,     1,     3,
       2,     0,     4,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     0,     4,
       0,     1,     1,     3,     2,     0,     4,     0,     4,     0,
       1,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     4,     0,
       4,     0,     4,     1,     0,     4,     3,     0,     6,     0,
       1,     1,     3,     2,     0,     4,     0,     4,     0,     1,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     1,     3,     3,
       3,     0,     6,     0,     1,     1,     3,     2,     0,     4,
       0,     4,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     4,     0,     4,     0,     6,
       0,     1,     1,     3,     2,     0,     4,     0,     4,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     3,     0,     4,     3,     3,
       0,     6,     0,     1,     1,     3,     2,     0,     4,     0,
       4,     0,     1,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     6,     1,     1,     0,     4,     0,     6,     1,
       3,     2,     0,     4,     0,     1,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     0,     4,     3,     0,
       6,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     1,     1,     1,     3,     0,
       4,     3,     3,     3,     0,     6,     1,     3,     2,     1,
       1,     1,     1,     1,     0,     4,     0,     4,     0,     6,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       0,     4,     3,     0,     4,     0,     6,     0,     4,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     4,     0,     4,     3,     0,     4,     3,     3,
       0,     4,     1,     1,     0,     4,     3,     3,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     6,     0,     4,
       1,     3,     2,     1,     1,     0,     6,     3,     0,     6,
       1,     3,     2,     0,     4,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     4,     0,     6,
       1,     3,     2,     0,     4,     1,     3,     2,     1,     1,
       1,     1,     1,     0,     4,     3,     3,     3,     0,     4,
       0,     6,     1,     3,     2,     1,     1,     3
  };


#if PARSER6_DEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Dhcp6Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\",\"", "\":\"",
  "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\"null\"", "\"Dhcp6\"",
  "\"data-directory\"", "\"config-control\"", "\"config-databases\"",
  "\"config-fetch-wait-time\"", "\"interfaces-config\"", "\"interfaces\"",
  "\"re-detect\"", "\"service-sockets-require-all\"",
  "\"service-sockets-retry-wait-time\"", "\"service-sockets-max-retries\"",
  "\"lease-database\"", "\"hosts-database\"", "\"hosts-databases\"",
  "\"type\"", "\"memfile\"", "\"mysql\"", "\"postgresql\"", "\"user\"",
  "\"password\"", "\"host\"", "\"port\"", "\"persist\"",
  "\"lfc-interval\"", "\"readonly\"", "\"connect-timeout\"",
  "\"max-reconnect-tries\"", "\"reconnect-wait-time\"", "\"on-fail\"",
  "\"stop-retry-exit\"", "\"serve-retry-exit\"",
  "\"serve-retry-continue\"", "\"max-row-errors\"", "\"trust-anchor\"",
  "\"cert-file\"", "\"key-file\"", "\"cipher-list\"",
  "\"preferred-lifetime\"", "\"min-preferred-lifetime\"",
  "\"max-preferred-lifetime\"", "\"valid-lifetime\"",
  "\"min-valid-lifetime\"", "\"max-valid-lifetime\"", "\"renew-timer\"",
  "\"rebind-timer\"", "\"calculate-tee-times\"", "\"t1-percent\"",
  "\"t2-percent\"", "\"cache-threshold\"", "\"cache-max-age\"",
  "\"decline-probation-period\"", "\"server-tag\"",
  "\"statistic-default-sample-count\"", "\"statistic-default-sample-age\"",
  "\"ddns-send-updates\"", "\"ddns-override-no-update\"",
  "\"ddns-override-client-update\"", "\"ddns-replace-client-name\"",
  "\"ddns-generated-prefix\"", "\"ddns-qualifying-suffix\"",
  "\"ddns-update-on-renew\"", "\"ddns-use-conflict-resolution\"",
  "\"store-extended-info\"", "\"subnet6\"", "\"option-def\"",
  "\"option-data\"", "\"name\"", "\"data\"", "\"code\"", "\"space\"",
  "\"csv-format\"", "\"always-send\"", "\"never-send\"",
  "\"record-types\"", "\"encapsulate\"", "\"array\"",
  "\"parked-packet-limit\"", "\"shared-networks\"", "\"pools\"",
  "\"pool\"", "\"pd-pools\"", "\"prefix\"", "\"prefix-len\"",
  "\"excluded-prefix\"", "\"excluded-prefix-len\"", "\"delegated-len\"",
  "\"user-context\"", "\"comment\"", "\"subnet\"", "\"interface\"",
  "\"interface-id\"", "\"id\"", "\"rapid-commit\"", "\"reservation-mode\"",
  "\"disabled\"", "\"out-of-pool\"", "\"global\"", "\"all\"",
  "\"reservations-global\"", "\"reservations-in-subnet\"",
  "\"reservations-out-of-pool\"", "\"mac-sources\"",
  "\"relay-supplied-options\"", "\"host-reservation-identifiers\"",
  "\"sanity-checks\"", "\"lease-checks\"", "\"extended-info-checks\"",
  "\"client-classes\"", "\"require-client-classes\"", "\"test\"",
  "\"template-test\"", "\"only-if-required\"", "\"client-class\"",
  "\"reservations\"", "\"ip-addresses\"", "\"prefixes\"", "\"duid\"",
  "\"hw-address\"", "\"hostname\"", "\"flex-id\"", "\"relay\"",
  "\"ip-address\"", "\"hooks-libraries\"", "\"library\"", "\"parameters\"",
  "\"expired-leases-processing\"", "\"reclaim-timer-wait-time\"",
  "\"flush-reclaimed-timer-wait-time\"", "\"hold-reclaimed-time\"",
  "\"max-reclaim-leases\"", "\"max-reclaim-time\"",
  "\"unwarned-reclaim-cycles\"", "\"server-id\"", "\"LLT\"", "\"EN\"",
  "\"LL\"", "\"identifier\"", "\"htype\"", "\"time\"", "\"enterprise-id\"",
  "\"dhcp4o6-port\"", "\"multi-threading\"", "\"enable-multi-threading\"",
  "\"thread-pool-size\"", "\"packet-queue-size\"", "\"control-socket\"",
  "\"socket-type\"", "\"socket-name\"", "\"dhcp-queue-control\"",
  "\"enable-queue\"", "\"queue-type\"", "\"capacity\"", "\"dhcp-ddns\"",
  "\"enable-updates\"", "\"qualifying-suffix\"", "\"server-ip\"",
  "\"server-port\"", "\"sender-ip\"", "\"sender-port\"",
  "\"max-queue-size\"", "\"ncr-protocol\"", "\"ncr-format\"",
  "\"override-no-update\"", "\"override-client-update\"",
  "\"replace-client-name\"", "\"generated-prefix\"", "\"UDP\"", "\"TCP\"",
  "\"JSON\"", "\"when-present\"", "\"never\"", "\"always\"",
  "\"when-not-present\"", "\"hostname-char-set\"",
  "\"hostname-char-replacement\"", "\"early-global-reservations-lookup\"",
  "\"ip-reservations-unique\"", "\"reservations-lookup-first\"",
  "\"loggers\"", "\"output_options\"", "\"output\"", "\"debuglevel\"",
  "\"severity\"", "\"flush\"", "\"maxsize\"", "\"maxver\"", "\"pattern\"",
  "\"compatibility\"", "\"lenient-option-parsing\"", "TOPLEVEL_JSON",
  "TOPLEVEL_DHCP6", "SUB_DHCP6", "SUB_INTERFACES6", "SUB_SUBNET6",
  "SUB_POOL6", "SUB_PD_POOL", "SUB_RESERVATION", "SUB_OPTION_DEFS",
  "SUB_OPTION_DEF", "SUB_OPTION_DATA", "SUB_HOOKS_LIBRARY",
  "SUB_DHCP_DDNS", "SUB_CONFIG_CONTROL", "\"constant string\"",
  "\"integer\"", "\"floating point\"", "\"boolean\"", "$accept", "start",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "$@11", "$@12", "$@13", "$@14", "value", "sub_json", "map2", "$@15",
  "map_value", "map_content", "not_empty_map", "list_generic", "$@16",
  "list_content", "not_empty_list", "list_strings", "$@17",
  "list_strings_content", "not_empty_list_strings", "unknown_map_entry",
  "syntax_map", "$@18", "global_object", "$@19", "global_object_comma",
  "sub_dhcp6", "$@20", "global_params", "global_param", "data_directory",
  "$@21", "preferred_lifetime", "min_preferred_lifetime",
  "max_preferred_lifetime", "valid_lifetime", "min_valid_lifetime",
  "max_valid_lifetime", "renew_timer", "rebind_timer",
  "calculate_tee_times", "t1_percent", "t2_percent", "cache_threshold",
  "cache_max_age", "decline_probation_period", "ddns_send_updates",
  "ddns_override_no_update", "ddns_override_client_update",
  "ddns_replace_client_name", "$@22", "ddns_replace_client_name_value",
  "ddns_generated_prefix", "$@23", "ddns_qualifying_suffix", "$@24",
  "ddns_update_on_renew", "ddns_use_conflict_resolution",
  "hostname_char_set", "$@25", "hostname_char_replacement", "$@26",
  "store_extended_info", "statistic_default_sample_count",
  "statistic_default_sample_age", "server_tag", "$@27",
  "parked_packet_limit", "early_global_reservations_lookup",
  "ip_reservations_unique", "reservations_lookup_first",
  "interfaces_config", "$@28", "sub_interfaces6", "$@29",
  "interfaces_config_params", "interfaces_config_param", "interfaces_list",
  "$@30", "re_detect", "service_sockets_require_all",
  "service_sockets_retry_wait_time", "service_sockets_max_retries",
  "lease_database", "$@31", "hosts_database", "$@32", "hosts_databases",
  "$@33", "database_list", "not_empty_database_list", "database", "$@34",
  "database_map_params", "database_map_param", "database_type", "$@35",
  "db_type", "user", "$@36", "password", "$@37", "host", "$@38", "port",
  "name", "$@39", "persist", "lfc_interval", "readonly", "connect_timeout",
  "reconnect_wait_time", "on_fail", "$@40", "on_fail_mode",
  "max_row_errors", "max_reconnect_tries", "trust_anchor", "$@41",
  "cert_file", "$@42", "key_file", "$@43", "cipher_list", "$@44",
  "sanity_checks", "$@45", "sanity_checks_params", "sanity_checks_param",
  "lease_checks", "$@46", "extended_info_checks", "$@47", "mac_sources",
  "$@48", "mac_sources_list", "mac_sources_value", "duid_id", "string_id",
  "host_reservation_identifiers", "$@49",
  "host_reservation_identifiers_list", "host_reservation_identifier",
  "hw_address_id", "flex_id", "relay_supplied_options", "$@50",
  "dhcp_multi_threading", "$@51", "multi_threading_params",
  "multi_threading_param", "enable_multi_threading", "thread_pool_size",
  "packet_queue_size", "hooks_libraries", "$@52", "hooks_libraries_list",
  "not_empty_hooks_libraries_list", "hooks_library", "$@53",
  "sub_hooks_library", "$@54", "hooks_params", "hooks_param", "library",
  "$@55", "parameters", "$@56", "expired_leases_processing", "$@57",
  "expired_leases_params", "expired_leases_param",
  "reclaim_timer_wait_time", "flush_reclaimed_timer_wait_time",
  "hold_reclaimed_time", "max_reclaim_leases", "max_reclaim_time",
  "unwarned_reclaim_cycles", "subnet6_list", "$@58",
  "subnet6_list_content", "not_empty_subnet6_list", "subnet6", "$@59",
  "sub_subnet6", "$@60", "subnet6_params", "subnet6_param", "subnet",
  "$@61", "interface", "$@62", "interface_id", "$@63", "client_class",
  "$@64", "require_client_classes", "$@65", "reservations_global",
  "reservations_in_subnet", "reservations_out_of_pool", "reservation_mode",
  "$@66", "hr_mode", "id", "rapid_commit", "shared_networks", "$@67",
  "shared_networks_content", "shared_networks_list", "shared_network",
  "$@68", "shared_network_params", "shared_network_param",
  "option_def_list", "$@69", "sub_option_def_list", "$@70",
  "option_def_list_content", "not_empty_option_def_list",
  "option_def_entry", "$@71", "sub_option_def", "$@72",
  "option_def_params", "not_empty_option_def_params", "option_def_param",
  "option_def_name", "code", "option_def_code", "option_def_type", "$@73",
  "option_def_record_types", "$@74", "space", "$@75", "option_def_space",
  "option_def_encapsulate", "$@76", "option_def_array", "option_data_list",
  "$@77", "option_data_list_content", "not_empty_option_data_list",
  "option_data_entry", "$@78", "sub_option_data", "$@79",
  "option_data_params", "not_empty_option_data_params",
  "option_data_param", "option_data_name", "option_data_data", "$@80",
  "option_data_code", "option_data_space", "option_data_csv_format",
  "option_data_always_send", "option_data_never_send", "pools_list",
  "$@81", "pools_list_content", "not_empty_pools_list", "pool_list_entry",
  "$@82", "sub_pool6", "$@83", "pool_params", "pool_param", "pool_entry",
  "$@84", "user_context", "$@85", "comment", "$@86", "pd_pools_list",
  "$@87", "pd_pools_list_content", "not_empty_pd_pools_list",
  "pd_pool_entry", "$@88", "sub_pd_pool", "$@89", "pd_pool_params",
  "pd_pool_param", "pd_prefix", "$@90", "pd_prefix_len", "excluded_prefix",
  "$@91", "excluded_prefix_len", "pd_delegated_len", "reservations",
  "$@92", "reservations_list", "not_empty_reservations_list",
  "reservation", "$@93", "sub_reservation", "$@94", "reservation_params",
  "not_empty_reservation_params", "reservation_param", "ip_addresses",
  "$@95", "prefixes", "$@96", "duid", "$@97", "hw_address", "$@98",
  "hostname", "$@99", "flex_id_value", "$@100",
  "reservation_client_classes", "$@101", "relay", "$@102", "relay_map",
  "ip_address", "$@103", "client_classes", "$@104", "client_classes_list",
  "client_class_entry", "$@105", "client_class_params",
  "not_empty_client_class_params", "client_class_param",
  "client_class_name", "client_class_test", "$@106",
  "client_class_template_test", "$@107", "only_if_required", "server_id",
  "$@108", "server_id_params", "server_id_param", "server_id_type",
  "$@109", "duid_type", "htype", "identifier", "$@110", "time",
  "enterprise_id", "dhcp4o6_port", "control_socket", "$@111",
  "control_socket_params", "control_socket_param", "socket_type", "$@112",
  "socket_name", "$@113", "dhcp_queue_control", "$@114",
  "queue_control_params", "queue_control_param", "enable_queue",
  "queue_type", "$@115", "capacity", "arbitrary_map_entry", "$@116",
  "dhcp_ddns", "$@117", "sub_dhcp_ddns", "$@118", "dhcp_ddns_params",
  "dhcp_ddns_param", "enable_updates", "dep_qualifying_suffix", "$@119",
  "server_ip", "$@120", "server_port", "sender_ip", "$@121", "sender_port",
  "max_queue_size", "ncr_protocol", "$@122", "ncr_protocol_value",
  "ncr_format", "$@123", "dep_override_no_update",
  "dep_override_client_update", "dep_replace_client_name", "$@124",
  "dep_generated_prefix", "$@125", "dep_hostname_char_set", "$@126",
  "dep_hostname_char_replacement", "$@127", "config_control", "$@128",
  "sub_config_control", "$@129", "config_control_params",
  "config_control_param", "config_databases", "$@130",
  "config_fetch_wait_time", "loggers", "$@131", "loggers_entries",
  "logger_entry", "$@132", "logger_params", "logger_param", "debuglevel",
  "severity", "$@133", "output_options_list", "$@134",
  "output_options_list_content", "output_entry", "$@135",
  "output_params_list", "output_params", "output", "$@136", "flush",
  "maxsize", "maxver", "pattern", "$@137", "compatibility", "$@138",
  "compatibility_params", "compatibility_param", "lenient_option_parsing", YY_NULLPTR
  };
#endif


#if PARSER6_DEBUG
  const short
  Dhcp6Parser::yyrline_[] =
  {
       0,   305,   305,   305,   306,   306,   307,   307,   308,   308,
     309,   309,   310,   310,   311,   311,   312,   312,   313,   313,
     314,   314,   315,   315,   316,   316,   317,   317,   318,   318,
     326,   327,   328,   329,   330,   331,   332,   335,   340,   340,
     351,   354,   355,   358,   363,   369,   374,   374,   381,   382,
     385,   389,   393,   399,   399,   406,   407,   410,   414,   418,
     428,   437,   437,   452,   452,   466,   469,   475,   475,   484,
     485,   486,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   560,   560,   569,
     575,   581,   587,   593,   599,   605,   611,   617,   623,   629,
     635,   641,   647,   653,   659,   665,   671,   671,   680,   683,
     686,   689,   692,   698,   698,   707,   707,   716,   722,   728,
     728,   737,   737,   746,   752,   758,   764,   764,   773,   779,
     785,   791,   797,   797,   809,   809,   818,   819,   820,   825,
     826,   827,   828,   829,   830,   831,   832,   835,   835,   846,
     852,   858,   864,   870,   870,   883,   883,   896,   896,   907,
     908,   911,   912,   913,   918,   918,   928,   929,   930,   935,
     936,   937,   938,   939,   940,   941,   942,   943,   944,   945,
     946,   947,   948,   949,   950,   951,   952,   953,   956,   956,
     964,   965,   966,   969,   969,   978,   978,   987,   987,   996,
    1002,  1002,  1011,  1017,  1023,  1029,  1035,  1041,  1041,  1049,
    1050,  1051,  1054,  1060,  1066,  1066,  1075,  1075,  1084,  1084,
    1093,  1093,  1102,  1102,  1113,  1114,  1115,  1120,  1121,  1124,
    1124,  1143,  1143,  1161,  1161,  1172,  1173,  1174,  1179,  1180,
    1183,  1188,  1193,  1193,  1204,  1205,  1206,  1211,  1212,  1213,
    1216,  1221,  1228,  1228,  1241,  1241,  1254,  1255,  1256,  1261,
    1262,  1263,  1264,  1265,  1266,  1269,  1275,  1281,  1287,  1287,
    1298,  1299,  1302,  1303,  1304,  1309,  1309,  1319,  1319,  1329,
    1330,  1331,  1334,  1337,  1338,  1341,  1341,  1350,  1350,  1359,
    1359,  1371,  1372,  1373,  1378,  1379,  1380,  1381,  1382,  1383,
    1386,  1392,  1398,  1404,  1410,  1416,  1425,  1425,  1439,  1440,
    1443,  1444,  1445,  1454,  1454,  1480,  1480,  1491,  1492,  1493,
    1499,  1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,  1508,
    1509,  1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,  1518,
    1519,  1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,  1528,
    1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,  1538,
    1539,  1540,  1541,  1544,  1544,  1553,  1553,  1562,  1562,  1571,
    1571,  1580,  1580,  1591,  1597,  1603,  1609,  1609,  1617,  1618,
    1619,  1620,  1623,  1629,  1637,  1637,  1649,  1650,  1654,  1655,
    1656,  1661,  1661,  1669,  1670,  1671,  1676,  1677,  1678,  1679,
    1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,  1689,
    1690,  1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,  1699,
    1700,  1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,
    1710,  1711,  1712,  1713,  1714,  1715,  1722,  1722,  1736,  1736,
    1745,  1746,  1749,  1750,  1751,  1758,  1758,  1773,  1773,  1787,
    1788,  1791,  1792,  1793,  1798,  1799,  1800,  1801,  1802,  1803,
    1804,  1805,  1806,  1807,  1810,  1812,  1818,  1820,  1820,  1829,
    1829,  1838,  1838,  1847,  1849,  1849,  1858,  1868,  1868,  1881,
    1882,  1887,  1888,  1889,  1896,  1896,  1908,  1908,  1920,  1921,
    1926,  1927,  1928,  1935,  1936,  1937,  1938,  1939,  1940,  1941,
    1942,  1943,  1944,  1947,  1949,  1949,  1958,  1960,  1962,  1968,
    1974,  1983,  1983,  1996,  1997,  2000,  2001,  2002,  2007,  2007,
    2017,  2017,  2027,  2028,  2029,  2034,  2035,  2036,  2037,  2038,
    2039,  2040,  2043,  2043,  2052,  2052,  2077,  2077,  2107,  2107,
    2120,  2121,  2124,  2125,  2126,  2131,  2131,  2143,  2143,  2155,
    2156,  2157,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,
    2170,  2171,  2172,  2175,  2175,  2184,  2190,  2190,  2199,  2205,
    2214,  2214,  2225,  2226,  2229,  2230,  2231,  2236,  2236,  2245,
    2245,  2254,  2255,  2258,  2259,  2260,  2266,  2267,  2268,  2269,
    2270,  2271,  2272,  2273,  2274,  2275,  2276,  2279,  2279,  2290,
    2290,  2301,  2301,  2310,  2310,  2319,  2319,  2328,  2328,  2337,
    2337,  2351,  2351,  2362,  2363,  2366,  2366,  2378,  2378,  2389,
    2390,  2391,  2396,  2396,  2406,  2407,  2410,  2411,  2412,  2417,
    2418,  2419,  2420,  2421,  2422,  2423,  2424,  2425,  2426,  2427,
    2428,  2429,  2430,  2433,  2435,  2435,  2444,  2444,  2453,  2462,
    2462,  2475,  2476,  2477,  2482,  2483,  2484,  2485,  2486,  2487,
    2488,  2489,  2490,  2493,  2493,  2501,  2502,  2503,  2506,  2512,
    2512,  2521,  2527,  2535,  2543,  2543,  2554,  2555,  2556,  2561,
    2562,  2563,  2564,  2565,  2568,  2568,  2577,  2577,  2589,  2589,
    2602,  2603,  2604,  2609,  2610,  2611,  2612,  2613,  2614,  2617,
    2623,  2623,  2632,  2638,  2638,  2648,  2648,  2661,  2661,  2671,
    2672,  2673,  2678,  2679,  2680,  2681,  2682,  2683,  2684,  2685,
    2686,  2687,  2688,  2689,  2690,  2691,  2692,  2693,  2694,  2695,
    2698,  2705,  2705,  2714,  2714,  2723,  2729,  2729,  2738,  2744,
    2750,  2750,  2759,  2760,  2763,  2763,  2773,  2780,  2787,  2787,
    2796,  2796,  2806,  2806,  2816,  2816,  2828,  2828,  2840,  2840,
    2850,  2851,  2852,  2858,  2859,  2862,  2862,  2873,  2881,  2881,
    2894,  2895,  2896,  2902,  2902,  2910,  2911,  2912,  2917,  2918,
    2919,  2920,  2921,  2922,  2923,  2926,  2932,  2932,  2941,  2941,
    2952,  2953,  2954,  2959,  2959,  2967,  2968,  2969,  2974,  2975,
    2976,  2977,  2978,  2981,  2981,  2990,  2996,  3002,  3008,  3008,
    3017,  3017,  3028,  3029,  3030,  3035,  3036,  3039
  };

  void
  Dhcp6Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Dhcp6Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // PARSER6_DEBUG


#line 14 "dhcp6_parser.yy"
} } // isc::dhcp
#line 6453 "dhcp6_parser.cc"

#line 3045 "dhcp6_parser.yy"


void
isc::dhcp::Dhcp6Parser::error(const location_type& loc,
                              const std::string& what)
{
    ctx.error(loc, what);
}
