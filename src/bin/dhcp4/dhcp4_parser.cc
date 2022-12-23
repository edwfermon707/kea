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
#define yylex   parser4_lex



#include "dhcp4_parser.h"


// Unqualified %code blocks.
#line 34 "dhcp4_parser.yy"

#include <dhcp4/parser_context.h>

#line 52 "dhcp4_parser.cc"


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
#if PARSER4_DEBUG

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

#else // !PARSER4_DEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !PARSER4_DEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 14 "dhcp4_parser.yy"
namespace isc { namespace dhcp {
#line 145 "dhcp4_parser.cc"

  /// Build a parser object.
  Dhcp4Parser::Dhcp4Parser (isc::dhcp::Parser4Context& ctx_yyarg)
#if PARSER4_DEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      ctx (ctx_yyarg)
  {}

  Dhcp4Parser::~Dhcp4Parser ()
  {}

  Dhcp4Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  Dhcp4Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Dhcp4Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Dhcp4Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Dhcp4Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Dhcp4Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Dhcp4Parser::symbol_kind_type
  Dhcp4Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Dhcp4Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Dhcp4Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_socket_type: // socket_type
      case symbol_kind::S_outbound_interface_value: // outbound_interface_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
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

  Dhcp4Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_socket_type: // socket_type
      case symbol_kind::S_outbound_interface_value: // outbound_interface_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
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
  Dhcp4Parser::stack_symbol_type&
  Dhcp4Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_socket_type: // socket_type
      case symbol_kind::S_outbound_interface_value: // outbound_interface_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
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

  Dhcp4Parser::stack_symbol_type&
  Dhcp4Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
      case symbol_kind::S_socket_type: // socket_type
      case symbol_kind::S_outbound_interface_value: // outbound_interface_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
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
  Dhcp4Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if PARSER4_DEBUG
  template <typename Base>
  void
  Dhcp4Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
#line 290 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 408 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_INTEGER: // "integer"
#line 290 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < int64_t > (); }
#line 414 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_FLOAT: // "floating point"
#line 290 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < double > (); }
#line 420 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
#line 290 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < bool > (); }
#line 426 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_value: // value
#line 290 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 432 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_map_value: // map_value
#line 290 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 438 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
#line 290 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 444 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_socket_type: // socket_type
#line 290 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 450 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_outbound_interface_value: // outbound_interface_value
#line 290 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 456 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_db_type: // db_type
#line 290 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 462 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_on_fail_mode: // on_fail_mode
#line 290 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 468 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_hr_mode: // hr_mode
#line 290 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 474 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
#line 290 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 480 "dhcp4_parser.cc"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  Dhcp4Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Dhcp4Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Dhcp4Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if PARSER4_DEBUG
  std::ostream&
  Dhcp4Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Dhcp4Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Dhcp4Parser::debug_level_type
  Dhcp4Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Dhcp4Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // PARSER4_DEBUG

  Dhcp4Parser::state_type
  Dhcp4Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Dhcp4Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Dhcp4Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Dhcp4Parser::operator() ()
  {
    return parse ();
  }

  int
  Dhcp4Parser::parse ()
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
      case symbol_kind::S_socket_type: // socket_type
      case symbol_kind::S_outbound_interface_value: // outbound_interface_value
      case symbol_kind::S_db_type: // db_type
      case symbol_kind::S_on_fail_mode: // on_fail_mode
      case symbol_kind::S_hr_mode: // hr_mode
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
#line 299 "dhcp4_parser.yy"
                     { ctx.ctx_ = ctx.NO_KEYWORD; }
#line 761 "dhcp4_parser.cc"
    break;

  case 4: // $@2: %empty
#line 300 "dhcp4_parser.yy"
                      { ctx.ctx_ = ctx.CONFIG; }
#line 767 "dhcp4_parser.cc"
    break;

  case 6: // $@3: %empty
#line 301 "dhcp4_parser.yy"
                 { ctx.ctx_ = ctx.DHCP4; }
#line 773 "dhcp4_parser.cc"
    break;

  case 8: // $@4: %empty
#line 302 "dhcp4_parser.yy"
                       { ctx.ctx_ = ctx.INTERFACES_CONFIG; }
#line 779 "dhcp4_parser.cc"
    break;

  case 10: // $@5: %empty
#line 303 "dhcp4_parser.yy"
                   { ctx.ctx_ = ctx.SUBNET4; }
#line 785 "dhcp4_parser.cc"
    break;

  case 12: // $@6: %empty
#line 304 "dhcp4_parser.yy"
                 { ctx.ctx_ = ctx.POOLS; }
#line 791 "dhcp4_parser.cc"
    break;

  case 14: // $@7: %empty
#line 305 "dhcp4_parser.yy"
                       { ctx.ctx_ = ctx.RESERVATIONS; }
#line 797 "dhcp4_parser.cc"
    break;

  case 16: // $@8: %empty
#line 306 "dhcp4_parser.yy"
                       { ctx.ctx_ = ctx.DHCP4; }
#line 803 "dhcp4_parser.cc"
    break;

  case 18: // $@9: %empty
#line 307 "dhcp4_parser.yy"
                      { ctx.ctx_ = ctx.OPTION_DEF; }
#line 809 "dhcp4_parser.cc"
    break;

  case 20: // $@10: %empty
#line 308 "dhcp4_parser.yy"
                       { ctx.ctx_ = ctx.OPTION_DATA; }
#line 815 "dhcp4_parser.cc"
    break;

  case 22: // $@11: %empty
#line 309 "dhcp4_parser.yy"
                         { ctx.ctx_ = ctx.HOOKS_LIBRARIES; }
#line 821 "dhcp4_parser.cc"
    break;

  case 24: // $@12: %empty
#line 310 "dhcp4_parser.yy"
                     { ctx.ctx_ = ctx.DHCP_DDNS; }
#line 827 "dhcp4_parser.cc"
    break;

  case 26: // $@13: %empty
#line 311 "dhcp4_parser.yy"
                          { ctx.ctx_ = ctx.CONFIG_CONTROL; }
#line 833 "dhcp4_parser.cc"
    break;

  case 28: // value: "integer"
#line 319 "dhcp4_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location))); }
#line 839 "dhcp4_parser.cc"
    break;

  case 29: // value: "floating point"
#line 320 "dhcp4_parser.yy"
             { yylhs.value.as < ElementPtr > () = ElementPtr(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location))); }
#line 845 "dhcp4_parser.cc"
    break;

  case 30: // value: "boolean"
#line 321 "dhcp4_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location))); }
#line 851 "dhcp4_parser.cc"
    break;

  case 31: // value: "constant string"
#line 322 "dhcp4_parser.yy"
              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location))); }
#line 857 "dhcp4_parser.cc"
    break;

  case 32: // value: "null"
#line 323 "dhcp4_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new NullElement(ctx.loc2pos(yystack_[0].location))); }
#line 863 "dhcp4_parser.cc"
    break;

  case 33: // value: map2
#line 324 "dhcp4_parser.yy"
            { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 869 "dhcp4_parser.cc"
    break;

  case 34: // value: list_generic
#line 325 "dhcp4_parser.yy"
                    { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 875 "dhcp4_parser.cc"
    break;

  case 35: // sub_json: value
#line 328 "dhcp4_parser.yy"
                {
    // Push back the JSON value on the stack
    ctx.stack_.push_back(yystack_[0].value.as < ElementPtr > ());
}
#line 884 "dhcp4_parser.cc"
    break;

  case 36: // $@14: %empty
#line 333 "dhcp4_parser.yy"
                     {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 895 "dhcp4_parser.cc"
    break;

  case 37: // map2: "{" $@14 map_content "}"
#line 338 "dhcp4_parser.yy"
                             {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.
}
#line 905 "dhcp4_parser.cc"
    break;

  case 38: // map_value: map2
#line 344 "dhcp4_parser.yy"
                { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 911 "dhcp4_parser.cc"
    break;

  case 41: // not_empty_map: "constant string" ":" value
#line 351 "dhcp4_parser.yy"
                                  {
                  // map containing a single entry
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 921 "dhcp4_parser.cc"
    break;

  case 42: // not_empty_map: not_empty_map "," "constant string" ":" value
#line 356 "dhcp4_parser.yy"
                                                      {
                  // map consisting of a shorter map followed by
                  // comma and string:value
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 932 "dhcp4_parser.cc"
    break;

  case 43: // not_empty_map: not_empty_map ","
#line 362 "dhcp4_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 940 "dhcp4_parser.cc"
    break;

  case 44: // $@15: %empty
#line 367 "dhcp4_parser.yy"
                              {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 949 "dhcp4_parser.cc"
    break;

  case 45: // list_generic: "[" $@15 list_content "]"
#line 370 "dhcp4_parser.yy"
                               {
    // list parsing complete. Put any sanity checking here
}
#line 957 "dhcp4_parser.cc"
    break;

  case 48: // not_empty_list: value
#line 378 "dhcp4_parser.yy"
                      {
                  // List consisting of a single element.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 966 "dhcp4_parser.cc"
    break;

  case 49: // not_empty_list: not_empty_list "," value
#line 382 "dhcp4_parser.yy"
                                           {
                  // List ending with , and a value.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 975 "dhcp4_parser.cc"
    break;

  case 50: // not_empty_list: not_empty_list ","
#line 386 "dhcp4_parser.yy"
                                     {
                  ctx.warnAboutExtraCommas(yystack_[0].location);
                  }
#line 983 "dhcp4_parser.cc"
    break;

  case 51: // $@16: %empty
#line 392 "dhcp4_parser.yy"
                              {
    // List parsing about to start
}
#line 991 "dhcp4_parser.cc"
    break;

  case 52: // list_strings: "[" $@16 list_strings_content "]"
#line 394 "dhcp4_parser.yy"
                                       {
    // list parsing complete. Put any sanity checking here
    //ctx.stack_.pop_back();
}
#line 1000 "dhcp4_parser.cc"
    break;

  case 55: // not_empty_list_strings: "constant string"
#line 403 "dhcp4_parser.yy"
                               {
                          ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
                          ctx.stack_.back()->add(s);
                          }
#line 1009 "dhcp4_parser.cc"
    break;

  case 56: // not_empty_list_strings: not_empty_list_strings "," "constant string"
#line 407 "dhcp4_parser.yy"
                                                            {
                          ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
                          ctx.stack_.back()->add(s);
                          }
#line 1018 "dhcp4_parser.cc"
    break;

  case 57: // not_empty_list_strings: not_empty_list_strings ","
#line 411 "dhcp4_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 1026 "dhcp4_parser.cc"
    break;

  case 58: // unknown_map_entry: "constant string" ":"
#line 421 "dhcp4_parser.yy"
                                {
    const std::string& where = ctx.contextName();
    const std::string& keyword = yystack_[1].value.as < std::string > ();
    error(yystack_[1].location,
          "got unexpected keyword \"" + keyword + "\" in " + where + " map.");
}
#line 1037 "dhcp4_parser.cc"
    break;

  case 59: // $@17: %empty
#line 430 "dhcp4_parser.yy"
                           {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1048 "dhcp4_parser.cc"
    break;

  case 60: // syntax_map: "{" $@17 global_object "}"
#line 435 "dhcp4_parser.yy"
                               {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.

    // Dhcp4 is required
    ctx.require("Dhcp4", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
}
#line 1061 "dhcp4_parser.cc"
    break;

  case 61: // $@18: %empty
#line 445 "dhcp4_parser.yy"
                     {
    // This code is executed when we're about to start parsing
    // the content of the map
    // Prevent against duplicate.
    ctx.unique("Dhcp4", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("Dhcp4", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.DHCP4);
}
#line 1076 "dhcp4_parser.cc"
    break;

  case 62: // global_object: "Dhcp4" $@18 ":" "{" global_params "}"
#line 454 "dhcp4_parser.yy"
                                                    {
    // No global parameter is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1086 "dhcp4_parser.cc"
    break;

  case 64: // global_object_comma: global_object ","
#line 462 "dhcp4_parser.yy"
                                         {
    ctx.warnAboutExtraCommas(yystack_[0].location);
}
#line 1094 "dhcp4_parser.cc"
    break;

  case 65: // $@19: %empty
#line 468 "dhcp4_parser.yy"
                          {
    // Parse the Dhcp4 map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1104 "dhcp4_parser.cc"
    break;

  case 66: // sub_dhcp4: "{" $@19 global_params "}"
#line 472 "dhcp4_parser.yy"
                               {
    // No global parameter is required
    // parsing completed
}
#line 1113 "dhcp4_parser.cc"
    break;

  case 69: // global_params: global_params ","
#line 479 "dhcp4_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 1121 "dhcp4_parser.cc"
    break;

  case 134: // valid_lifetime: "valid-lifetime" ":" "integer"
#line 552 "dhcp4_parser.yy"
                                             {
    ctx.unique("valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("valid-lifetime", prf);
}
#line 1131 "dhcp4_parser.cc"
    break;

  case 135: // min_valid_lifetime: "min-valid-lifetime" ":" "integer"
#line 558 "dhcp4_parser.yy"
                                                     {
    ctx.unique("min-valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("min-valid-lifetime", prf);
}
#line 1141 "dhcp4_parser.cc"
    break;

  case 136: // max_valid_lifetime: "max-valid-lifetime" ":" "integer"
#line 564 "dhcp4_parser.yy"
                                                     {
    ctx.unique("max-valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-valid-lifetime", prf);
}
#line 1151 "dhcp4_parser.cc"
    break;

  case 137: // renew_timer: "renew-timer" ":" "integer"
#line 570 "dhcp4_parser.yy"
                                       {
    ctx.unique("renew-timer", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("renew-timer", prf);
}
#line 1161 "dhcp4_parser.cc"
    break;

  case 138: // rebind_timer: "rebind-timer" ":" "integer"
#line 576 "dhcp4_parser.yy"
                                         {
    ctx.unique("rebind-timer", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("rebind-timer", prf);
}
#line 1171 "dhcp4_parser.cc"
    break;

  case 139: // calculate_tee_times: "calculate-tee-times" ":" "boolean"
#line 582 "dhcp4_parser.yy"
                                                       {
    ctx.unique("calculate-tee-times", ctx.loc2pos(yystack_[2].location));
    ElementPtr ctt(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("calculate-tee-times", ctt);
}
#line 1181 "dhcp4_parser.cc"
    break;

  case 140: // t1_percent: "t1-percent" ":" "floating point"
#line 588 "dhcp4_parser.yy"
                                   {
    ctx.unique("t1-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr t1(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("t1-percent", t1);
}
#line 1191 "dhcp4_parser.cc"
    break;

  case 141: // t2_percent: "t2-percent" ":" "floating point"
#line 594 "dhcp4_parser.yy"
                                   {
    ctx.unique("t2-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr t2(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("t2-percent", t2);
}
#line 1201 "dhcp4_parser.cc"
    break;

  case 142: // cache_threshold: "cache-threshold" ":" "floating point"
#line 600 "dhcp4_parser.yy"
                                             {
    ctx.unique("cache-threshold", ctx.loc2pos(yystack_[2].location));
    ElementPtr ct(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cache-threshold", ct);
}
#line 1211 "dhcp4_parser.cc"
    break;

  case 143: // cache_max_age: "cache-max-age" ":" "integer"
#line 606 "dhcp4_parser.yy"
                                           {
    ctx.unique("cache-max-age", ctx.loc2pos(yystack_[2].location));
    ElementPtr cm(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cache-max-age", cm);
}
#line 1221 "dhcp4_parser.cc"
    break;

  case 144: // decline_probation_period: "decline-probation-period" ":" "integer"
#line 612 "dhcp4_parser.yy"
                                                                 {
    ctx.unique("decline-probation-period", ctx.loc2pos(yystack_[2].location));
    ElementPtr dpp(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("decline-probation-period", dpp);
}
#line 1231 "dhcp4_parser.cc"
    break;

  case 145: // $@20: %empty
#line 618 "dhcp4_parser.yy"
                       {
    ctx.unique("server-tag", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1240 "dhcp4_parser.cc"
    break;

  case 146: // server_tag: "server-tag" $@20 ":" "constant string"
#line 621 "dhcp4_parser.yy"
               {
    ElementPtr stag(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-tag", stag);
    ctx.leave();
}
#line 1250 "dhcp4_parser.cc"
    break;

  case 147: // parked_packet_limit: "parked-packet-limit" ":" "integer"
#line 627 "dhcp4_parser.yy"
                                                       {
    ctx.unique("parked-packet-limit", ctx.loc2pos(yystack_[2].location));
    ElementPtr ppl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("parked-packet-limit", ppl);
}
#line 1260 "dhcp4_parser.cc"
    break;

  case 148: // echo_client_id: "echo-client-id" ":" "boolean"
#line 633 "dhcp4_parser.yy"
                                             {
    ctx.unique("echo-client-id", ctx.loc2pos(yystack_[2].location));
    ElementPtr echo(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("echo-client-id", echo);
}
#line 1270 "dhcp4_parser.cc"
    break;

  case 149: // match_client_id: "match-client-id" ":" "boolean"
#line 639 "dhcp4_parser.yy"
                                               {
    ctx.unique("match-client-id", ctx.loc2pos(yystack_[2].location));
    ElementPtr match(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("match-client-id", match);
}
#line 1280 "dhcp4_parser.cc"
    break;

  case 150: // authoritative: "authoritative" ":" "boolean"
#line 645 "dhcp4_parser.yy"
                                           {
    ctx.unique("authoritative", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("authoritative", prf);
}
#line 1290 "dhcp4_parser.cc"
    break;

  case 151: // ddns_send_updates: "ddns-send-updates" ":" "boolean"
#line 651 "dhcp4_parser.yy"
                                                   {
    ctx.unique("ddns-send-updates", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-send-updates", b);
}
#line 1300 "dhcp4_parser.cc"
    break;

  case 152: // ddns_override_no_update: "ddns-override-no-update" ":" "boolean"
#line 657 "dhcp4_parser.yy"
                                                               {
    ctx.unique("ddns-override-no-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-override-no-update", b);
}
#line 1310 "dhcp4_parser.cc"
    break;

  case 153: // ddns_override_client_update: "ddns-override-client-update" ":" "boolean"
#line 663 "dhcp4_parser.yy"
                                                                       {
    ctx.unique("ddns-override-client-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-override-client-update", b);
}
#line 1320 "dhcp4_parser.cc"
    break;

  case 154: // $@21: %empty
#line 669 "dhcp4_parser.yy"
                                                   {
    ctx.enter(ctx.REPLACE_CLIENT_NAME);
    ctx.unique("ddns-replace-client-name", ctx.loc2pos(yystack_[0].location));
}
#line 1329 "dhcp4_parser.cc"
    break;

  case 155: // ddns_replace_client_name: "ddns-replace-client-name" $@21 ":" ddns_replace_client_name_value
#line 672 "dhcp4_parser.yy"
                                       {
    ctx.stack_.back()->set("ddns-replace-client-name", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1338 "dhcp4_parser.cc"
    break;

  case 156: // ddns_replace_client_name_value: "when-present"
#line 678 "dhcp4_parser.yy"
                 {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("when-present", ctx.loc2pos(yystack_[0].location)));
      }
#line 1346 "dhcp4_parser.cc"
    break;

  case 157: // ddns_replace_client_name_value: "never"
#line 681 "dhcp4_parser.yy"
          {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("never", ctx.loc2pos(yystack_[0].location)));
      }
#line 1354 "dhcp4_parser.cc"
    break;

  case 158: // ddns_replace_client_name_value: "always"
#line 684 "dhcp4_parser.yy"
           {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("always", ctx.loc2pos(yystack_[0].location)));
      }
#line 1362 "dhcp4_parser.cc"
    break;

  case 159: // ddns_replace_client_name_value: "when-not-present"
#line 687 "dhcp4_parser.yy"
                     {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("when-not-present", ctx.loc2pos(yystack_[0].location)));
      }
#line 1370 "dhcp4_parser.cc"
    break;

  case 160: // ddns_replace_client_name_value: "boolean"
#line 690 "dhcp4_parser.yy"
            {
      error(yystack_[0].location, "boolean values for the replace-client-name are "
                "no longer supported");
      }
#line 1379 "dhcp4_parser.cc"
    break;

  case 161: // $@22: %empty
#line 696 "dhcp4_parser.yy"
                                             {
    ctx.unique("ddns-generated-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1388 "dhcp4_parser.cc"
    break;

  case 162: // ddns_generated_prefix: "ddns-generated-prefix" $@22 ":" "constant string"
#line 699 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-generated-prefix", s);
    ctx.leave();
}
#line 1398 "dhcp4_parser.cc"
    break;

  case 163: // $@23: %empty
#line 705 "dhcp4_parser.yy"
                                               {
    ctx.unique("ddns-qualifying-suffix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1407 "dhcp4_parser.cc"
    break;

  case 164: // ddns_qualifying_suffix: "ddns-qualifying-suffix" $@23 ":" "constant string"
#line 708 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-qualifying-suffix", s);
    ctx.leave();
}
#line 1417 "dhcp4_parser.cc"
    break;

  case 165: // ddns_update_on_renew: "ddns-update-on-renew" ":" "boolean"
#line 714 "dhcp4_parser.yy"
                                                         {
    ctx.unique("ddns-update-on-renew", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-update-on-renew", b);
}
#line 1427 "dhcp4_parser.cc"
    break;

  case 166: // ddns_use_conflict_resolution: "ddns-use-conflict-resolution" ":" "boolean"
#line 720 "dhcp4_parser.yy"
                                                                         {
    ctx.unique("ddns-use-conflict-resolution", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-use-conflict-resolution", b);
}
#line 1437 "dhcp4_parser.cc"
    break;

  case 167: // $@24: %empty
#line 726 "dhcp4_parser.yy"
                                     {
    ctx.unique("hostname-char-set", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1446 "dhcp4_parser.cc"
    break;

  case 168: // hostname_char_set: "hostname-char-set" $@24 ":" "constant string"
#line 729 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-set", s);
    ctx.leave();
}
#line 1456 "dhcp4_parser.cc"
    break;

  case 169: // $@25: %empty
#line 735 "dhcp4_parser.yy"
                                                     {
    ctx.unique("hostname-char-replacement", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1465 "dhcp4_parser.cc"
    break;

  case 170: // hostname_char_replacement: "hostname-char-replacement" $@25 ":" "constant string"
#line 738 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-replacement", s);
    ctx.leave();
}
#line 1475 "dhcp4_parser.cc"
    break;

  case 171: // store_extended_info: "store-extended-info" ":" "boolean"
#line 744 "dhcp4_parser.yy"
                                                       {
    ctx.unique("store-extended-info", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("store-extended-info", b);
}
#line 1485 "dhcp4_parser.cc"
    break;

  case 172: // statistic_default_sample_count: "statistic-default-sample-count" ":" "integer"
#line 750 "dhcp4_parser.yy"
                                                                             {
    ctx.unique("statistic-default-sample-count", ctx.loc2pos(yystack_[2].location));
    ElementPtr count(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("statistic-default-sample-count", count);
}
#line 1495 "dhcp4_parser.cc"
    break;

  case 173: // statistic_default_sample_age: "statistic-default-sample-age" ":" "integer"
#line 756 "dhcp4_parser.yy"
                                                                         {
    ctx.unique("statistic-default-sample-age", ctx.loc2pos(yystack_[2].location));
    ElementPtr age(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("statistic-default-sample-age", age);
}
#line 1505 "dhcp4_parser.cc"
    break;

  case 174: // early_global_reservations_lookup: "early-global-reservations-lookup" ":" "boolean"
#line 762 "dhcp4_parser.yy"
                                                                                 {
    ctx.unique("early-global-reservations-lookup", ctx.loc2pos(yystack_[2].location));
    ElementPtr early(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("early-global-reservations-lookup", early);
}
#line 1515 "dhcp4_parser.cc"
    break;

  case 175: // ip_reservations_unique: "ip-reservations-unique" ":" "boolean"
#line 768 "dhcp4_parser.yy"
                                                             {
    ctx.unique("ip-reservations-unique", ctx.loc2pos(yystack_[2].location));
    ElementPtr unique(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-reservations-unique", unique);
}
#line 1525 "dhcp4_parser.cc"
    break;

  case 176: // reservations_lookup_first: "reservations-lookup-first" ":" "boolean"
#line 774 "dhcp4_parser.yy"
                                                                   {
    ctx.unique("reservations-lookup-first", ctx.loc2pos(yystack_[2].location));
    ElementPtr first(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-lookup-first", first);
}
#line 1535 "dhcp4_parser.cc"
    break;

  case 177: // $@26: %empty
#line 780 "dhcp4_parser.yy"
                                     {
    ctx.unique("interfaces-config", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interfaces-config", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.INTERFACES_CONFIG);
}
#line 1547 "dhcp4_parser.cc"
    break;

  case 178: // interfaces_config: "interfaces-config" $@26 ":" "{" interfaces_config_params "}"
#line 786 "dhcp4_parser.yy"
                                                               {
    // No interfaces config param is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1557 "dhcp4_parser.cc"
    break;

  case 181: // interfaces_config_params: interfaces_config_params ","
#line 794 "dhcp4_parser.yy"
                                                         {
                            ctx.warnAboutExtraCommas(yystack_[0].location);
                            }
#line 1565 "dhcp4_parser.cc"
    break;

  case 192: // $@27: %empty
#line 811 "dhcp4_parser.yy"
                                {
    // Parse the interfaces-config map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1575 "dhcp4_parser.cc"
    break;

  case 193: // sub_interfaces4: "{" $@27 interfaces_config_params "}"
#line 815 "dhcp4_parser.yy"
                                          {
    // No interfaces config param is required
    // parsing completed
}
#line 1584 "dhcp4_parser.cc"
    break;

  case 194: // $@28: %empty
#line 820 "dhcp4_parser.yy"
                            {
    ctx.unique("interfaces", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interfaces", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1596 "dhcp4_parser.cc"
    break;

  case 195: // interfaces_list: "interfaces" $@28 ":" list_strings
#line 826 "dhcp4_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1605 "dhcp4_parser.cc"
    break;

  case 196: // $@29: %empty
#line 831 "dhcp4_parser.yy"
                                   {
    ctx.unique("dhcp-socket-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DHCP_SOCKET_TYPE);
}
#line 1614 "dhcp4_parser.cc"
    break;

  case 197: // dhcp_socket_type: "dhcp-socket-type" $@29 ":" socket_type
#line 834 "dhcp4_parser.yy"
                    {
    ctx.stack_.back()->set("dhcp-socket-type", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1623 "dhcp4_parser.cc"
    break;

  case 198: // socket_type: "raw"
#line 839 "dhcp4_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("raw", ctx.loc2pos(yystack_[0].location))); }
#line 1629 "dhcp4_parser.cc"
    break;

  case 199: // socket_type: "udp"
#line 840 "dhcp4_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("udp", ctx.loc2pos(yystack_[0].location))); }
#line 1635 "dhcp4_parser.cc"
    break;

  case 200: // $@30: %empty
#line 843 "dhcp4_parser.yy"
                                       {
    ctx.unique("outbound-interface", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.OUTBOUND_INTERFACE);
}
#line 1644 "dhcp4_parser.cc"
    break;

  case 201: // outbound_interface: "outbound-interface" $@30 ":" outbound_interface_value
#line 846 "dhcp4_parser.yy"
                                 {
    ctx.stack_.back()->set("outbound-interface", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1653 "dhcp4_parser.cc"
    break;

  case 202: // outbound_interface_value: "same-as-inbound"
#line 851 "dhcp4_parser.yy"
                                          {
    yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("same-as-inbound", ctx.loc2pos(yystack_[0].location)));
}
#line 1661 "dhcp4_parser.cc"
    break;

  case 203: // outbound_interface_value: "use-routing"
#line 853 "dhcp4_parser.yy"
                {
    yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("use-routing", ctx.loc2pos(yystack_[0].location)));
    }
#line 1669 "dhcp4_parser.cc"
    break;

  case 204: // re_detect: "re-detect" ":" "boolean"
#line 857 "dhcp4_parser.yy"
                                   {
    ctx.unique("re-detect", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("re-detect", b);
}
#line 1679 "dhcp4_parser.cc"
    break;

  case 205: // service_sockets_require_all: "service-sockets-require-all" ":" "boolean"
#line 863 "dhcp4_parser.yy"
                                                                       {
    ctx.unique("service-sockets-require-all", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-require-all", b);
}
#line 1689 "dhcp4_parser.cc"
    break;

  case 206: // service_sockets_retry_wait_time: "service-sockets-retry-wait-time" ":" "integer"
#line 869 "dhcp4_parser.yy"
                                                                               {
    ctx.unique("service-sockets-retry-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-retry-wait-time", n);
}
#line 1699 "dhcp4_parser.cc"
    break;

  case 207: // service_sockets_max_retries: "service-sockets-max-retries" ":" "integer"
#line 875 "dhcp4_parser.yy"
                                                                       {
    ctx.unique("service-sockets-max-retries", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-max-retries", n);
}
#line 1709 "dhcp4_parser.cc"
    break;

  case 208: // $@31: %empty
#line 881 "dhcp4_parser.yy"
                               {
    ctx.unique("lease-database", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lease-database", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.LEASE_DATABASE);
}
#line 1721 "dhcp4_parser.cc"
    break;

  case 209: // lease_database: "lease-database" $@31 ":" "{" database_map_params "}"
#line 887 "dhcp4_parser.yy"
                                                          {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1732 "dhcp4_parser.cc"
    break;

  case 210: // $@32: %empty
#line 894 "dhcp4_parser.yy"
                             {
    ctx.unique("sanity-checks", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sanity-checks", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.SANITY_CHECKS);
}
#line 1744 "dhcp4_parser.cc"
    break;

  case 211: // sanity_checks: "sanity-checks" $@32 ":" "{" sanity_checks_params "}"
#line 900 "dhcp4_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1753 "dhcp4_parser.cc"
    break;

  case 214: // sanity_checks_params: sanity_checks_params ","
#line 907 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 1761 "dhcp4_parser.cc"
    break;

  case 217: // $@33: %empty
#line 916 "dhcp4_parser.yy"
                           {
    ctx.unique("lease-checks", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1770 "dhcp4_parser.cc"
    break;

  case 218: // lease_checks: "lease-checks" $@33 ":" "constant string"
#line 919 "dhcp4_parser.yy"
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
#line 1790 "dhcp4_parser.cc"
    break;

  case 219: // $@34: %empty
#line 935 "dhcp4_parser.yy"
                                           {
    ctx.unique("extended-info-checks", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1799 "dhcp4_parser.cc"
    break;

  case 220: // extended_info_checks: "extended-info-checks" $@34 ":" "constant string"
#line 938 "dhcp4_parser.yy"
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
#line 1818 "dhcp4_parser.cc"
    break;

  case 221: // $@35: %empty
#line 953 "dhcp4_parser.yy"
                               {
    ctx.unique("hosts-database", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hosts-database", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.HOSTS_DATABASE);
}
#line 1830 "dhcp4_parser.cc"
    break;

  case 222: // hosts_database: "hosts-database" $@35 ":" "{" database_map_params "}"
#line 959 "dhcp4_parser.yy"
                                                          {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1841 "dhcp4_parser.cc"
    break;

  case 223: // $@36: %empty
#line 966 "dhcp4_parser.yy"
                                 {
    ctx.unique("hosts-databases", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hosts-databases", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOSTS_DATABASE);
}
#line 1853 "dhcp4_parser.cc"
    break;

  case 224: // hosts_databases: "hosts-databases" $@36 ":" "[" database_list "]"
#line 972 "dhcp4_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1862 "dhcp4_parser.cc"
    break;

  case 229: // not_empty_database_list: not_empty_database_list ","
#line 983 "dhcp4_parser.yy"
                                                       {
                           ctx.warnAboutExtraCommas(yystack_[0].location);
                           }
#line 1870 "dhcp4_parser.cc"
    break;

  case 230: // $@37: %empty
#line 988 "dhcp4_parser.yy"
                         {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1880 "dhcp4_parser.cc"
    break;

  case 231: // database: "{" $@37 database_map_params "}"
#line 992 "dhcp4_parser.yy"
                                     {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 1890 "dhcp4_parser.cc"
    break;

  case 234: // database_map_params: database_map_params ","
#line 1000 "dhcp4_parser.yy"
                                               {
                       ctx.warnAboutExtraCommas(yystack_[0].location);
                       }
#line 1898 "dhcp4_parser.cc"
    break;

  case 254: // $@38: %empty
#line 1026 "dhcp4_parser.yy"
                    {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DATABASE_TYPE);
}
#line 1907 "dhcp4_parser.cc"
    break;

  case 255: // database_type: "type" $@38 ":" db_type
#line 1029 "dhcp4_parser.yy"
                {
    ctx.stack_.back()->set("type", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1916 "dhcp4_parser.cc"
    break;

  case 256: // db_type: "memfile"
#line 1034 "dhcp4_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("memfile", ctx.loc2pos(yystack_[0].location))); }
#line 1922 "dhcp4_parser.cc"
    break;

  case 257: // db_type: "mysql"
#line 1035 "dhcp4_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("mysql", ctx.loc2pos(yystack_[0].location))); }
#line 1928 "dhcp4_parser.cc"
    break;

  case 258: // db_type: "postgresql"
#line 1036 "dhcp4_parser.yy"
                    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("postgresql", ctx.loc2pos(yystack_[0].location))); }
#line 1934 "dhcp4_parser.cc"
    break;

  case 259: // $@39: %empty
#line 1039 "dhcp4_parser.yy"
           {
    ctx.unique("user", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1943 "dhcp4_parser.cc"
    break;

  case 260: // user: "user" $@39 ":" "constant string"
#line 1042 "dhcp4_parser.yy"
               {
    ElementPtr user(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("user", user);
    ctx.leave();
}
#line 1953 "dhcp4_parser.cc"
    break;

  case 261: // $@40: %empty
#line 1048 "dhcp4_parser.yy"
                   {
    ctx.unique("password", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1962 "dhcp4_parser.cc"
    break;

  case 262: // password: "password" $@40 ":" "constant string"
#line 1051 "dhcp4_parser.yy"
               {
    ElementPtr pwd(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("password", pwd);
    ctx.leave();
}
#line 1972 "dhcp4_parser.cc"
    break;

  case 263: // $@41: %empty
#line 1057 "dhcp4_parser.yy"
           {
    ctx.unique("host", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1981 "dhcp4_parser.cc"
    break;

  case 264: // host: "host" $@41 ":" "constant string"
#line 1060 "dhcp4_parser.yy"
               {
    ElementPtr h(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("host", h);
    ctx.leave();
}
#line 1991 "dhcp4_parser.cc"
    break;

  case 265: // port: "port" ":" "integer"
#line 1066 "dhcp4_parser.yy"
                         {
    ctx.unique("port", ctx.loc2pos(yystack_[2].location));
    ElementPtr p(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("port", p);
}
#line 2001 "dhcp4_parser.cc"
    break;

  case 266: // $@42: %empty
#line 1072 "dhcp4_parser.yy"
           {
    ctx.unique("name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2010 "dhcp4_parser.cc"
    break;

  case 267: // name: "name" $@42 ":" "constant string"
#line 1075 "dhcp4_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("name", name);
    ctx.leave();
}
#line 2020 "dhcp4_parser.cc"
    break;

  case 268: // persist: "persist" ":" "boolean"
#line 1081 "dhcp4_parser.yy"
                               {
    ctx.unique("persist", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("persist", n);
}
#line 2030 "dhcp4_parser.cc"
    break;

  case 269: // lfc_interval: "lfc-interval" ":" "integer"
#line 1087 "dhcp4_parser.yy"
                                         {
    ctx.unique("lfc-interval", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lfc-interval", n);
}
#line 2040 "dhcp4_parser.cc"
    break;

  case 270: // readonly: "readonly" ":" "boolean"
#line 1093 "dhcp4_parser.yy"
                                 {
    ctx.unique("readonly", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("readonly", n);
}
#line 2050 "dhcp4_parser.cc"
    break;

  case 271: // connect_timeout: "connect-timeout" ":" "integer"
#line 1099 "dhcp4_parser.yy"
                                               {
    ctx.unique("connect-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("connect-timeout", n);
}
#line 2060 "dhcp4_parser.cc"
    break;

  case 272: // max_reconnect_tries: "max-reconnect-tries" ":" "integer"
#line 1105 "dhcp4_parser.yy"
                                                       {
    ctx.unique("max-reconnect-tries", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reconnect-tries", n);
}
#line 2070 "dhcp4_parser.cc"
    break;

  case 273: // reconnect_wait_time: "reconnect-wait-time" ":" "integer"
#line 1111 "dhcp4_parser.yy"
                                                       {
    ctx.unique("reconnect-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reconnect-wait-time", n);
}
#line 2080 "dhcp4_parser.cc"
    break;

  case 274: // $@43: %empty
#line 1117 "dhcp4_parser.yy"
                 {
    ctx.unique("on-fail", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DATABASE_ON_FAIL);
}
#line 2089 "dhcp4_parser.cc"
    break;

  case 275: // on_fail: "on-fail" $@43 ":" on_fail_mode
#line 1120 "dhcp4_parser.yy"
                     {
    ctx.stack_.back()->set("on-fail", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2098 "dhcp4_parser.cc"
    break;

  case 276: // on_fail_mode: "stop-retry-exit"
#line 1125 "dhcp4_parser.yy"
                              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("stop-retry-exit", ctx.loc2pos(yystack_[0].location))); }
#line 2104 "dhcp4_parser.cc"
    break;

  case 277: // on_fail_mode: "serve-retry-exit"
#line 1126 "dhcp4_parser.yy"
                               { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("serve-retry-exit", ctx.loc2pos(yystack_[0].location))); }
#line 2110 "dhcp4_parser.cc"
    break;

  case 278: // on_fail_mode: "serve-retry-continue"
#line 1127 "dhcp4_parser.yy"
                                   { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("serve-retry-continue", ctx.loc2pos(yystack_[0].location))); }
#line 2116 "dhcp4_parser.cc"
    break;

  case 279: // max_row_errors: "max-row-errors" ":" "integer"
#line 1130 "dhcp4_parser.yy"
                                             {
    ctx.unique("max-row-errors", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-row-errors", n);
}
#line 2126 "dhcp4_parser.cc"
    break;

  case 280: // $@44: %empty
#line 1136 "dhcp4_parser.yy"
                           {
    ctx.unique("trust-anchor", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2135 "dhcp4_parser.cc"
    break;

  case 281: // trust_anchor: "trust-anchor" $@44 ":" "constant string"
#line 1139 "dhcp4_parser.yy"
               {
    ElementPtr ca(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("trust-anchor", ca);
    ctx.leave();
}
#line 2145 "dhcp4_parser.cc"
    break;

  case 282: // $@45: %empty
#line 1145 "dhcp4_parser.yy"
                     {
    ctx.unique("cert-file", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2154 "dhcp4_parser.cc"
    break;

  case 283: // cert_file: "cert-file" $@45 ":" "constant string"
#line 1148 "dhcp4_parser.yy"
               {
    ElementPtr cert(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cert-file", cert);
    ctx.leave();
}
#line 2164 "dhcp4_parser.cc"
    break;

  case 284: // $@46: %empty
#line 1154 "dhcp4_parser.yy"
                   {
    ctx.unique("key-file", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2173 "dhcp4_parser.cc"
    break;

  case 285: // key_file: "key-file" $@46 ":" "constant string"
#line 1157 "dhcp4_parser.yy"
               {
    ElementPtr key(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("key-file", key);
    ctx.leave();
}
#line 2183 "dhcp4_parser.cc"
    break;

  case 286: // $@47: %empty
#line 1163 "dhcp4_parser.yy"
                         {
    ctx.unique("cipher-list", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2192 "dhcp4_parser.cc"
    break;

  case 287: // cipher_list: "cipher-list" $@47 ":" "constant string"
#line 1166 "dhcp4_parser.yy"
               {
    ElementPtr cl(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cipher-list", cl);
    ctx.leave();
}
#line 2202 "dhcp4_parser.cc"
    break;

  case 288: // $@48: %empty
#line 1172 "dhcp4_parser.yy"
                                                           {
    ctx.unique("host-reservation-identifiers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("host-reservation-identifiers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOST_RESERVATION_IDENTIFIERS);
}
#line 2214 "dhcp4_parser.cc"
    break;

  case 289: // host_reservation_identifiers: "host-reservation-identifiers" $@48 ":" "[" host_reservation_identifiers_list "]"
#line 1178 "dhcp4_parser.yy"
                                                                          {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2223 "dhcp4_parser.cc"
    break;

  case 292: // host_reservation_identifiers_list: host_reservation_identifiers_list ","
#line 1185 "dhcp4_parser.yy"
                                              {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 2231 "dhcp4_parser.cc"
    break;

  case 298: // duid_id: "duid"
#line 1197 "dhcp4_parser.yy"
              {
    ElementPtr duid(new StringElement("duid", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(duid);
}
#line 2240 "dhcp4_parser.cc"
    break;

  case 299: // hw_address_id: "hw-address"
#line 1202 "dhcp4_parser.yy"
                          {
    ElementPtr hwaddr(new StringElement("hw-address", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(hwaddr);
}
#line 2249 "dhcp4_parser.cc"
    break;

  case 300: // circuit_id: "circuit-id"
#line 1207 "dhcp4_parser.yy"
                       {
    ElementPtr circuit(new StringElement("circuit-id", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(circuit);
}
#line 2258 "dhcp4_parser.cc"
    break;

  case 301: // client_id: "client-id"
#line 1212 "dhcp4_parser.yy"
                     {
    ElementPtr client(new StringElement("client-id", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(client);
}
#line 2267 "dhcp4_parser.cc"
    break;

  case 302: // flex_id: "flex-id"
#line 1217 "dhcp4_parser.yy"
                 {
    ElementPtr flex_id(new StringElement("flex-id", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(flex_id);
}
#line 2276 "dhcp4_parser.cc"
    break;

  case 303: // $@49: %empty
#line 1224 "dhcp4_parser.yy"
                                           {
    ctx.unique("multi-threading", ctx.loc2pos(yystack_[0].location));
    ElementPtr mt(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("multi-threading", mt);
    ctx.stack_.push_back(mt);
    ctx.enter(ctx.DHCP_MULTI_THREADING);
}
#line 2288 "dhcp4_parser.cc"
    break;

  case 304: // dhcp_multi_threading: "multi-threading" $@49 ":" "{" multi_threading_params "}"
#line 1230 "dhcp4_parser.yy"
                                                             {
    // The enable parameter is required.
    ctx.require("enable-multi-threading", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2299 "dhcp4_parser.cc"
    break;

  case 307: // multi_threading_params: multi_threading_params ","
#line 1239 "dhcp4_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 2307 "dhcp4_parser.cc"
    break;

  case 314: // enable_multi_threading: "enable-multi-threading" ":" "boolean"
#line 1252 "dhcp4_parser.yy"
                                                             {
    ctx.unique("enable-multi-threading", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-multi-threading", b);
}
#line 2317 "dhcp4_parser.cc"
    break;

  case 315: // thread_pool_size: "thread-pool-size" ":" "integer"
#line 1258 "dhcp4_parser.yy"
                                                 {
    ctx.unique("thread-pool-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("thread-pool-size", prf);
}
#line 2327 "dhcp4_parser.cc"
    break;

  case 316: // packet_queue_size: "packet-queue-size" ":" "integer"
#line 1264 "dhcp4_parser.yy"
                                                   {
    ctx.unique("packet-queue-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("packet-queue-size", prf);
}
#line 2337 "dhcp4_parser.cc"
    break;

  case 317: // $@50: %empty
#line 1270 "dhcp4_parser.yy"
                                 {
    ctx.unique("hooks-libraries", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hooks-libraries", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOOKS_LIBRARIES);
}
#line 2349 "dhcp4_parser.cc"
    break;

  case 318: // hooks_libraries: "hooks-libraries" $@50 ":" "[" hooks_libraries_list "]"
#line 1276 "dhcp4_parser.yy"
                                                             {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2358 "dhcp4_parser.cc"
    break;

  case 323: // not_empty_hooks_libraries_list: not_empty_hooks_libraries_list ","
#line 1287 "dhcp4_parser.yy"
                                           {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 2366 "dhcp4_parser.cc"
    break;

  case 324: // $@51: %empty
#line 1292 "dhcp4_parser.yy"
                              {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2376 "dhcp4_parser.cc"
    break;

  case 325: // hooks_library: "{" $@51 hooks_params "}"
#line 1296 "dhcp4_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2386 "dhcp4_parser.cc"
    break;

  case 326: // $@52: %empty
#line 1302 "dhcp4_parser.yy"
                                  {
    // Parse the hooks-libraries list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2396 "dhcp4_parser.cc"
    break;

  case 327: // sub_hooks_library: "{" $@52 hooks_params "}"
#line 1306 "dhcp4_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2406 "dhcp4_parser.cc"
    break;

  case 330: // hooks_params: hooks_params ","
#line 1314 "dhcp4_parser.yy"
                                 {
                ctx.warnAboutExtraCommas(yystack_[0].location);
                }
#line 2414 "dhcp4_parser.cc"
    break;

  case 334: // $@53: %empty
#line 1324 "dhcp4_parser.yy"
                 {
    ctx.unique("library", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2423 "dhcp4_parser.cc"
    break;

  case 335: // library: "library" $@53 ":" "constant string"
#line 1327 "dhcp4_parser.yy"
               {
    ElementPtr lib(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("library", lib);
    ctx.leave();
}
#line 2433 "dhcp4_parser.cc"
    break;

  case 336: // $@54: %empty
#line 1333 "dhcp4_parser.yy"
                       {
    ctx.unique("parameters", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2442 "dhcp4_parser.cc"
    break;

  case 337: // parameters: "parameters" $@54 ":" map_value
#line 1336 "dhcp4_parser.yy"
                  {
    ctx.stack_.back()->set("parameters", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2451 "dhcp4_parser.cc"
    break;

  case 338: // $@55: %empty
#line 1342 "dhcp4_parser.yy"
                                                     {
    ctx.unique("expired-leases-processing", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("expired-leases-processing", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.EXPIRED_LEASES_PROCESSING);
}
#line 2463 "dhcp4_parser.cc"
    break;

  case 339: // expired_leases_processing: "expired-leases-processing" $@55 ":" "{" expired_leases_params "}"
#line 1348 "dhcp4_parser.yy"
                                                            {
    // No expired lease parameter is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2473 "dhcp4_parser.cc"
    break;

  case 342: // expired_leases_params: expired_leases_params ","
#line 1356 "dhcp4_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 2481 "dhcp4_parser.cc"
    break;

  case 349: // reclaim_timer_wait_time: "reclaim-timer-wait-time" ":" "integer"
#line 1369 "dhcp4_parser.yy"
                                                               {
    ctx.unique("reclaim-timer-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reclaim-timer-wait-time", value);
}
#line 2491 "dhcp4_parser.cc"
    break;

  case 350: // flush_reclaimed_timer_wait_time: "flush-reclaimed-timer-wait-time" ":" "integer"
#line 1375 "dhcp4_parser.yy"
                                                                               {
    ctx.unique("flush-reclaimed-timer-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush-reclaimed-timer-wait-time", value);
}
#line 2501 "dhcp4_parser.cc"
    break;

  case 351: // hold_reclaimed_time: "hold-reclaimed-time" ":" "integer"
#line 1381 "dhcp4_parser.yy"
                                                       {
    ctx.unique("hold-reclaimed-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hold-reclaimed-time", value);
}
#line 2511 "dhcp4_parser.cc"
    break;

  case 352: // max_reclaim_leases: "max-reclaim-leases" ":" "integer"
#line 1387 "dhcp4_parser.yy"
                                                     {
    ctx.unique("max-reclaim-leases", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reclaim-leases", value);
}
#line 2521 "dhcp4_parser.cc"
    break;

  case 353: // max_reclaim_time: "max-reclaim-time" ":" "integer"
#line 1393 "dhcp4_parser.yy"
                                                 {
    ctx.unique("max-reclaim-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reclaim-time", value);
}
#line 2531 "dhcp4_parser.cc"
    break;

  case 354: // unwarned_reclaim_cycles: "unwarned-reclaim-cycles" ":" "integer"
#line 1399 "dhcp4_parser.yy"
                                                               {
    ctx.unique("unwarned-reclaim-cycles", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("unwarned-reclaim-cycles", value);
}
#line 2541 "dhcp4_parser.cc"
    break;

  case 355: // $@56: %empty
#line 1408 "dhcp4_parser.yy"
                      {
    ctx.unique("subnet4", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("subnet4", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.SUBNET4);
}
#line 2553 "dhcp4_parser.cc"
    break;

  case 356: // subnet4_list: "subnet4" $@56 ":" "[" subnet4_list_content "]"
#line 1414 "dhcp4_parser.yy"
                                                             {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2562 "dhcp4_parser.cc"
    break;

  case 361: // not_empty_subnet4_list: not_empty_subnet4_list ","
#line 1428 "dhcp4_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 2570 "dhcp4_parser.cc"
    break;

  case 362: // $@57: %empty
#line 1437 "dhcp4_parser.yy"
                        {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2580 "dhcp4_parser.cc"
    break;

  case 363: // subnet4: "{" $@57 subnet4_params "}"
#line 1441 "dhcp4_parser.yy"
                                {
    // Once we reached this place, the subnet parsing is now complete.
    // If we want to, we can implement default values here.
    // In particular we can do things like this:
    // if (!ctx.stack_.back()->get("interface")) {
    //     ctx.stack_.back()->set("interface", StringElement("loopback"));
    // }
    //
    // We can also stack up one level (Dhcp4) and copy over whatever
    // global parameters we want to:
    // if (!ctx.stack_.back()->get("renew-timer")) {
    //     ElementPtr renew = ctx_stack_[...].get("renew-timer");
    //     if (renew) {
    //         ctx.stack_.back()->set("renew-timer", renew);
    //     }
    // }

    // The subnet subnet4 parameter is required
    ctx.require("subnet", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2606 "dhcp4_parser.cc"
    break;

  case 364: // $@58: %empty
#line 1463 "dhcp4_parser.yy"
                            {
    // Parse the subnet4 list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2616 "dhcp4_parser.cc"
    break;

  case 365: // sub_subnet4: "{" $@58 subnet4_params "}"
#line 1467 "dhcp4_parser.yy"
                                {
    // The subnet subnet4 parameter is required
    ctx.require("subnet", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2626 "dhcp4_parser.cc"
    break;

  case 368: // subnet4_params: subnet4_params ","
#line 1476 "dhcp4_parser.yy"
                                     {
                  ctx.warnAboutExtraCommas(yystack_[0].location);
                  }
#line 2634 "dhcp4_parser.cc"
    break;

  case 414: // $@59: %empty
#line 1529 "dhcp4_parser.yy"
               {
    ctx.unique("subnet", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2643 "dhcp4_parser.cc"
    break;

  case 415: // subnet: "subnet" $@59 ":" "constant string"
#line 1532 "dhcp4_parser.yy"
               {
    ElementPtr subnet(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("subnet", subnet);
    ctx.leave();
}
#line 2653 "dhcp4_parser.cc"
    break;

  case 416: // $@60: %empty
#line 1538 "dhcp4_parser.yy"
                                           {
    ctx.unique("4o6-interface", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2662 "dhcp4_parser.cc"
    break;

  case 417: // subnet_4o6_interface: "4o6-interface" $@60 ":" "constant string"
#line 1541 "dhcp4_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("4o6-interface", iface);
    ctx.leave();
}
#line 2672 "dhcp4_parser.cc"
    break;

  case 418: // $@61: %empty
#line 1547 "dhcp4_parser.yy"
                                                 {
    ctx.unique("4o6-interface-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2681 "dhcp4_parser.cc"
    break;

  case 419: // subnet_4o6_interface_id: "4o6-interface-id" $@61 ":" "constant string"
#line 1550 "dhcp4_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("4o6-interface-id", iface);
    ctx.leave();
}
#line 2691 "dhcp4_parser.cc"
    break;

  case 420: // $@62: %empty
#line 1556 "dhcp4_parser.yy"
                                     {
    ctx.unique("4o6-subnet", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2700 "dhcp4_parser.cc"
    break;

  case 421: // subnet_4o6_subnet: "4o6-subnet" $@62 ":" "constant string"
#line 1559 "dhcp4_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("4o6-subnet", iface);
    ctx.leave();
}
#line 2710 "dhcp4_parser.cc"
    break;

  case 422: // $@63: %empty
#line 1565 "dhcp4_parser.yy"
                     {
    ctx.unique("interface", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2719 "dhcp4_parser.cc"
    break;

  case 423: // interface: "interface" $@63 ":" "constant string"
#line 1568 "dhcp4_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interface", iface);
    ctx.leave();
}
#line 2729 "dhcp4_parser.cc"
    break;

  case 424: // $@64: %empty
#line 1574 "dhcp4_parser.yy"
                           {
    ctx.unique("client-class", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2738 "dhcp4_parser.cc"
    break;

  case 425: // client_class: "client-class" $@64 ":" "constant string"
#line 1577 "dhcp4_parser.yy"
               {
    ElementPtr cls(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-class", cls);
    ctx.leave();
}
#line 2748 "dhcp4_parser.cc"
    break;

  case 426: // $@65: %empty
#line 1583 "dhcp4_parser.yy"
                                               {
    ctx.unique("require-client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr c(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("require-client-classes", c);
    ctx.stack_.push_back(c);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2760 "dhcp4_parser.cc"
    break;

  case 427: // require_client_classes: "require-client-classes" $@65 ":" list_strings
#line 1589 "dhcp4_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2769 "dhcp4_parser.cc"
    break;

  case 428: // reservations_global: "reservations-global" ":" "boolean"
#line 1594 "dhcp4_parser.yy"
                                                       {
    ctx.unique("reservations-global", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-global", b);
}
#line 2779 "dhcp4_parser.cc"
    break;

  case 429: // reservations_in_subnet: "reservations-in-subnet" ":" "boolean"
#line 1600 "dhcp4_parser.yy"
                                                             {
    ctx.unique("reservations-in-subnet", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-in-subnet", b);
}
#line 2789 "dhcp4_parser.cc"
    break;

  case 430: // reservations_out_of_pool: "reservations-out-of-pool" ":" "boolean"
#line 1606 "dhcp4_parser.yy"
                                                                 {
    ctx.unique("reservations-out-of-pool", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-out-of-pool", b);
}
#line 2799 "dhcp4_parser.cc"
    break;

  case 431: // $@66: %empty
#line 1612 "dhcp4_parser.yy"
                                   {
    ctx.unique("reservation-mode", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.RESERVATION_MODE);
}
#line 2808 "dhcp4_parser.cc"
    break;

  case 432: // reservation_mode: "reservation-mode" $@66 ":" hr_mode
#line 1615 "dhcp4_parser.yy"
                {
    ctx.stack_.back()->set("reservation-mode", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2817 "dhcp4_parser.cc"
    break;

  case 433: // hr_mode: "disabled"
#line 1620 "dhcp4_parser.yy"
                  { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("disabled", ctx.loc2pos(yystack_[0].location))); }
#line 2823 "dhcp4_parser.cc"
    break;

  case 434: // hr_mode: "out-of-pool"
#line 1621 "dhcp4_parser.yy"
                     { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("out-of-pool", ctx.loc2pos(yystack_[0].location))); }
#line 2829 "dhcp4_parser.cc"
    break;

  case 435: // hr_mode: "global"
#line 1622 "dhcp4_parser.yy"
                { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("global", ctx.loc2pos(yystack_[0].location))); }
#line 2835 "dhcp4_parser.cc"
    break;

  case 436: // hr_mode: "all"
#line 1623 "dhcp4_parser.yy"
             { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("all", ctx.loc2pos(yystack_[0].location))); }
#line 2841 "dhcp4_parser.cc"
    break;

  case 437: // id: "id" ":" "integer"
#line 1626 "dhcp4_parser.yy"
                     {
    ctx.unique("id", ctx.loc2pos(yystack_[2].location));
    ElementPtr id(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("id", id);
}
#line 2851 "dhcp4_parser.cc"
    break;

  case 438: // $@67: %empty
#line 1634 "dhcp4_parser.yy"
                                 {
    ctx.unique("shared-networks", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("shared-networks", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.SHARED_NETWORK);
}
#line 2863 "dhcp4_parser.cc"
    break;

  case 439: // shared_networks: "shared-networks" $@67 ":" "[" shared_networks_content "]"
#line 1640 "dhcp4_parser.yy"
                                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2872 "dhcp4_parser.cc"
    break;

  case 444: // shared_networks_list: shared_networks_list ","
#line 1653 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 2880 "dhcp4_parser.cc"
    break;

  case 445: // $@68: %empty
#line 1658 "dhcp4_parser.yy"
                               {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2890 "dhcp4_parser.cc"
    break;

  case 446: // shared_network: "{" $@68 shared_network_params "}"
#line 1662 "dhcp4_parser.yy"
                                       {
    ctx.stack_.pop_back();
}
#line 2898 "dhcp4_parser.cc"
    break;

  case 449: // shared_network_params: shared_network_params ","
#line 1668 "dhcp4_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 2906 "dhcp4_parser.cc"
    break;

  case 490: // $@69: %empty
#line 1719 "dhcp4_parser.yy"
                            {
    ctx.unique("option-def", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("option-def", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OPTION_DEF);
}
#line 2918 "dhcp4_parser.cc"
    break;

  case 491: // option_def_list: "option-def" $@69 ":" "[" option_def_list_content "]"
#line 1725 "dhcp4_parser.yy"
                                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2927 "dhcp4_parser.cc"
    break;

  case 492: // $@70: %empty
#line 1733 "dhcp4_parser.yy"
                                    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2936 "dhcp4_parser.cc"
    break;

  case 493: // sub_option_def_list: "{" $@70 option_def_list "}"
#line 1736 "dhcp4_parser.yy"
                                 {
    // parsing completed
}
#line 2944 "dhcp4_parser.cc"
    break;

  case 498: // not_empty_option_def_list: not_empty_option_def_list ","
#line 1748 "dhcp4_parser.yy"
                                                           {
                             ctx.warnAboutExtraCommas(yystack_[0].location);
                             }
#line 2952 "dhcp4_parser.cc"
    break;

  case 499: // $@71: %empty
#line 1755 "dhcp4_parser.yy"
                                 {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2962 "dhcp4_parser.cc"
    break;

  case 500: // option_def_entry: "{" $@71 option_def_params "}"
#line 1759 "dhcp4_parser.yy"
                                   {
    // The name, code and type option def parameters are required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("code", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2974 "dhcp4_parser.cc"
    break;

  case 501: // $@72: %empty
#line 1770 "dhcp4_parser.yy"
                               {
    // Parse the option-def list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2984 "dhcp4_parser.cc"
    break;

  case 502: // sub_option_def: "{" $@72 option_def_params "}"
#line 1774 "dhcp4_parser.yy"
                                   {
    // The name, code and type option def parameters are required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("code", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2996 "dhcp4_parser.cc"
    break;

  case 507: // not_empty_option_def_params: not_empty_option_def_params ","
#line 1790 "dhcp4_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 3004 "dhcp4_parser.cc"
    break;

  case 519: // code: "code" ":" "integer"
#line 1809 "dhcp4_parser.yy"
                         {
    ctx.unique("code", ctx.loc2pos(yystack_[2].location));
    ElementPtr code(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("code", code);
}
#line 3014 "dhcp4_parser.cc"
    break;

  case 521: // $@73: %empty
#line 1817 "dhcp4_parser.yy"
                      {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3023 "dhcp4_parser.cc"
    break;

  case 522: // option_def_type: "type" $@73 ":" "constant string"
#line 1820 "dhcp4_parser.yy"
               {
    ElementPtr prf(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("type", prf);
    ctx.leave();
}
#line 3033 "dhcp4_parser.cc"
    break;

  case 523: // $@74: %empty
#line 1826 "dhcp4_parser.yy"
                                      {
    ctx.unique("record-types", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3042 "dhcp4_parser.cc"
    break;

  case 524: // option_def_record_types: "record-types" $@74 ":" "constant string"
#line 1829 "dhcp4_parser.yy"
               {
    ElementPtr rtypes(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("record-types", rtypes);
    ctx.leave();
}
#line 3052 "dhcp4_parser.cc"
    break;

  case 525: // $@75: %empty
#line 1835 "dhcp4_parser.yy"
             {
    ctx.unique("space", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3061 "dhcp4_parser.cc"
    break;

  case 526: // space: "space" $@75 ":" "constant string"
#line 1838 "dhcp4_parser.yy"
               {
    ElementPtr space(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("space", space);
    ctx.leave();
}
#line 3071 "dhcp4_parser.cc"
    break;

  case 528: // $@76: %empty
#line 1846 "dhcp4_parser.yy"
                                    {
    ctx.unique("encapsulate", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3080 "dhcp4_parser.cc"
    break;

  case 529: // option_def_encapsulate: "encapsulate" $@76 ":" "constant string"
#line 1849 "dhcp4_parser.yy"
               {
    ElementPtr encap(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("encapsulate", encap);
    ctx.leave();
}
#line 3090 "dhcp4_parser.cc"
    break;

  case 530: // option_def_array: "array" ":" "boolean"
#line 1855 "dhcp4_parser.yy"
                                      {
    ctx.unique("array", ctx.loc2pos(yystack_[2].location));
    ElementPtr array(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("array", array);
}
#line 3100 "dhcp4_parser.cc"
    break;

  case 531: // $@77: %empty
#line 1865 "dhcp4_parser.yy"
                              {
    ctx.unique("option-data", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("option-data", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OPTION_DATA);
}
#line 3112 "dhcp4_parser.cc"
    break;

  case 532: // option_data_list: "option-data" $@77 ":" "[" option_data_list_content "]"
#line 1871 "dhcp4_parser.yy"
                                                                 {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3121 "dhcp4_parser.cc"
    break;

  case 537: // not_empty_option_data_list: not_empty_option_data_list ","
#line 1886 "dhcp4_parser.yy"
                                                             {
                              ctx.warnAboutExtraCommas(yystack_[0].location);
                              }
#line 3129 "dhcp4_parser.cc"
    break;

  case 538: // $@78: %empty
#line 1893 "dhcp4_parser.yy"
                                  {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3139 "dhcp4_parser.cc"
    break;

  case 539: // option_data_entry: "{" $@78 option_data_params "}"
#line 1897 "dhcp4_parser.yy"
                                    {
    /// @todo: the code or name parameters are required.
    ctx.stack_.pop_back();
}
#line 3148 "dhcp4_parser.cc"
    break;

  case 540: // $@79: %empty
#line 1905 "dhcp4_parser.yy"
                                {
    // Parse the option-data list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3158 "dhcp4_parser.cc"
    break;

  case 541: // sub_option_data: "{" $@79 option_data_params "}"
#line 1909 "dhcp4_parser.yy"
                                    {
    /// @todo: the code or name parameters are required.
    // parsing completed
}
#line 3167 "dhcp4_parser.cc"
    break;

  case 546: // not_empty_option_data_params: not_empty_option_data_params ","
#line 1925 "dhcp4_parser.yy"
                                         {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3175 "dhcp4_parser.cc"
    break;

  case 558: // $@80: %empty
#line 1946 "dhcp4_parser.yy"
                       {
    ctx.unique("data", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3184 "dhcp4_parser.cc"
    break;

  case 559: // option_data_data: "data" $@80 ":" "constant string"
#line 1949 "dhcp4_parser.yy"
               {
    ElementPtr data(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("data", data);
    ctx.leave();
}
#line 3194 "dhcp4_parser.cc"
    break;

  case 562: // option_data_csv_format: "csv-format" ":" "boolean"
#line 1959 "dhcp4_parser.yy"
                                                 {
    ctx.unique("csv-format", ctx.loc2pos(yystack_[2].location));
    ElementPtr space(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("csv-format", space);
}
#line 3204 "dhcp4_parser.cc"
    break;

  case 563: // option_data_always_send: "always-send" ":" "boolean"
#line 1965 "dhcp4_parser.yy"
                                                   {
    ctx.unique("always-send", ctx.loc2pos(yystack_[2].location));
    ElementPtr persist(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("always-send", persist);
}
#line 3214 "dhcp4_parser.cc"
    break;

  case 564: // option_data_never_send: "never-send" ":" "boolean"
#line 1971 "dhcp4_parser.yy"
                                                 {
    ctx.unique("never-send", ctx.loc2pos(yystack_[2].location));
    ElementPtr persist(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("never-send", persist);
}
#line 3224 "dhcp4_parser.cc"
    break;

  case 565: // $@81: %empty
#line 1980 "dhcp4_parser.yy"
                  {
    ctx.unique("pools", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pools", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.POOLS);
}
#line 3236 "dhcp4_parser.cc"
    break;

  case 566: // pools_list: "pools" $@81 ":" "[" pools_list_content "]"
#line 1986 "dhcp4_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3245 "dhcp4_parser.cc"
    break;

  case 571: // not_empty_pools_list: not_empty_pools_list ","
#line 1999 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 3253 "dhcp4_parser.cc"
    break;

  case 572: // $@82: %empty
#line 2004 "dhcp4_parser.yy"
                                {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3263 "dhcp4_parser.cc"
    break;

  case 573: // pool_list_entry: "{" $@82 pool_params "}"
#line 2008 "dhcp4_parser.yy"
                             {
    // The pool parameter is required.
    ctx.require("pool", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3273 "dhcp4_parser.cc"
    break;

  case 574: // $@83: %empty
#line 2014 "dhcp4_parser.yy"
                          {
    // Parse the pool list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3283 "dhcp4_parser.cc"
    break;

  case 575: // sub_pool4: "{" $@83 pool_params "}"
#line 2018 "dhcp4_parser.yy"
                             {
    // The pool parameter is required.
    ctx.require("pool", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 3293 "dhcp4_parser.cc"
    break;

  case 578: // pool_params: pool_params ","
#line 2026 "dhcp4_parser.yy"
                               {
               ctx.warnAboutExtraCommas(yystack_[0].location);
               }
#line 3301 "dhcp4_parser.cc"
    break;

  case 586: // $@84: %empty
#line 2040 "dhcp4_parser.yy"
                 {
    ctx.unique("pool", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3310 "dhcp4_parser.cc"
    break;

  case 587: // pool_entry: "pool" $@84 ":" "constant string"
#line 2043 "dhcp4_parser.yy"
               {
    ElementPtr pool(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pool", pool);
    ctx.leave();
}
#line 3320 "dhcp4_parser.cc"
    break;

  case 588: // $@85: %empty
#line 2049 "dhcp4_parser.yy"
                           {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3328 "dhcp4_parser.cc"
    break;

  case 589: // user_context: "user-context" $@85 ":" map_value
#line 2051 "dhcp4_parser.yy"
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
#line 3355 "dhcp4_parser.cc"
    break;

  case 590: // $@86: %empty
#line 2074 "dhcp4_parser.yy"
                 {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3363 "dhcp4_parser.cc"
    break;

  case 591: // comment: "comment" $@86 ":" "constant string"
#line 2076 "dhcp4_parser.yy"
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
#line 3392 "dhcp4_parser.cc"
    break;

  case 592: // $@87: %empty
#line 2104 "dhcp4_parser.yy"
                           {
    ctx.unique("reservations", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.RESERVATIONS);
}
#line 3404 "dhcp4_parser.cc"
    break;

  case 593: // reservations: "reservations" $@87 ":" "[" reservations_list "]"
#line 2110 "dhcp4_parser.yy"
                                                          {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3413 "dhcp4_parser.cc"
    break;

  case 598: // not_empty_reservations_list: not_empty_reservations_list ","
#line 2121 "dhcp4_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 3421 "dhcp4_parser.cc"
    break;

  case 599: // $@88: %empty
#line 2126 "dhcp4_parser.yy"
                            {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3431 "dhcp4_parser.cc"
    break;

  case 600: // reservation: "{" $@88 reservation_params "}"
#line 2130 "dhcp4_parser.yy"
                                    {
    /// @todo: an identifier parameter is required.
    ctx.stack_.pop_back();
}
#line 3440 "dhcp4_parser.cc"
    break;

  case 601: // $@89: %empty
#line 2135 "dhcp4_parser.yy"
                                {
    // Parse the reservations list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3450 "dhcp4_parser.cc"
    break;

  case 602: // sub_reservation: "{" $@89 reservation_params "}"
#line 2139 "dhcp4_parser.yy"
                                    {
    /// @todo: an identifier parameter is required.
    // parsing completed
}
#line 3459 "dhcp4_parser.cc"
    break;

  case 607: // not_empty_reservation_params: not_empty_reservation_params ","
#line 2150 "dhcp4_parser.yy"
                                         {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3467 "dhcp4_parser.cc"
    break;

  case 623: // $@90: %empty
#line 2173 "dhcp4_parser.yy"
                         {
    ctx.unique("next-server", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3476 "dhcp4_parser.cc"
    break;

  case 624: // next_server: "next-server" $@90 ":" "constant string"
#line 2176 "dhcp4_parser.yy"
               {
    ElementPtr next_server(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("next-server", next_server);
    ctx.leave();
}
#line 3486 "dhcp4_parser.cc"
    break;

  case 625: // $@91: %empty
#line 2182 "dhcp4_parser.yy"
                                 {
    ctx.unique("server-hostname", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3495 "dhcp4_parser.cc"
    break;

  case 626: // server_hostname: "server-hostname" $@91 ":" "constant string"
#line 2185 "dhcp4_parser.yy"
               {
    ElementPtr srv(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-hostname", srv);
    ctx.leave();
}
#line 3505 "dhcp4_parser.cc"
    break;

  case 627: // $@92: %empty
#line 2191 "dhcp4_parser.yy"
                               {
    ctx.unique("boot-file-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3514 "dhcp4_parser.cc"
    break;

  case 628: // boot_file_name: "boot-file-name" $@92 ":" "constant string"
#line 2194 "dhcp4_parser.yy"
               {
    ElementPtr bootfile(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("boot-file-name", bootfile);
    ctx.leave();
}
#line 3524 "dhcp4_parser.cc"
    break;

  case 629: // $@93: %empty
#line 2200 "dhcp4_parser.yy"
                       {
    ctx.unique("ip-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3533 "dhcp4_parser.cc"
    break;

  case 630: // ip_address: "ip-address" $@93 ":" "constant string"
#line 2203 "dhcp4_parser.yy"
               {
    ElementPtr addr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-address", addr);
    ctx.leave();
}
#line 3543 "dhcp4_parser.cc"
    break;

  case 631: // $@94: %empty
#line 2209 "dhcp4_parser.yy"
                           {
    ctx.unique("ip-addresses", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-addresses", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3555 "dhcp4_parser.cc"
    break;

  case 632: // ip_addresses: "ip-addresses" $@94 ":" list_strings
#line 2215 "dhcp4_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3564 "dhcp4_parser.cc"
    break;

  case 633: // $@95: %empty
#line 2220 "dhcp4_parser.yy"
           {
    ctx.unique("duid", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3573 "dhcp4_parser.cc"
    break;

  case 634: // duid: "duid" $@95 ":" "constant string"
#line 2223 "dhcp4_parser.yy"
               {
    ElementPtr d(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("duid", d);
    ctx.leave();
}
#line 3583 "dhcp4_parser.cc"
    break;

  case 635: // $@96: %empty
#line 2229 "dhcp4_parser.yy"
                       {
    ctx.unique("hw-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3592 "dhcp4_parser.cc"
    break;

  case 636: // hw_address: "hw-address" $@96 ":" "constant string"
#line 2232 "dhcp4_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hw-address", hw);
    ctx.leave();
}
#line 3602 "dhcp4_parser.cc"
    break;

  case 637: // $@97: %empty
#line 2238 "dhcp4_parser.yy"
                           {
    ctx.unique("client-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3611 "dhcp4_parser.cc"
    break;

  case 638: // client_id_value: "client-id" $@97 ":" "constant string"
#line 2241 "dhcp4_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-id", hw);
    ctx.leave();
}
#line 3621 "dhcp4_parser.cc"
    break;

  case 639: // $@98: %empty
#line 2247 "dhcp4_parser.yy"
                             {
    ctx.unique("circuit-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3630 "dhcp4_parser.cc"
    break;

  case 640: // circuit_id_value: "circuit-id" $@98 ":" "constant string"
#line 2250 "dhcp4_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("circuit-id", hw);
    ctx.leave();
}
#line 3640 "dhcp4_parser.cc"
    break;

  case 641: // $@99: %empty
#line 2256 "dhcp4_parser.yy"
                       {
    ctx.unique("flex-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3649 "dhcp4_parser.cc"
    break;

  case 642: // flex_id_value: "flex-id" $@99 ":" "constant string"
#line 2259 "dhcp4_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flex-id", hw);
    ctx.leave();
}
#line 3659 "dhcp4_parser.cc"
    break;

  case 643: // $@100: %empty
#line 2265 "dhcp4_parser.yy"
                   {
    ctx.unique("hostname", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3668 "dhcp4_parser.cc"
    break;

  case 644: // hostname: "hostname" $@100 ":" "constant string"
#line 2268 "dhcp4_parser.yy"
               {
    ElementPtr host(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname", host);
    ctx.leave();
}
#line 3678 "dhcp4_parser.cc"
    break;

  case 645: // $@101: %empty
#line 2274 "dhcp4_parser.yy"
                                           {
    ctx.unique("client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr c(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-classes", c);
    ctx.stack_.push_back(c);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3690 "dhcp4_parser.cc"
    break;

  case 646: // reservation_client_classes: "client-classes" $@101 ":" list_strings
#line 2280 "dhcp4_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3699 "dhcp4_parser.cc"
    break;

  case 647: // $@102: %empty
#line 2288 "dhcp4_parser.yy"
             {
    ctx.unique("relay", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("relay", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.RELAY);
}
#line 3711 "dhcp4_parser.cc"
    break;

  case 648: // relay: "relay" $@102 ":" "{" relay_map "}"
#line 2294 "dhcp4_parser.yy"
                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3720 "dhcp4_parser.cc"
    break;

  case 651: // $@103: %empty
#line 2306 "dhcp4_parser.yy"
                               {
    ctx.unique("client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-classes", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.CLIENT_CLASSES);
}
#line 3732 "dhcp4_parser.cc"
    break;

  case 652: // client_classes: "client-classes" $@103 ":" "[" client_classes_list "]"
#line 2312 "dhcp4_parser.yy"
                                                            {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3741 "dhcp4_parser.cc"
    break;

  case 655: // client_classes_list: client_classes_list ","
#line 2319 "dhcp4_parser.yy"
                                               {
                       ctx.warnAboutExtraCommas(yystack_[0].location);
                       }
#line 3749 "dhcp4_parser.cc"
    break;

  case 656: // $@104: %empty
#line 2324 "dhcp4_parser.yy"
                                   {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3759 "dhcp4_parser.cc"
    break;

  case 657: // client_class_entry: "{" $@104 client_class_params "}"
#line 2328 "dhcp4_parser.yy"
                                     {
    // The name client class parameter is required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3769 "dhcp4_parser.cc"
    break;

  case 662: // not_empty_client_class_params: not_empty_client_class_params ","
#line 2340 "dhcp4_parser.yy"
                                          {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3777 "dhcp4_parser.cc"
    break;

  case 679: // $@105: %empty
#line 2364 "dhcp4_parser.yy"
                        {
    ctx.unique("test", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3786 "dhcp4_parser.cc"
    break;

  case 680: // client_class_test: "test" $@105 ":" "constant string"
#line 2367 "dhcp4_parser.yy"
               {
    ElementPtr test(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("test", test);
    ctx.leave();
}
#line 3796 "dhcp4_parser.cc"
    break;

  case 681: // $@106: %empty
#line 2373 "dhcp4_parser.yy"
                                          {
    ctx.unique("template-test", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3805 "dhcp4_parser.cc"
    break;

  case 682: // client_class_template_test: "template-test" $@106 ":" "constant string"
#line 2376 "dhcp4_parser.yy"
               {
    ElementPtr template_test(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("template-test", template_test);
    ctx.leave();
}
#line 3815 "dhcp4_parser.cc"
    break;

  case 683: // only_if_required: "only-if-required" ":" "boolean"
#line 2382 "dhcp4_parser.yy"
                                                 {
    ctx.unique("only-if-required", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("only-if-required", b);
}
#line 3825 "dhcp4_parser.cc"
    break;

  case 684: // dhcp4o6_port: "dhcp4o6-port" ":" "integer"
#line 2390 "dhcp4_parser.yy"
                                         {
    ctx.unique("dhcp4o6-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr time(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp4o6-port", time);
}
#line 3835 "dhcp4_parser.cc"
    break;

  case 685: // $@107: %empty
#line 2398 "dhcp4_parser.yy"
                               {
    ctx.unique("control-socket", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("control-socket", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.CONTROL_SOCKET);
}
#line 3847 "dhcp4_parser.cc"
    break;

  case 686: // control_socket: "control-socket" $@107 ":" "{" control_socket_params "}"
#line 2404 "dhcp4_parser.yy"
                                                            {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3856 "dhcp4_parser.cc"
    break;

  case 689: // control_socket_params: control_socket_params ","
#line 2411 "dhcp4_parser.yy"
                                                   {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 3864 "dhcp4_parser.cc"
    break;

  case 695: // $@108: %empty
#line 2423 "dhcp4_parser.yy"
                                 {
    ctx.unique("socket-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3873 "dhcp4_parser.cc"
    break;

  case 696: // control_socket_type: "socket-type" $@108 ":" "constant string"
#line 2426 "dhcp4_parser.yy"
               {
    ElementPtr stype(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-type", stype);
    ctx.leave();
}
#line 3883 "dhcp4_parser.cc"
    break;

  case 697: // $@109: %empty
#line 2432 "dhcp4_parser.yy"
                                 {
    ctx.unique("socket-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3892 "dhcp4_parser.cc"
    break;

  case 698: // control_socket_name: "socket-name" $@109 ":" "constant string"
#line 2435 "dhcp4_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-name", name);
    ctx.leave();
}
#line 3902 "dhcp4_parser.cc"
    break;

  case 699: // $@110: %empty
#line 2444 "dhcp4_parser.yy"
                                       {
    ctx.unique("dhcp-queue-control", ctx.loc2pos(yystack_[0].location));
    ElementPtr qc(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp-queue-control", qc);
    ctx.stack_.push_back(qc);
    ctx.enter(ctx.DHCP_QUEUE_CONTROL);
}
#line 3914 "dhcp4_parser.cc"
    break;

  case 700: // dhcp_queue_control: "dhcp-queue-control" $@110 ":" "{" queue_control_params "}"
#line 2450 "dhcp4_parser.yy"
                                                           {
    // The enable queue parameter is required.
    ctx.require("enable-queue", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3925 "dhcp4_parser.cc"
    break;

  case 703: // queue_control_params: queue_control_params ","
#line 2459 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 3933 "dhcp4_parser.cc"
    break;

  case 710: // enable_queue: "enable-queue" ":" "boolean"
#line 2472 "dhcp4_parser.yy"
                                         {
    ctx.unique("enable-queue", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-queue", b);
}
#line 3943 "dhcp4_parser.cc"
    break;

  case 711: // $@111: %empty
#line 2478 "dhcp4_parser.yy"
                       {
    ctx.unique("queue-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3952 "dhcp4_parser.cc"
    break;

  case 712: // queue_type: "queue-type" $@111 ":" "constant string"
#line 2481 "dhcp4_parser.yy"
               {
    ElementPtr qt(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("queue-type", qt);
    ctx.leave();
}
#line 3962 "dhcp4_parser.cc"
    break;

  case 713: // capacity: "capacity" ":" "integer"
#line 2487 "dhcp4_parser.yy"
                                 {
    ctx.unique("capacity", ctx.loc2pos(yystack_[2].location));
    ElementPtr c(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("capacity", c);
}
#line 3972 "dhcp4_parser.cc"
    break;

  case 714: // $@112: %empty
#line 2493 "dhcp4_parser.yy"
                            {
    ctx.unique(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3981 "dhcp4_parser.cc"
    break;

  case 715: // arbitrary_map_entry: "constant string" $@112 ":" value
#line 2496 "dhcp4_parser.yy"
              {
    ctx.stack_.back()->set(yystack_[3].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 3990 "dhcp4_parser.cc"
    break;

  case 716: // $@113: %empty
#line 2503 "dhcp4_parser.yy"
                     {
    ctx.unique("dhcp-ddns", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp-ddns", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.DHCP_DDNS);
}
#line 4002 "dhcp4_parser.cc"
    break;

  case 717: // dhcp_ddns: "dhcp-ddns" $@113 ":" "{" dhcp_ddns_params "}"
#line 2509 "dhcp4_parser.yy"
                                                       {
    // The enable updates DHCP DDNS parameter is required.
    ctx.require("enable-updates", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4013 "dhcp4_parser.cc"
    break;

  case 718: // $@114: %empty
#line 2516 "dhcp4_parser.yy"
                              {
    // Parse the dhcp-ddns map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 4023 "dhcp4_parser.cc"
    break;

  case 719: // sub_dhcp_ddns: "{" $@114 dhcp_ddns_params "}"
#line 2520 "dhcp4_parser.yy"
                                  {
    // The enable updates DHCP DDNS parameter is required.
    ctx.require("enable-updates", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 4033 "dhcp4_parser.cc"
    break;

  case 722: // dhcp_ddns_params: dhcp_ddns_params ","
#line 2528 "dhcp4_parser.yy"
                                         {
                    ctx.warnAboutExtraCommas(yystack_[0].location);
                    }
#line 4041 "dhcp4_parser.cc"
    break;

  case 741: // enable_updates: "enable-updates" ":" "boolean"
#line 2553 "dhcp4_parser.yy"
                                             {
    ctx.unique("enable-updates", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-updates", b);
}
#line 4051 "dhcp4_parser.cc"
    break;

  case 742: // $@115: %empty
#line 2559 "dhcp4_parser.yy"
                     {
    ctx.unique("server-ip", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4060 "dhcp4_parser.cc"
    break;

  case 743: // server_ip: "server-ip" $@115 ":" "constant string"
#line 2562 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-ip", s);
    ctx.leave();
}
#line 4070 "dhcp4_parser.cc"
    break;

  case 744: // server_port: "server-port" ":" "integer"
#line 2568 "dhcp4_parser.yy"
                                       {
    ctx.unique("server-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-port", i);
}
#line 4080 "dhcp4_parser.cc"
    break;

  case 745: // $@116: %empty
#line 2574 "dhcp4_parser.yy"
                     {
    ctx.unique("sender-ip", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4089 "dhcp4_parser.cc"
    break;

  case 746: // sender_ip: "sender-ip" $@116 ":" "constant string"
#line 2577 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sender-ip", s);
    ctx.leave();
}
#line 4099 "dhcp4_parser.cc"
    break;

  case 747: // sender_port: "sender-port" ":" "integer"
#line 2583 "dhcp4_parser.yy"
                                       {
    ctx.unique("sender-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sender-port", i);
}
#line 4109 "dhcp4_parser.cc"
    break;

  case 748: // max_queue_size: "max-queue-size" ":" "integer"
#line 2589 "dhcp4_parser.yy"
                                             {
    ctx.unique("max-queue-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-queue-size", i);
}
#line 4119 "dhcp4_parser.cc"
    break;

  case 749: // $@117: %empty
#line 2595 "dhcp4_parser.yy"
                           {
    ctx.unique("ncr-protocol", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_PROTOCOL);
}
#line 4128 "dhcp4_parser.cc"
    break;

  case 750: // ncr_protocol: "ncr-protocol" $@117 ":" ncr_protocol_value
#line 2598 "dhcp4_parser.yy"
                           {
    ctx.stack_.back()->set("ncr-protocol", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4137 "dhcp4_parser.cc"
    break;

  case 751: // ncr_protocol_value: "udp"
#line 2604 "dhcp4_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("UDP", ctx.loc2pos(yystack_[0].location))); }
#line 4143 "dhcp4_parser.cc"
    break;

  case 752: // ncr_protocol_value: "tcp"
#line 2605 "dhcp4_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("TCP", ctx.loc2pos(yystack_[0].location))); }
#line 4149 "dhcp4_parser.cc"
    break;

  case 753: // $@118: %empty
#line 2608 "dhcp4_parser.yy"
                       {
    ctx.unique("ncr-format", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_FORMAT);
}
#line 4158 "dhcp4_parser.cc"
    break;

  case 754: // ncr_format: "ncr-format" $@118 ":" "JSON"
#line 2611 "dhcp4_parser.yy"
             {
    ElementPtr json(new StringElement("JSON", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ncr-format", json);
    ctx.leave();
}
#line 4168 "dhcp4_parser.cc"
    break;

  case 755: // $@119: %empty
#line 2618 "dhcp4_parser.yy"
                                         {
    ctx.unique("qualifying-suffix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4177 "dhcp4_parser.cc"
    break;

  case 756: // dep_qualifying_suffix: "qualifying-suffix" $@119 ":" "constant string"
#line 2621 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("qualifying-suffix", s);
    ctx.leave();
}
#line 4187 "dhcp4_parser.cc"
    break;

  case 757: // dep_override_no_update: "override-no-update" ":" "boolean"
#line 2628 "dhcp4_parser.yy"
                                                         {
    ctx.unique("override-no-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("override-no-update", b);
}
#line 4197 "dhcp4_parser.cc"
    break;

  case 758: // dep_override_client_update: "override-client-update" ":" "boolean"
#line 2635 "dhcp4_parser.yy"
                                                                 {
    ctx.unique("override-client-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("override-client-update", b);
}
#line 4207 "dhcp4_parser.cc"
    break;

  case 759: // $@120: %empty
#line 2642 "dhcp4_parser.yy"
                                             {
    ctx.unique("replace-client-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.REPLACE_CLIENT_NAME);
}
#line 4216 "dhcp4_parser.cc"
    break;

  case 760: // dep_replace_client_name: "replace-client-name" $@120 ":" ddns_replace_client_name_value
#line 2645 "dhcp4_parser.yy"
                                       {
    ctx.stack_.back()->set("replace-client-name", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4225 "dhcp4_parser.cc"
    break;

  case 761: // $@121: %empty
#line 2651 "dhcp4_parser.yy"
                                       {
    ctx.unique("generated-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4234 "dhcp4_parser.cc"
    break;

  case 762: // dep_generated_prefix: "generated-prefix" $@121 ":" "constant string"
#line 2654 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("generated-prefix", s);
    ctx.leave();
}
#line 4244 "dhcp4_parser.cc"
    break;

  case 763: // $@122: %empty
#line 2661 "dhcp4_parser.yy"
                                         {
    ctx.unique("hostname-char-set", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4253 "dhcp4_parser.cc"
    break;

  case 764: // dep_hostname_char_set: "hostname-char-set" $@122 ":" "constant string"
#line 2664 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-set", s);
    ctx.leave();
}
#line 4263 "dhcp4_parser.cc"
    break;

  case 765: // $@123: %empty
#line 2671 "dhcp4_parser.yy"
                                                         {
    ctx.unique("hostname-char-replacement", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4272 "dhcp4_parser.cc"
    break;

  case 766: // dep_hostname_char_replacement: "hostname-char-replacement" $@123 ":" "constant string"
#line 2674 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-replacement", s);
    ctx.leave();
}
#line 4282 "dhcp4_parser.cc"
    break;

  case 767: // $@124: %empty
#line 2683 "dhcp4_parser.yy"
                               {
    ctx.unique("config-control", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-control", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.CONFIG_CONTROL);
}
#line 4294 "dhcp4_parser.cc"
    break;

  case 768: // config_control: "config-control" $@124 ":" "{" config_control_params "}"
#line 2689 "dhcp4_parser.yy"
                                                            {
    // No config control params are required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4304 "dhcp4_parser.cc"
    break;

  case 769: // $@125: %empty
#line 2695 "dhcp4_parser.yy"
                                   {
    // Parse the config-control map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 4314 "dhcp4_parser.cc"
    break;

  case 770: // sub_config_control: "{" $@125 config_control_params "}"
#line 2699 "dhcp4_parser.yy"
                                       {
    // No config_control params are required
    // parsing completed
}
#line 4323 "dhcp4_parser.cc"
    break;

  case 773: // config_control_params: config_control_params ","
#line 2707 "dhcp4_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 4331 "dhcp4_parser.cc"
    break;

  case 776: // $@126: %empty
#line 2717 "dhcp4_parser.yy"
                                   {
    ctx.unique("config-databases", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-databases", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.CONFIG_DATABASE);
}
#line 4343 "dhcp4_parser.cc"
    break;

  case 777: // config_databases: "config-databases" $@126 ":" "[" database_list "]"
#line 2723 "dhcp4_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4352 "dhcp4_parser.cc"
    break;

  case 778: // config_fetch_wait_time: "config-fetch-wait-time" ":" "integer"
#line 2728 "dhcp4_parser.yy"
                                                             {
    ctx.unique("config-fetch-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-fetch-wait-time", value);
}
#line 4362 "dhcp4_parser.cc"
    break;

  case 779: // $@127: %empty
#line 2736 "dhcp4_parser.yy"
                 {
    ctx.unique("loggers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("loggers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.LOGGERS);
}
#line 4374 "dhcp4_parser.cc"
    break;

  case 780: // loggers: "loggers" $@127 ":" "[" loggers_entries "]"
#line 2742 "dhcp4_parser.yy"
                                                         {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4383 "dhcp4_parser.cc"
    break;

  case 783: // loggers_entries: loggers_entries ","
#line 2751 "dhcp4_parser.yy"
                                       {
                   ctx.warnAboutExtraCommas(yystack_[0].location);
                   }
#line 4391 "dhcp4_parser.cc"
    break;

  case 784: // $@128: %empty
#line 2757 "dhcp4_parser.yy"
                             {
    ElementPtr l(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(l);
    ctx.stack_.push_back(l);
}
#line 4401 "dhcp4_parser.cc"
    break;

  case 785: // logger_entry: "{" $@128 logger_params "}"
#line 2761 "dhcp4_parser.yy"
                               {
    ctx.stack_.pop_back();
}
#line 4409 "dhcp4_parser.cc"
    break;

  case 788: // logger_params: logger_params ","
#line 2767 "dhcp4_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 4417 "dhcp4_parser.cc"
    break;

  case 796: // debuglevel: "debuglevel" ":" "integer"
#line 2781 "dhcp4_parser.yy"
                                     {
    ctx.unique("debuglevel", ctx.loc2pos(yystack_[2].location));
    ElementPtr dl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("debuglevel", dl);
}
#line 4427 "dhcp4_parser.cc"
    break;

  case 797: // $@129: %empty
#line 2787 "dhcp4_parser.yy"
                   {
    ctx.unique("severity", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4436 "dhcp4_parser.cc"
    break;

  case 798: // severity: "severity" $@129 ":" "constant string"
#line 2790 "dhcp4_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("severity", sev);
    ctx.leave();
}
#line 4446 "dhcp4_parser.cc"
    break;

  case 799: // $@130: %empty
#line 2796 "dhcp4_parser.yy"
                                    {
    ctx.unique("output_options", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output_options", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OUTPUT_OPTIONS);
}
#line 4458 "dhcp4_parser.cc"
    break;

  case 800: // output_options_list: "output_options" $@130 ":" "[" output_options_list_content "]"
#line 2802 "dhcp4_parser.yy"
                                                                    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4467 "dhcp4_parser.cc"
    break;

  case 803: // output_options_list_content: output_options_list_content ","
#line 2809 "dhcp4_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 4475 "dhcp4_parser.cc"
    break;

  case 804: // $@131: %empty
#line 2814 "dhcp4_parser.yy"
                             {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 4485 "dhcp4_parser.cc"
    break;

  case 805: // output_entry: "{" $@131 output_params_list "}"
#line 2818 "dhcp4_parser.yy"
                                    {
    ctx.stack_.pop_back();
}
#line 4493 "dhcp4_parser.cc"
    break;

  case 808: // output_params_list: output_params_list ","
#line 2824 "dhcp4_parser.yy"
                                             {
                      ctx.warnAboutExtraCommas(yystack_[0].location);
                      }
#line 4501 "dhcp4_parser.cc"
    break;

  case 814: // $@132: %empty
#line 2836 "dhcp4_parser.yy"
               {
    ctx.unique("output", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4510 "dhcp4_parser.cc"
    break;

  case 815: // output: "output" $@132 ":" "constant string"
#line 2839 "dhcp4_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output", sev);
    ctx.leave();
}
#line 4520 "dhcp4_parser.cc"
    break;

  case 816: // flush: "flush" ":" "boolean"
#line 2845 "dhcp4_parser.yy"
                           {
    ctx.unique("flush", ctx.loc2pos(yystack_[2].location));
    ElementPtr flush(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush", flush);
}
#line 4530 "dhcp4_parser.cc"
    break;

  case 817: // maxsize: "maxsize" ":" "integer"
#line 2851 "dhcp4_parser.yy"
                               {
    ctx.unique("maxsize", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxsize(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxsize", maxsize);
}
#line 4540 "dhcp4_parser.cc"
    break;

  case 818: // maxver: "maxver" ":" "integer"
#line 2857 "dhcp4_parser.yy"
                             {
    ctx.unique("maxver", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxver(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxver", maxver);
}
#line 4550 "dhcp4_parser.cc"
    break;

  case 819: // $@133: %empty
#line 2863 "dhcp4_parser.yy"
                 {
    ctx.unique("pattern", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4559 "dhcp4_parser.cc"
    break;

  case 820: // pattern: "pattern" $@133 ":" "constant string"
#line 2866 "dhcp4_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pattern", sev);
    ctx.leave();
}
#line 4569 "dhcp4_parser.cc"
    break;

  case 821: // $@134: %empty
#line 2872 "dhcp4_parser.yy"
                             {
    ctx.unique("compatibility", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("compatibility", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.COMPATIBILITY);
}
#line 4581 "dhcp4_parser.cc"
    break;

  case 822: // compatibility: "compatibility" $@134 ":" "{" compatibility_params "}"
#line 2878 "dhcp4_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4590 "dhcp4_parser.cc"
    break;

  case 825: // compatibility_params: compatibility_params ","
#line 2885 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 4598 "dhcp4_parser.cc"
    break;

  case 829: // lenient_option_parsing: "lenient-option-parsing" ":" "boolean"
#line 2895 "dhcp4_parser.yy"
                                                             {
    ctx.unique("lenient-option-parsing", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lenient-option-parsing", b);
}
#line 4608 "dhcp4_parser.cc"
    break;

  case 830: // ignore-rai-link-selection: "ignore-rai-link-selection" ":" "boolean"
#line 2901 "dhcp4_parser.yy"
                                                             {
    ctx.unique("ignore-rai-link-selection", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ignore-rai-link-selection", b);
}
#line 4618 "dhcp4_parser.cc"
    break;


#line 4622 "dhcp4_parser.cc"

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
  Dhcp4Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Dhcp4Parser::yytnamerr_ (const char *yystr)
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
  Dhcp4Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Dhcp4Parser::context.
  Dhcp4Parser::context::context (const Dhcp4Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Dhcp4Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
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
  Dhcp4Parser::yy_syntax_error_arguments_ (const context& yyctx,
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
  Dhcp4Parser::yysyntax_error_ (const context& yyctx) const
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


  const short Dhcp4Parser::yypact_ninf_ = -978;

  const signed char Dhcp4Parser::yytable_ninf_ = -1;

  const short
  Dhcp4Parser::yypact_[] =
  {
     421,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,    44,    31,    39,    41,    59,    72,
      82,    84,    88,    94,   103,   106,   124,   128,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,    31,  -134,   155,   107,   130,   242,
     110,   481,    79,   156,   174,  -101,   488,   302,  -978,   194,
     199,   200,   202,   217,  -978,    66,  -978,  -978,  -978,  -978,
     222,   224,   246,  -978,  -978,  -978,  -978,  -978,  -978,   258,
     267,   277,   298,   322,   373,   397,   417,   419,   429,   435,
    -978,   441,   442,   445,   447,   448,  -978,  -978,  -978,   449,
     450,   451,  -978,  -978,  -978,   452,  -978,  -978,  -978,  -978,
     456,   459,   460,  -978,  -978,  -978,  -978,  -978,   462,  -978,
    -978,  -978,  -978,  -978,  -978,   463,   464,   466,  -978,  -978,
     469,  -978,    85,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
     474,   475,   476,   482,  -978,    89,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,   485,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
      95,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   112,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,   235,   229,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   284,
    -978,  -978,   487,  -978,  -978,  -978,   490,  -978,  -978,   333,
     365,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,   491,   494,   496,  -978,  -978,  -978,
    -978,   477,   498,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,   120,  -978,  -978,  -978,
     499,  -978,  -978,   500,  -978,   501,   503,  -978,  -978,   505,
     506,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   189,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,   508,   239,  -978,  -978,
    -978,  -978,    31,    31,  -978,   310,   513,  -978,  -978,   521,
     523,   524,   321,   324,   326,   525,   532,   536,   538,   539,
     541,   339,   343,   348,   349,   353,   344,   355,   357,   358,
     361,   369,   567,   371,   374,   375,   378,   379,   569,   576,
     578,   380,   381,   382,   579,   590,   591,   389,   593,   594,
     596,   597,   393,   394,   395,   601,   608,   623,   624,   625,
     423,   627,   628,   629,   630,   631,   632,   431,   432,   433,
     634,   639,  -978,   107,  -978,   654,   655,   656,   453,   454,
     461,   465,   130,  -978,   662,   663,   665,   666,   667,   671,
     470,   674,   675,   678,   242,  -978,   679,   110,  -978,   680,
     681,   682,   684,   685,   686,   687,   688,  -978,   481,  -978,
     689,   695,   495,   697,   699,   700,   472,  -978,   156,   701,
     497,   504,   507,  -978,   174,   708,   710,   264,  -978,   509,
     711,   713,   512,   716,   514,   515,   719,   720,   516,   517,
     723,   724,   725,   726,   488,  -978,   727,   526,   302,  -978,
    -978,  -978,   728,   741,   742,   743,   744,  -978,  -978,  -978,
     556,   557,   558,   758,   761,   764,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,   564,  -978,  -978,
    -978,  -978,  -978,  -122,   565,   566,  -978,  -978,  -978,   768,
     769,   770,  -978,   771,   772,   571,   317,  -978,  -978,  -978,
     773,   775,   778,   780,   781,  -978,   782,   783,   787,   788,
     581,   592,  -978,  -978,  -978,   792,   794,  -978,   797,   396,
     411,  -978,  -978,  -978,  -978,  -978,   598,   599,   600,   798,
     603,   604,  -978,   797,   605,   800,  -978,   606,  -978,   797,
     607,   609,   610,   611,   612,   613,   614,  -978,   615,   616,
    -978,   617,   618,   619,  -978,  -978,   620,  -978,  -978,  -978,
    -978,   621,   772,  -978,  -978,   622,   626,  -978,   633,  -978,
    -978,    23,   643,  -978,  -978,  -122,   635,   636,   637,  -978,
     824,  -978,  -978,    31,   107,   302,   130,   410,  -978,  -978,
    -978,   346,   346,   823,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,   826,   827,   828,   829,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,    34,   830,   831,   833,   -58,
     153,   228,     3,   488,  -978,  -978,   837,  -135,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   838,
    -978,  -978,  -978,  -978,   311,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,   823,  -978,   274,   286,   287,  -978,  -978,
     288,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   795,   842,
     843,   844,   845,   846,   847,  -978,   848,  -978,  -978,  -978,
    -978,  -978,   290,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,   327,  -978,   825,   852,  -978,  -978,   850,   854,
    -978,  -978,   853,   855,  -978,  -978,   856,   857,  -978,  -978,
     858,   860,  -978,  -978,  -978,  -978,  -978,  -978,   144,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,   145,  -978,  -978,   859,
     863,  -978,  -978,   861,   865,  -978,   866,   867,   868,   869,
     870,   871,   331,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
     872,   873,   874,  -978,   334,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,   335,  -978,  -978,  -978,
     875,  -978,   876,  -978,  -978,  -978,   337,  -978,  -978,  -978,
    -978,  -978,   352,  -978,   160,  -978,   877,   878,  -978,   364,
    -978,  -978,  -978,   683,  -978,   879,   881,  -978,  -978,  -978,
    -978,   880,   884,  -978,  -978,  -978,   882,   883,   410,  -978,
     887,   888,   889,   890,   690,   652,   691,   660,   692,   693,
     694,   891,   696,   892,   898,   900,   901,   346,  -978,  -978,
     346,  -978,   823,   242,  -978,   826,   156,  -978,   827,   174,
    -978,   828,   677,  -978,   829,    34,  -978,   320,   830,  -978,
     481,  -978,   831,  -101,  -978,   833,   702,   703,   704,   705,
     706,   707,   -58,  -978,   698,   714,   717,   153,  -978,   902,
     904,   228,  -978,   709,   911,   732,   913,     3,  -978,  -978,
      21,   837,  -978,   734,   737,  -135,  -978,  -978,   914,   929,
     110,  -978,   838,   955,  -978,  -978,   796,   799,  -978,   178,
     801,   862,   864,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
     332,  -978,   885,   886,   893,   894,  -978,   366,  -978,   367,
    -978,   956,  -978,   971,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   368,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,   977,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,   976,   990,  -978,  -978,  -978,  -978,
    -978,  -978,  1041,  -978,   404,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,   895,   896,  -978,
    -978,   897,  -978,    31,  -978,  -978,  1047,  -978,  -978,  -978,
    -978,  -978,   408,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,   899,   412,  -978,   797,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,   677,  -978,  1050,
    1052,   849,  -978,   320,  -978,  -978,  -978,  -978,  -978,  -978,
    1055,   903,  1057,    21,  -978,  -978,  -978,  -978,  -978,   905,
     906,  -978,  -978,  1058,  -978,   907,  -978,  -978,  -978,  1059,
    -978,  -978,   195,  -978,  -128,  1059,  -978,  -978,  1060,  1061,
    1063,  -978,   414,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    1065,   908,   909,   912,  1067,  -128,  -978,   915,  -978,  -978,
    -978,   916,  -978,  -978,  -978
  };

  const short
  Dhcp4Parser::yydefact_[] =
  {
       0,     2,     4,     6,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,    44,
      36,    32,    31,    28,    29,    30,    35,     3,    33,    34,
      59,     5,    65,     7,   192,     9,   364,    11,   574,    13,
     601,    15,   492,    17,   501,    19,   540,    21,   326,    23,
     718,    25,   769,    27,    46,    39,     0,     0,     0,     0,
       0,   603,     0,   503,   542,     0,     0,     0,    48,     0,
      47,     0,     0,    40,    61,     0,    63,   767,   177,   210,
       0,     0,     0,   623,   625,   627,   208,   221,   223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,     0,     0,   154,   161,   163,     0,
       0,     0,   355,   490,   531,     0,   438,   588,   590,   431,
       0,     0,     0,   288,   651,   592,   317,   338,     0,   303,
     685,   699,   716,   167,   169,     0,     0,     0,   779,   821,
       0,   133,     0,    67,    70,    71,    72,    73,    74,   108,
     109,   110,   111,   112,    75,   103,   132,    92,    93,    94,
     116,   117,   118,   119,   120,   121,   122,   123,   114,   115,
     124,   125,   126,   128,   129,   130,    78,    79,   100,    80,
      81,    82,   127,    86,    87,    76,   105,   106,   107,   104,
      77,    84,    85,    98,    99,   101,    95,    96,    97,    83,
      88,    89,    90,    91,   102,   113,   131,   194,   196,   200,
       0,     0,     0,     0,   191,     0,   179,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   416,   418,   420,   565,
     414,   422,     0,   426,   424,   647,   413,   369,   370,   371,
     372,   373,   397,   398,   399,   400,   401,   387,   388,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
       0,   366,   376,   392,   393,   394,   377,   379,   380,   383,
     384,   385,   382,   378,   374,   375,   395,   396,   381,   389,
     390,   391,   386,   586,   585,   581,   582,   580,     0,   576,
     579,   583,   584,   645,   633,   635,   639,   637,   643,   641,
     629,   622,   616,   620,   621,     0,   604,   605,   617,   618,
     619,   613,   608,   614,   610,   611,   612,   615,   609,     0,
     521,   266,     0,   525,   523,   528,     0,   517,   518,     0,
     504,   505,   508,   520,   509,   510,   511,   527,   512,   513,
     514,   515,   516,   558,     0,     0,     0,   556,   557,   560,
     561,     0,   543,   544,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   334,   336,   331,     0,   328,   332,   333,
       0,   755,   742,     0,   745,     0,     0,   749,   753,     0,
       0,   759,   761,   763,   765,   740,   738,   739,     0,   720,
     723,   724,   725,   726,   727,   728,   729,   730,   735,   731,
     732,   733,   734,   736,   737,   776,     0,     0,   771,   774,
     775,    45,    50,     0,    37,    43,     0,    64,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    69,    66,     0,     0,     0,     0,     0,
       0,     0,   181,   193,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   368,   365,     0,   578,   575,     0,
       0,     0,     0,     0,     0,     0,     0,   602,   607,   493,
       0,     0,     0,     0,     0,     0,     0,   502,   507,     0,
       0,     0,     0,   541,   546,     0,     0,   330,   327,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   722,   719,     0,     0,   773,   770,
      49,    41,     0,     0,     0,     0,     0,   148,   149,   150,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,   172,   173,
     151,   152,   153,     0,     0,     0,   165,   166,   171,     0,
       0,     0,   147,     0,     0,     0,     0,   428,   429,   430,
       0,     0,     0,     0,     0,   684,     0,     0,     0,     0,
       0,     0,   174,   175,   176,     0,     0,    68,     0,     0,
       0,   204,   205,   206,   207,   180,     0,     0,     0,     0,
       0,     0,   437,     0,     0,     0,   367,     0,   577,     0,
       0,     0,     0,     0,     0,     0,     0,   606,     0,     0,
     519,     0,     0,     0,   530,   506,     0,   562,   563,   564,
     545,     0,     0,   329,   741,     0,     0,   744,     0,   747,
     748,     0,     0,   757,   758,     0,     0,     0,     0,   721,
       0,   778,   772,     0,     0,     0,     0,     0,   624,   626,
     628,     0,     0,   225,   146,   156,   157,   158,   159,   160,
     155,   162,   164,   357,   494,   533,   440,    38,   589,   591,
     433,   434,   435,   436,   432,     0,     0,   594,   319,     0,
       0,     0,     0,     0,   168,   170,     0,     0,    51,   195,
     198,   199,   197,   202,   203,   201,   417,   419,   421,   567,
     415,   423,   427,   425,     0,   587,   646,   634,   636,   640,
     638,   644,   642,   630,   522,   267,   526,   524,   529,   559,
     335,   337,   756,   743,   746,   751,   752,   750,   754,   760,
     762,   764,   766,   225,    42,     0,     0,     0,   217,   219,
       0,   212,   215,   216,   254,   259,   261,   263,     0,     0,
       0,     0,     0,     0,     0,   274,     0,   280,   282,   284,
     286,   253,     0,   232,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,   230,     0,   226,   227,   362,     0,   358,
     359,   499,     0,   495,   496,   538,     0,   534,   535,   445,
       0,   441,   442,   298,   299,   300,   301,   302,     0,   290,
     293,   294,   295,   296,   297,   656,     0,   653,   599,     0,
     595,   596,   324,     0,   320,   321,     0,     0,     0,     0,
       0,     0,     0,   340,   343,   344,   345,   346,   347,   348,
       0,     0,     0,   313,     0,   305,   308,   309,   310,   311,
     312,   695,   697,   694,   692,   693,     0,   687,   690,   691,
       0,   711,     0,   714,   707,   708,     0,   701,   704,   705,
     706,   709,     0,   784,     0,   781,     0,     0,   828,     0,
     823,   826,   827,    53,   572,     0,   568,   569,   631,   649,
     650,     0,     0,    62,   768,   178,     0,     0,   214,   211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,   209,   222,
       0,   224,   229,     0,   356,   361,   503,   491,   498,   542,
     532,   537,     0,   439,   444,   292,   289,   658,   655,   652,
     603,   593,   598,     0,   318,   323,     0,     0,     0,     0,
       0,     0,   342,   339,     0,     0,     0,   307,   304,     0,
       0,   689,   686,     0,     0,     0,     0,   703,   700,   717,
       0,   783,   780,     0,     0,   825,   822,    55,     0,    54,
       0,   566,   571,     0,   648,   777,     0,     0,   213,     0,
       0,     0,     0,   265,   268,   269,   270,   271,   272,   273,
       0,   279,     0,     0,     0,     0,   233,     0,   228,     0,
     360,     0,   497,     0,   536,   489,   468,   469,   470,   453,
     454,   473,   474,   475,   476,   477,   456,   457,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   450,
     451,   452,   466,   467,   463,   464,   465,   462,     0,   447,
     455,   471,   472,   458,   459,   460,   461,   443,   291,   679,
     681,     0,   674,   675,   676,   677,   678,   667,   668,   672,
     673,   669,   670,   671,     0,   659,   660,   663,   664,   665,
     666,   654,     0,   597,     0,   322,   349,   350,   351,   352,
     353,   354,   341,   314,   315,   316,   306,     0,     0,   688,
     710,     0,   713,     0,   702,   799,     0,   797,   795,   789,
     793,   794,     0,   786,   791,   792,   790,   782,   829,   830,
     824,    52,    57,     0,   570,     0,   218,   220,   256,   257,
     258,   255,   260,   262,   264,   276,   277,   278,   275,   281,
     283,   285,   287,   231,   363,   500,   539,   449,   446,     0,
       0,     0,   657,   662,   600,   325,   696,   698,   712,   715,
       0,     0,     0,   788,   785,    56,   573,   632,   448,     0,
       0,   683,   661,     0,   796,     0,   787,   680,   682,     0,
     798,   804,     0,   801,     0,   803,   800,   814,     0,     0,
       0,   819,     0,   806,   809,   810,   811,   812,   813,   802,
       0,     0,     0,     0,     0,   808,   805,     0,   816,   817,
     818,     0,   807,   815,   820
  };

  const short
  Dhcp4Parser::yypgoto_[] =
  {
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,   -59,  -978,  -582,  -978,   390,
    -978,  -978,  -978,  -978,  -978,  -978,  -637,  -978,  -978,  -978,
     -67,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   370,   580,
     -55,     7,    17,   -32,   -30,   -27,     4,     9,    25,    27,
    -978,  -978,  -978,  -978,  -978,    30,    33,    35,    37,    40,
      43,  -978,   383,    45,  -978,    47,  -978,    48,    50,    53,
    -978,    55,  -978,    58,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,   356,   573,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,   118,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,   289,  -978,    97,  -978,  -700,   100,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,   -63,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
      86,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,    67,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,    75,  -978,  -978,
    -978,    80,   540,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
      73,  -978,  -978,  -978,  -978,  -978,  -978,  -977,  -978,  -978,
    -978,   101,  -978,  -978,  -978,   105,   575,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -971,  -978,   -43,  -978,    20,
    -978,    60,    61,    63,    65,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,    96,  -978,  -978,  -114,   -39,  -978,  -978,  -978,
    -978,  -978,   108,  -978,  -978,  -978,   109,  -978,   559,  -978,
     -54,  -978,  -978,  -978,  -978,  -978,   -20,  -978,  -978,  -978,
    -978,  -978,   -52,  -978,  -978,  -978,   115,  -978,  -978,  -978,
     119,  -978,   550,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,    56,  -978,  -978,  -978,    69,
     640,  -978,  -978,   -45,  -978,    -6,  -978,   -56,  -978,  -978,
    -978,   113,  -978,  -978,  -978,   114,  -978,   595,   -26,  -978,
     -22,  -978,     6,  -978,   354,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -962,  -978,  -978,  -978,  -978,  -978,   122,  -978,
    -978,  -978,  -106,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,   104,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,    99,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,   384,   560,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,   424,   562,  -978,  -978,  -978,  -978,  -978,
    -978,   102,  -978,  -978,   -95,  -978,  -978,  -978,  -978,  -978,
    -978,  -113,  -978,  -978,  -131,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,   116,  -978,  -978
  };

  const short
  Dhcp4Parser::yydefgoto_[] =
  {
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    36,    37,    38,    65,   728,
      82,    83,    39,    64,    79,    80,   749,   943,  1038,  1039,
     821,    41,    66,    85,   426,    86,    43,    67,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   452,   166,   167,   168,   169,   170,   171,   172,
     173,   458,   720,   174,   459,   175,   460,   176,   177,   178,
     485,   179,   486,   180,   181,   182,   183,   184,   185,   186,
     430,   225,   226,    45,    68,   227,   495,   228,   496,   752,
     229,   497,   755,   230,   231,   232,   233,   187,   438,   188,
     431,   800,   801,   802,   956,   803,   957,   189,   439,   190,
     440,   844,   845,   846,   980,   822,   823,   824,   960,  1191,
     825,   961,   826,   962,   827,   963,   828,   829,   531,   830,
     831,   832,   833,   834,   835,   836,   971,  1198,   837,   838,
     973,   839,   974,   840,   975,   841,   976,   191,   475,   868,
     869,   870,   871,   872,   873,   874,   192,   481,   904,   905,
     906,   907,   908,   193,   478,   883,   884,   885,  1003,    59,
      75,   376,   377,   378,   545,   379,   546,   194,   479,   892,
     893,   894,   895,   896,   897,   898,   899,   195,   464,   848,
     849,   850,   983,    47,    69,   270,   271,   272,   508,   273,
     504,   274,   505,   275,   506,   276,   509,   277,   512,   278,
     511,   196,   197,   198,   199,   471,   734,   283,   200,   468,
     860,   861,   862,   992,  1108,  1109,   201,   465,    53,    72,
     852,   853,   854,   986,    55,    73,   339,   340,   341,   342,
     343,   344,   345,   530,   346,   534,   347,   533,   348,   349,
     535,   350,   202,   466,   856,   857,   858,   989,    57,    74,
     361,   362,   363,   364,   365,   539,   366,   367,   368,   369,
     370,   285,   507,   945,   946,   947,  1040,    49,    70,   298,
     299,   300,   516,   203,   469,   204,   470,   205,   477,   879,
     880,   881,  1000,    51,    71,   315,   316,   317,   206,   435,
     207,   436,   208,   437,   321,   526,   950,  1043,   322,   520,
     323,   521,   324,   523,   325,   522,   326,   525,   327,   524,
     328,   519,   292,   513,   951,   209,   476,   876,   877,   997,
    1134,  1135,  1136,  1137,  1138,  1209,  1139,  1210,  1140,   210,
     211,   482,   916,   917,   918,  1019,   919,  1020,   212,   483,
     926,   927,   928,   929,  1024,   930,   931,  1026,   213,   484,
      61,    76,   398,   399,   400,   401,   551,   402,   403,   553,
     404,   405,   406,   556,   787,   407,   557,   408,   550,   409,
     410,   411,   560,   412,   561,   413,   562,   414,   563,   214,
     429,    63,    77,   417,   418,   419,   566,   420,   215,   490,
     934,   935,  1030,  1172,  1173,  1174,  1175,  1222,  1176,  1220,
    1242,  1243,  1244,  1252,  1253,  1254,  1260,  1255,  1256,  1257,
    1258,  1264,   216,   491,   939,   940,   941,   942
  };

  const short
  Dhcp4Parser::yytable_[] =
  {
     151,   224,   246,   294,   311,    78,   337,   357,   375,   395,
     338,   358,   842,   288,   247,  1100,   762,   284,   297,   312,
     359,  1101,   766,   234,   286,   301,   313,   295,   351,   371,
    1116,   396,   727,   329,   373,   374,    29,   250,    30,   251,
      31,   785,   252,   289,    28,   318,    40,   290,    42,   319,
     715,   716,   717,   718,   360,  1247,   936,   937,  1248,  1249,
    1250,  1251,   235,   287,   302,   314,    44,   352,   372,   427,
     397,   150,    81,   253,   428,   291,   248,   320,   254,    46,
     886,   887,   888,   889,   890,   891,   249,   719,   493,    48,
     296,    50,   502,   494,   255,    52,   256,   503,   514,   257,
     727,    54,   258,   515,   259,   150,   260,   127,   128,   261,
      56,   331,   262,    58,   263,   517,   264,   265,    87,   266,
     518,    88,   267,   547,   268,   127,   128,   269,   548,   279,
     280,    60,   281,    89,   282,    62,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   217,   218,   995,   998,   219,
     996,   999,   220,   221,   222,   223,   920,   921,   922,   863,
     864,   865,   866,  1031,   867,    84,  1032,   123,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   564,   786,   330,   123,   124,   565,  1245,   124,
     421,  1246,   422,  1165,   423,  1166,  1167,   125,   126,   923,
     424,   127,   128,   293,   127,   128,   129,  1188,  1189,  1190,
     425,   130,   131,   132,   133,   134,   432,   150,   433,   243,
    1100,   135,   528,   244,   127,   128,  1101,    32,    33,    34,
      35,   136,   568,   527,   137,  1116,   331,   569,   332,   333,
     434,   138,   139,   334,   335,   336,   140,   127,   128,   141,
     127,   128,   441,   142,   331,   353,   332,   333,   354,   355,
     356,   442,    91,    92,    93,    94,    95,   493,   127,   128,
    1067,   443,   953,   143,   144,   145,   146,   147,   148,   568,
     502,   958,   529,   977,   954,   955,   959,   149,   978,   900,
     901,   902,   444,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   150,   415,   416,   150,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   445,   236,   237,   238,
     977,   124,   127,   128,  1012,   979,   150,  1017,  1021,  1013,
    1027,   537,  1018,  1022,   239,  1028,   127,   128,   240,   241,
     242,   129,    93,    94,    95,   564,   130,   131,   132,   150,
    1029,   243,   150,   570,   571,   244,   135,  1035,   538,   977,
     514,  1207,  1036,   245,  1203,  1204,  1208,   446,   911,   912,
     150,    99,   100,   101,   804,  1195,  1196,  1197,   805,   806,
     807,   808,   809,   810,   811,   812,   813,   814,   815,   373,
     374,   447,   816,   817,   818,   819,   820,   547,   123,   124,
     331,  1223,  1215,   750,   751,   517,  1224,  1265,   143,   144,
    1226,   448,  1266,   449,   127,   128,   151,   730,   731,   732,
     733,   753,   754,   450,   150,   224,   331,   798,   799,   451,
    1119,  1120,  1121,   310,   948,   453,   454,   246,   150,   455,
     294,   456,   457,   461,   462,   463,   467,   234,   288,   247,
     472,   311,   284,   473,   474,   297,   480,   487,   488,   286,
     489,   337,   301,   492,   295,   338,   312,   357,   498,   499,
     500,   358,   250,   313,   251,   543,   501,   252,   289,   510,
     359,   532,   290,   351,   536,   540,   235,   395,   541,   371,
     542,   544,   318,   549,   552,   554,   319,   555,   287,   558,
     559,   302,   567,    93,    94,    95,   572,   573,   253,   396,
     291,   248,   314,   254,   360,   574,   150,   575,   576,   580,
     577,   249,   352,   578,   320,   579,   581,   296,   372,   255,
     582,   256,   583,   584,   257,   585,   586,   258,  1227,   259,
     587,   260,   150,   591,   261,   588,   589,   262,   397,   263,
     590,   264,   265,   592,   266,   593,   594,   267,   595,   268,
     124,   597,   269,   603,   279,   280,   596,   281,   598,   282,
     604,   599,   605,   609,   600,   127,   128,   601,   602,   606,
     607,   608,   127,   128,   610,   611,   612,   613,   614,   303,
     615,   616,   617,   618,   619,   620,   304,   305,   306,   307,
     308,   309,   621,   310,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   151,   635,   224,
     632,   633,   634,   636,   794,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   638,   639,
     640,   234,   641,   642,   393,   394,   646,   647,   643,   648,
     649,   650,   644,   903,   913,   651,   395,   652,   653,   654,
     938,   674,   655,   657,   659,   660,   661,   150,   662,   663,
     664,   665,   666,   668,   150,   909,   914,   924,   396,   669,
     235,   671,   670,   672,   673,   676,   677,    91,    92,    93,
      94,    95,   681,   678,   682,   685,   679,   686,   684,   687,
     688,   689,   690,   691,   692,   693,   694,   695,   696,   697,
     698,   700,   703,   701,   910,   915,   925,   397,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   704,   705,
     706,   707,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   708,   709,   710,   711,   124,   331,   712,   713,
     714,   721,   722,   723,   724,   725,   726,   729,   735,    30,
     736,   127,   128,   737,   241,   738,   129,   744,   739,   740,
     741,   130,   131,   132,   742,   743,   243,   746,   745,   964,
     244,   747,   748,   759,   756,   757,   758,   764,   245,   760,
     761,   763,   765,   767,   788,   768,   769,   770,   771,   772,
     773,   774,   775,   776,   777,   778,   779,   780,   782,   793,
     843,   981,   783,   847,   851,   855,   859,   875,   878,   784,
     882,   790,   791,   792,   933,   944,   965,   966,   967,   968,
     969,   970,   972,   143,   144,   982,   984,   985,   988,   987,
     991,  1054,   990,   994,   993,  1001,  1002,  1004,  1005,  1056,
    1006,  1007,  1008,  1009,  1010,  1011,  1014,  1015,  1016,  1023,
    1025,  1033,  1034,   150,  1042,  1041,  1046,  1047,  1044,  1037,
    1045,  1049,  1050,  1051,  1052,  1060,  1062,  1053,  1055,  1057,
    1058,  1059,  1063,  1061,  1064,  1065,  1157,  1153,  1158,  1146,
    1147,  1148,  1149,  1150,  1151,  1161,   246,  1163,  1160,   337,
    1181,  1154,   357,   338,  1155,  1075,   358,   288,   247,  1099,
    1122,   284,  1182,   311,  1126,   359,   375,  1076,   286,  1162,
    1110,   351,  1123,  1178,   371,  1128,  1179,  1111,   312,  1102,
     903,   250,  1129,   251,   913,   313,   252,   289,  1127,  1185,
    1079,   290,  1080,  1168,  1205,  1081,  1113,  1169,   938,   360,
    1114,  1131,   909,   294,   318,  1132,   914,   287,   319,  1206,
     352,  1211,   924,   372,  1212,  1170,  1112,   253,   297,   291,
     248,  1130,   254,  1213,   314,   301,  1082,   295,  1115,  1077,
     249,  1083,  1186,  1133,  1124,  1187,   320,  1192,   255,  1078,
     256,   910,  1103,   257,  1125,   915,   258,  1084,   259,  1085,
     260,   925,  1086,   261,  1171,  1087,   262,  1088,   263,  1089,
     264,   265,  1090,   266,   302,  1091,   267,  1092,   268,  1093,
    1094,   269,  1095,   279,   280,  1096,   281,  1097,   282,  1214,
    1098,  1221,  1104,  1105,  1229,  1106,  1230,  1107,  1231,  1233,
     296,  1235,   797,  1239,  1261,  1262,  1241,  1263,  1193,  1267,
    1194,  1271,   781,   637,   795,   645,  1048,  1066,   789,  1068,
    1145,  1118,   952,  1144,  1156,  1152,  1070,   683,  1069,   656,
    1117,  1199,  1200,  1228,   680,  1071,  1072,   675,  1184,  1201,
    1202,  1216,  1217,  1218,  1219,  1225,  1074,  1232,  1073,  1183,
    1234,  1237,  1238,  1240,  1142,  1143,  1269,  1268,   949,  1270,
    1141,  1273,  1274,   667,   699,  1159,  1164,   932,  1236,   796,
     702,     0,  1259,  1177,  1272,     0,     0,     0,     0,     0,
    1075,     0,     0,     0,  1099,     0,  1122,     0,     0,     0,
    1126,  1180,  1076,     0,     0,  1110,  1168,   658,  1123,     0,
    1169,  1128,  1111,     0,  1102,     0,     0,     0,  1129,     0,
       0,     0,     0,     0,  1127,  1079,     0,  1080,  1170,     0,
    1081,  1113,     0,     0,     0,  1114,     0,  1131,     0,     0,
       0,  1132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1112,     0,     0,     0,     0,     0,  1130,     0,     0,
       0,  1082,     0,  1115,  1077,     0,  1083,  1171,     0,  1133,
    1124,     0,     0,     0,  1078,     0,     0,  1103,     0,     0,
    1125,     0,  1084,     0,  1085,     0,     0,  1086,     0,     0,
    1087,     0,  1088,     0,  1089,     0,     0,  1090,     0,     0,
    1091,     0,  1092,     0,  1093,  1094,     0,  1095,     0,     0,
    1096,     0,  1097,     0,     0,  1098,     0,  1104,  1105,     0,
    1106,     0,  1107
  };

  const short
  Dhcp4Parser::yycheck_[] =
  {
      67,    68,    69,    70,    71,    64,    73,    74,    75,    76,
      73,    74,   712,    69,    69,   992,   653,    69,    70,    71,
      74,   992,   659,    68,    69,    70,    71,    70,    73,    74,
     992,    76,   614,    72,   135,   136,     5,    69,     7,    69,
       9,    18,    69,    69,     0,    71,     7,    69,     7,    71,
     172,   173,   174,   175,    74,   183,   191,   192,   186,   187,
     188,   189,    68,    69,    70,    71,     7,    73,    74,     3,
      76,   206,   206,    69,     8,    69,    69,    71,    69,     7,
     138,   139,   140,   141,   142,   143,    69,   209,     3,     7,
      70,     7,     3,     8,    69,     7,    69,     8,     3,    69,
     682,     7,    69,     8,    69,   206,    69,   104,   105,    69,
       7,    90,    69,     7,    69,     3,    69,    69,    11,    69,
       8,    14,    69,     3,    69,   104,   105,    69,     8,    69,
      69,     7,    69,    26,    69,     7,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    15,    16,     3,     3,    19,
       6,     6,    22,    23,    24,    25,   153,   154,   155,   125,
     126,   127,   128,     3,   130,    10,     6,    88,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     3,   170,    38,    88,    89,     8,     3,    89,
       6,     6,     3,   182,     4,   184,   185,   100,   101,   206,
       8,   104,   105,   103,   104,   105,   109,    39,    40,    41,
       3,   114,   115,   116,   117,   118,     4,   206,     4,   119,
    1207,   124,     3,   123,   104,   105,  1207,   206,   207,   208,
     209,   134,     3,     8,   137,  1207,    90,     8,    92,    93,
       4,   144,   145,    97,    98,    99,   149,   104,   105,   152,
     104,   105,     4,   156,    90,    91,    92,    93,    94,    95,
      96,     4,    30,    31,    32,    33,    34,     3,   104,   105,
     980,     4,     8,   176,   177,   178,   179,   180,   181,     3,
       3,     3,     8,     3,     8,     8,     8,   190,     8,   146,
     147,   148,     4,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,   206,    12,    13,   206,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     4,    85,    86,    87,
       3,    89,   104,   105,     3,     8,   206,     3,     3,     8,
       3,     8,     8,     8,   102,     8,   104,   105,   106,   107,
     108,   109,    32,    33,    34,     3,   114,   115,   116,   206,
       8,   119,   206,   422,   423,   123,   124,     3,     3,     3,
       3,     3,     8,   131,     8,     8,     8,     4,   150,   151,
     206,    61,    62,    63,    38,    53,    54,    55,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,   135,
     136,     4,    56,    57,    58,    59,    60,     3,    88,    89,
      90,     3,     8,    17,    18,     3,     8,     3,   176,   177,
       8,     4,     8,     4,   104,   105,   493,   110,   111,   112,
     113,    20,    21,     4,   206,   502,    90,    27,    28,     4,
     120,   121,   122,   132,   133,     4,     4,   514,   206,     4,
     517,     4,     4,     4,     4,     4,     4,   502,   514,   514,
       4,   528,   514,     4,     4,   517,     4,     4,     4,   514,
       4,   538,   517,     4,   517,   538,   528,   544,     4,     4,
       4,   544,   514,   528,   514,     8,     4,   514,   514,     4,
     544,     4,   514,   538,     4,     4,   502,   564,     4,   544,
       4,     3,   528,     4,     4,     4,   528,     4,   514,     4,
       4,   517,     4,    32,    33,    34,   206,     4,   514,   564,
     514,   514,   528,   514,   544,     4,   206,     4,     4,     4,
     209,   514,   538,   209,   528,   209,     4,   517,   544,   514,
       4,   514,     4,     4,   514,     4,   207,   514,  1185,   514,
     207,   514,   206,   209,   514,   207,   207,   514,   564,   514,
     207,   514,   514,   208,   514,   208,   208,   514,   207,   514,
      89,     4,   514,     4,   514,   514,   207,   514,   207,   514,
       4,   207,     4,     4,   209,   104,   105,   209,   209,   209,
     209,   209,   104,   105,     4,     4,   207,     4,     4,   118,
       4,     4,   209,   209,   209,     4,   125,   126,   127,   128,
     129,   130,     4,   132,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,     4,     4,     4,
     207,     4,     4,     4,     4,     4,     4,   704,     4,   706,
     209,   209,   209,     4,   703,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,     4,     4,
       4,   706,   209,   209,   176,   177,     4,     4,   207,     4,
       4,     4,   207,   740,   741,     4,   743,   207,     4,     4,
     747,   209,     4,     4,     4,     4,     4,   206,     4,     4,
       4,     4,     4,     4,   206,   740,   741,   742,   743,     4,
     706,     4,   207,     4,     4,     4,   209,    30,    31,    32,
      33,    34,     4,   209,     4,     4,   209,     4,   209,   207,
       4,   207,   207,     4,     4,   209,   209,     4,     4,     4,
       4,     4,     4,   207,   740,   741,   742,   743,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     7,     7,
       7,     7,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   206,   206,   206,     7,    89,    90,     7,     5,
     206,   206,   206,     5,     5,     5,     5,   206,     5,     7,
       5,   104,   105,     5,   107,     5,   109,   206,     7,     7,
       7,   114,   115,   116,     7,     7,   119,     5,   206,     4,
     123,     7,     5,     5,   206,   206,   206,     7,   131,   206,
     206,   206,   206,   206,   171,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,     5,
       7,     6,   206,     7,     7,     7,     7,     7,     7,   206,
       7,   206,   206,   206,     7,     7,     4,     4,     4,     4,
       4,     4,     4,   176,   177,     3,     6,     3,     3,     6,
       3,   209,     6,     3,     6,     6,     3,     6,     3,   209,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,   206,     3,     6,     4,     4,     8,   206,
       6,     4,     4,     4,     4,     4,     4,   207,   207,   207,
     207,   207,     4,   207,     4,     4,     4,   209,     4,   207,
     207,   207,   207,   207,   207,     4,   983,     4,   209,   986,
       6,   207,   989,   986,   207,   992,   989,   983,   983,   992,
     997,   983,     3,  1000,   997,   989,  1003,   992,   983,   207,
     992,   986,   997,   209,   989,   997,   209,   992,  1000,   992,
    1017,   983,   997,   983,  1021,  1000,   983,   983,   997,     4,
     992,   983,   992,  1030,     8,   992,   992,  1030,  1035,   989,
     992,   997,  1017,  1040,  1000,   997,  1021,   983,  1000,     8,
     986,     4,  1027,   989,     8,  1030,   992,   983,  1040,   983,
     983,   997,   983,     3,  1000,  1040,   992,  1040,   992,   992,
     983,   992,   206,   997,   997,   206,  1000,   206,   983,   992,
     983,  1017,   992,   983,   997,  1021,   983,   992,   983,   992,
     983,  1027,   992,   983,  1030,   992,   983,   992,   983,   992,
     983,   983,   992,   983,  1040,   992,   983,   992,   983,   992,
     992,   983,   992,   983,   983,   992,   983,   992,   983,     8,
     992,     4,   992,   992,     4,   992,     4,   992,   209,     4,
    1040,     4,   706,     5,     4,     4,     7,     4,   206,     4,
     206,     4,   682,   493,   704,   502,   958,   977,   695,   982,
    1005,   995,   793,  1003,  1017,  1012,   985,   547,   983,   514,
     994,   206,   206,  1207,   544,   986,   988,   538,  1042,   206,
     206,   206,   206,   206,  1163,   206,   991,  1213,   989,  1040,
     207,   206,   206,   206,  1000,  1002,   207,   209,   764,   207,
     998,   206,   206,   528,   564,  1021,  1027,   743,  1223,   705,
     568,    -1,  1245,  1031,  1265,    -1,    -1,    -1,    -1,    -1,
    1207,    -1,    -1,    -1,  1207,    -1,  1213,    -1,    -1,    -1,
    1213,  1035,  1207,    -1,    -1,  1207,  1223,   517,  1213,    -1,
    1223,  1213,  1207,    -1,  1207,    -1,    -1,    -1,  1213,    -1,
      -1,    -1,    -1,    -1,  1213,  1207,    -1,  1207,  1223,    -1,
    1207,  1207,    -1,    -1,    -1,  1207,    -1,  1213,    -1,    -1,
      -1,  1213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1207,    -1,    -1,    -1,    -1,    -1,  1213,    -1,    -1,
      -1,  1207,    -1,  1207,  1207,    -1,  1207,  1223,    -1,  1213,
    1213,    -1,    -1,    -1,  1207,    -1,    -1,  1207,    -1,    -1,
    1213,    -1,  1207,    -1,  1207,    -1,    -1,  1207,    -1,    -1,
    1207,    -1,  1207,    -1,  1207,    -1,    -1,  1207,    -1,    -1,
    1207,    -1,  1207,    -1,  1207,  1207,    -1,  1207,    -1,    -1,
    1207,    -1,  1207,    -1,    -1,  1207,    -1,  1207,  1207,    -1,
    1207,    -1,  1207
  };

  const short
  Dhcp4Parser::yystos_[] =
  {
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,     0,     5,
       7,     9,   206,   207,   208,   209,   225,   226,   227,   232,
       7,   241,     7,   246,     7,   293,     7,   403,     7,   487,
       7,   503,     7,   438,     7,   444,     7,   468,     7,   379,
       7,   570,     7,   601,   233,   228,   242,   247,   294,   404,
     488,   504,   439,   445,   469,   380,   571,   602,   225,   234,
     235,   206,   230,   231,    10,   243,   245,    11,    14,    26,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    88,    89,   100,   101,   104,   105,   109,
     114,   115,   116,   117,   118,   124,   134,   137,   144,   145,
     149,   152,   156,   176,   177,   178,   179,   180,   181,   190,
     206,   240,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   263,   264,   265,   266,
     267,   268,   269,   270,   273,   275,   277,   278,   279,   281,
     283,   284,   285,   286,   287,   288,   289,   307,   309,   317,
     319,   357,   366,   373,   387,   397,   421,   422,   423,   424,
     428,   436,   462,   493,   495,   497,   508,   510,   512,   535,
     549,   550,   558,   568,   599,   608,   632,    15,    16,    19,
      22,    23,    24,    25,   240,   291,   292,   295,   297,   300,
     303,   304,   305,   306,   493,   495,    85,    86,    87,   102,
     106,   107,   108,   119,   123,   131,   240,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   265,   266,   267,
     268,   269,   270,   273,   275,   277,   278,   279,   281,   283,
     405,   406,   407,   409,   411,   413,   415,   417,   419,   421,
     422,   423,   424,   427,   462,   481,   493,   495,   497,   508,
     510,   512,   532,   103,   240,   417,   419,   462,   489,   490,
     491,   493,   495,   118,   125,   126,   127,   128,   129,   130,
     132,   240,   462,   493,   495,   505,   506,   507,   508,   510,
     512,   514,   518,   520,   522,   524,   526,   528,   530,   436,
      38,    90,    92,    93,    97,    98,    99,   240,   337,   446,
     447,   448,   449,   450,   451,   452,   454,   456,   458,   459,
     461,   493,   495,    91,    94,    95,    96,   240,   337,   450,
     456,   470,   471,   472,   473,   474,   476,   477,   478,   479,
     480,   493,   495,   135,   136,   240,   381,   382,   383,   385,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   176,   177,   240,   493,   495,   572,   573,
     574,   575,   577,   578,   580,   581,   582,   585,   587,   589,
     590,   591,   593,   595,   597,    12,    13,   603,   604,   605,
     607,     6,     3,     4,     8,     3,   244,     3,     8,   600,
     290,   310,     4,     4,     4,   509,   511,   513,   308,   318,
     320,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,   262,     4,     4,     4,     4,     4,   271,   274,
     276,     4,     4,     4,   398,   437,   463,     4,   429,   494,
     496,   425,     4,     4,     4,   358,   536,   498,   374,   388,
       4,   367,   551,   559,   569,   280,   282,     4,     4,     4,
     609,   633,     4,     3,     8,   296,   298,   301,     4,     4,
       4,     4,     3,     8,   410,   412,   414,   482,   408,   416,
       4,   420,   418,   533,     3,     8,   492,     3,     8,   531,
     519,   521,   525,   523,   529,   527,   515,     8,     3,     8,
     453,   338,     4,   457,   455,   460,     4,     8,     3,   475,
       4,     4,     4,     8,     3,   384,   386,     3,     8,     4,
     588,   576,     4,   579,     4,     4,   583,   586,     4,     4,
     592,   594,   596,   598,     3,     8,   606,     4,     3,     8,
     225,   225,   206,     4,     4,     4,     4,   209,   209,   209,
       4,     4,     4,     4,     4,     4,   207,   207,   207,   207,
     207,   209,   208,   208,   208,   207,   207,     4,   207,   207,
     209,   209,   209,     4,     4,     4,   209,   209,   209,     4,
       4,     4,   207,     4,     4,     4,     4,   209,   209,   209,
       4,     4,     4,     4,     4,   207,     4,     4,     4,     4,
       4,     4,   209,   209,   209,     4,     4,   249,     4,     4,
       4,   209,   209,   207,   207,   292,     4,     4,     4,     4,
       4,     4,   207,     4,     4,     4,   406,     4,   490,     4,
       4,     4,     4,     4,     4,     4,     4,   507,     4,     4,
     207,     4,     4,     4,   209,   448,     4,   209,   209,   209,
     472,     4,     4,   382,   209,     4,     4,   207,     4,   207,
     207,     4,     4,   209,   209,     4,     4,     4,     4,   573,
       4,   207,   604,     4,     7,     7,     7,     7,   206,   206,
     206,     7,     7,     5,   206,   172,   173,   174,   175,   209,
     272,   206,   206,     5,     5,     5,     5,   227,   229,   206,
     110,   111,   112,   113,   426,     5,     5,     5,     5,     7,
       7,     7,     7,     7,   206,   206,     5,     7,     5,   236,
      17,    18,   299,    20,    21,   302,   206,   206,   206,     5,
     206,   206,   236,   206,     7,   206,   236,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   229,   206,   206,   206,    18,   170,   584,   171,   272,
     206,   206,   206,     5,   225,   248,   603,   291,    27,    28,
     311,   312,   313,   315,    38,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    56,    57,    58,    59,
      60,   240,   325,   326,   327,   330,   332,   334,   336,   337,
     339,   340,   341,   342,   343,   344,   345,   348,   349,   351,
     353,   355,   325,     7,   321,   322,   323,     7,   399,   400,
     401,     7,   440,   441,   442,     7,   464,   465,   466,     7,
     430,   431,   432,   125,   126,   127,   128,   130,   359,   360,
     361,   362,   363,   364,   365,     7,   537,   538,     7,   499,
     500,   501,     7,   375,   376,   377,   138,   139,   140,   141,
     142,   143,   389,   390,   391,   392,   393,   394,   395,   396,
     146,   147,   148,   240,   368,   369,   370,   371,   372,   493,
     495,   150,   151,   240,   493,   495,   552,   553,   554,   556,
     153,   154,   155,   206,   493,   495,   560,   561,   562,   563,
     565,   566,   572,     7,   610,   611,   191,   192,   240,   634,
     635,   636,   637,   237,     7,   483,   484,   485,   133,   514,
     516,   534,   321,     8,     8,     8,   314,   316,     3,     8,
     328,   331,   333,   335,     4,     4,     4,     4,     4,     4,
       4,   346,     4,   350,   352,   354,   356,     3,     8,     8,
     324,     6,     3,   402,     6,     3,   443,     6,     3,   467,
       6,     3,   433,     6,     3,     3,     6,   539,     3,     6,
     502,     6,     3,   378,     6,     3,     4,     4,     4,     4,
       4,     4,     3,     8,     4,     4,     4,     3,     8,   555,
     557,     3,     8,     4,   564,     4,   567,     3,     8,     8,
     612,     3,     6,     4,     4,     3,     8,   206,   238,   239,
     486,     6,     3,   517,     8,     6,     4,     4,   312,     4,
       4,     4,     4,   207,   209,   207,   209,   207,   207,   207,
       4,   207,     4,     4,     4,     4,   326,   325,   323,   405,
     401,   446,   442,   470,   466,   240,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   265,   266,   267,   268,
     269,   270,   273,   275,   277,   278,   279,   281,   283,   337,
     397,   415,   417,   419,   421,   422,   423,   424,   434,   435,
     462,   493,   495,   508,   510,   512,   532,   432,   360,   120,
     121,   122,   240,   250,   251,   252,   337,   436,   462,   493,
     495,   508,   510,   512,   540,   541,   542,   543,   544,   546,
     548,   538,   505,   501,   381,   377,   207,   207,   207,   207,
     207,   207,   390,   209,   207,   207,   369,     4,     4,   553,
     209,     4,   207,     4,   561,   182,   184,   185,   240,   337,
     493,   495,   613,   614,   615,   616,   618,   611,   209,   209,
     635,     6,     3,   489,   485,     4,   206,   206,    39,    40,
      41,   329,   206,   206,   206,    53,    54,    55,   347,   206,
     206,   206,   206,     8,     8,     8,     8,     3,     8,   545,
     547,     4,     8,     3,     8,     8,   206,   206,   206,   225,
     619,     4,   617,     3,     8,   206,     8,   236,   435,     4,
       4,   209,   542,     4,   207,     4,   614,   206,   206,     5,
     206,     7,   620,   621,   622,     3,     6,   183,   186,   187,
     188,   189,   623,   624,   625,   627,   628,   629,   630,   621,
     626,     4,     4,     4,   631,     3,     8,     4,   209,   207,
     207,     4,   624,   206,   206
  };

  const short
  Dhcp4Parser::yyr1_[] =
  {
       0,   210,   212,   211,   213,   211,   214,   211,   215,   211,
     216,   211,   217,   211,   218,   211,   219,   211,   220,   211,
     221,   211,   222,   211,   223,   211,   224,   211,   225,   225,
     225,   225,   225,   225,   225,   226,   228,   227,   229,   230,
     230,   231,   231,   231,   233,   232,   234,   234,   235,   235,
     235,   237,   236,   238,   238,   239,   239,   239,   240,   242,
     241,   244,   243,   243,   245,   247,   246,   248,   248,   248,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   262,   261,   263,   264,   265,
     266,   267,   268,   269,   271,   270,   272,   272,   272,   272,
     272,   274,   273,   276,   275,   277,   278,   280,   279,   282,
     281,   283,   284,   285,   286,   287,   288,   290,   289,   291,
     291,   291,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   294,   293,   296,   295,   298,   297,   299,   299,
     301,   300,   302,   302,   303,   304,   305,   306,   308,   307,
     310,   309,   311,   311,   311,   312,   312,   314,   313,   316,
     315,   318,   317,   320,   319,   321,   321,   322,   322,   322,
     324,   323,   325,   325,   325,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   328,   327,   329,   329,   329,   331,
     330,   333,   332,   335,   334,   336,   338,   337,   339,   340,
     341,   342,   343,   344,   346,   345,   347,   347,   347,   348,
     350,   349,   352,   351,   354,   353,   356,   355,   358,   357,
     359,   359,   359,   360,   360,   360,   360,   360,   361,   362,
     363,   364,   365,   367,   366,   368,   368,   368,   369,   369,
     369,   369,   369,   369,   370,   371,   372,   374,   373,   375,
     375,   376,   376,   376,   378,   377,   380,   379,   381,   381,
     381,   381,   382,   382,   384,   383,   386,   385,   388,   387,
     389,   389,   389,   390,   390,   390,   390,   390,   390,   391,
     392,   393,   394,   395,   396,   398,   397,   399,   399,   400,
     400,   400,   402,   401,   404,   403,   405,   405,   405,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   408,   407,   410,   409,   412,   411,
     414,   413,   416,   415,   418,   417,   420,   419,   421,   422,
     423,   425,   424,   426,   426,   426,   426,   427,   429,   428,
     430,   430,   431,   431,   431,   433,   432,   434,   434,   434,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     437,   436,   439,   438,   440,   440,   441,   441,   441,   443,
     442,   445,   444,   446,   446,   447,   447,   447,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   449,   450,
     451,   453,   452,   455,   454,   457,   456,   458,   460,   459,
     461,   463,   462,   464,   464,   465,   465,   465,   467,   466,
     469,   468,   470,   470,   471,   471,   471,   472,   472,   472,
     472,   472,   472,   472,   472,   472,   472,   473,   475,   474,
     476,   477,   478,   479,   480,   482,   481,   483,   483,   484,
     484,   484,   486,   485,   488,   487,   489,   489,   489,   490,
     490,   490,   490,   490,   490,   490,   492,   491,   494,   493,
     496,   495,   498,   497,   499,   499,   500,   500,   500,   502,
     501,   504,   503,   505,   505,   506,   506,   506,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   509,   508,   511,   510,   513,   512,   515,
     514,   517,   516,   519,   518,   521,   520,   523,   522,   525,
     524,   527,   526,   529,   528,   531,   530,   533,   532,   534,
     534,   536,   535,   537,   537,   537,   539,   538,   540,   540,
     541,   541,   541,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   543,   545,
     544,   547,   546,   548,   549,   551,   550,   552,   552,   552,
     553,   553,   553,   553,   553,   555,   554,   557,   556,   559,
     558,   560,   560,   560,   561,   561,   561,   561,   561,   561,
     562,   564,   563,   565,   567,   566,   569,   568,   571,   570,
     572,   572,   572,   573,   573,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   573,   573,   573,   573,   573,
     573,   574,   576,   575,   577,   579,   578,   580,   581,   583,
     582,   584,   584,   586,   585,   588,   587,   589,   590,   592,
     591,   594,   593,   596,   595,   598,   597,   600,   599,   602,
     601,   603,   603,   603,   604,   604,   606,   605,   607,   609,
     608,   610,   610,   610,   612,   611,   613,   613,   613,   614,
     614,   614,   614,   614,   614,   614,   615,   617,   616,   619,
     618,   620,   620,   620,   622,   621,   623,   623,   623,   624,
     624,   624,   624,   624,   626,   625,   627,   628,   629,   631,
     630,   633,   632,   634,   634,   634,   635,   635,   635,   636,
     637
  };

  const signed char
  Dhcp4Parser::yyr2_[] =
  {
       0,     2,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     1,     0,
       1,     3,     5,     2,     0,     4,     0,     1,     1,     3,
       2,     0,     4,     0,     1,     1,     3,     2,     2,     0,
       4,     0,     6,     1,     2,     0,     4,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     0,     4,     3,     3,     3,
       3,     3,     3,     3,     0,     4,     1,     1,     1,     1,
       1,     0,     4,     0,     4,     3,     3,     0,     4,     0,
       4,     3,     3,     3,     3,     3,     3,     0,     6,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     4,     0,     4,     1,     1,
       0,     4,     1,     1,     3,     3,     3,     3,     0,     6,
       0,     6,     1,     3,     2,     1,     1,     0,     4,     0,
       4,     0,     6,     0,     6,     0,     1,     1,     3,     2,
       0,     4,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     1,     1,     0,
       4,     0,     4,     0,     4,     3,     0,     4,     3,     3,
       3,     3,     3,     3,     0,     4,     1,     1,     1,     3,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     6,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     0,     6,     0,
       1,     1,     3,     2,     0,     4,     0,     4,     1,     3,
       2,     1,     1,     1,     0,     4,     0,     4,     0,     6,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     0,     6,     0,     1,     1,
       3,     2,     0,     4,     0,     4,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     3,     3,
       3,     0,     4,     1,     1,     1,     1,     3,     0,     6,
       0,     1,     1,     3,     2,     0,     4,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     0,     4,     0,     1,     1,     3,     2,     0,
       4,     0,     4,     0,     1,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     0,     4,     0,     4,     0,     4,     1,     0,     4,
       3,     0,     6,     0,     1,     1,     3,     2,     0,     4,
       0,     4,     0,     1,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     1,     3,     3,     3,     0,     6,     0,     1,     1,
       3,     2,     0,     4,     0,     4,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     0,     6,     0,     1,     1,     3,     2,     0,
       4,     0,     4,     0,     1,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     6,     1,
       1,     0,     6,     1,     3,     2,     0,     4,     0,     1,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     0,     4,     3,     3,     0,     6,     1,     3,     2,
       1,     1,     1,     1,     1,     0,     4,     0,     4,     0,
       6,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     0,     4,     3,     0,     4,     0,     6,     0,     4,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     4,     3,     0,     4,     3,     3,     0,
       4,     1,     1,     0,     4,     0,     4,     3,     3,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     6,     0,
       4,     1,     3,     2,     1,     1,     0,     6,     3,     0,
       6,     1,     3,     2,     0,     4,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     4,     0,
       6,     1,     3,     2,     0,     4,     1,     3,     2,     1,
       1,     1,     1,     1,     0,     4,     3,     3,     3,     0,
       4,     0,     6,     1,     3,     2,     1,     1,     1,     3,
       3
  };


#if PARSER4_DEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Dhcp4Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\",\"", "\":\"",
  "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\"null\"", "\"Dhcp4\"",
  "\"config-control\"", "\"config-databases\"",
  "\"config-fetch-wait-time\"", "\"interfaces-config\"", "\"interfaces\"",
  "\"dhcp-socket-type\"", "\"raw\"", "\"udp\"", "\"outbound-interface\"",
  "\"same-as-inbound\"", "\"use-routing\"", "\"re-detect\"",
  "\"service-sockets-require-all\"", "\"service-sockets-retry-wait-time\"",
  "\"service-sockets-max-retries\"", "\"sanity-checks\"",
  "\"lease-checks\"", "\"extended-info-checks\"", "\"echo-client-id\"",
  "\"match-client-id\"", "\"authoritative\"", "\"next-server\"",
  "\"server-hostname\"", "\"boot-file-name\"", "\"lease-database\"",
  "\"hosts-database\"", "\"hosts-databases\"", "\"type\"", "\"memfile\"",
  "\"mysql\"", "\"postgresql\"", "\"user\"", "\"password\"", "\"host\"",
  "\"port\"", "\"persist\"", "\"lfc-interval\"", "\"readonly\"",
  "\"connect-timeout\"", "\"max-reconnect-tries\"",
  "\"reconnect-wait-time\"", "\"on-fail\"", "\"stop-retry-exit\"",
  "\"serve-retry-exit\"", "\"serve-retry-continue\"", "\"max-row-errors\"",
  "\"trust-anchor\"", "\"cert-file\"", "\"key-file\"", "\"cipher-list\"",
  "\"valid-lifetime\"", "\"min-valid-lifetime\"", "\"max-valid-lifetime\"",
  "\"renew-timer\"", "\"rebind-timer\"", "\"calculate-tee-times\"",
  "\"t1-percent\"", "\"t2-percent\"", "\"cache-threshold\"",
  "\"cache-max-age\"", "\"decline-probation-period\"", "\"server-tag\"",
  "\"statistic-default-sample-count\"", "\"statistic-default-sample-age\"",
  "\"ddns-send-updates\"", "\"ddns-override-no-update\"",
  "\"ddns-override-client-update\"", "\"ddns-replace-client-name\"",
  "\"ddns-generated-prefix\"", "\"ddns-qualifying-suffix\"",
  "\"ddns-update-on-renew\"", "\"ddns-use-conflict-resolution\"",
  "\"store-extended-info\"", "\"subnet4\"", "\"4o6-interface\"",
  "\"4o6-interface-id\"", "\"4o6-subnet\"", "\"option-def\"",
  "\"option-data\"", "\"name\"", "\"data\"", "\"code\"", "\"space\"",
  "\"csv-format\"", "\"always-send\"", "\"never-send\"",
  "\"record-types\"", "\"encapsulate\"", "\"array\"",
  "\"parked-packet-limit\"", "\"shared-networks\"", "\"pools\"",
  "\"pool\"", "\"user-context\"", "\"comment\"", "\"subnet\"",
  "\"interface\"", "\"id\"", "\"reservation-mode\"", "\"disabled\"",
  "\"out-of-pool\"", "\"global\"", "\"all\"", "\"reservations-global\"",
  "\"reservations-in-subnet\"", "\"reservations-out-of-pool\"",
  "\"host-reservation-identifiers\"", "\"client-classes\"",
  "\"require-client-classes\"", "\"test\"", "\"template-test\"",
  "\"only-if-required\"", "\"client-class\"", "\"reservations\"",
  "\"duid\"", "\"hw-address\"", "\"circuit-id\"", "\"client-id\"",
  "\"hostname\"", "\"flex-id\"", "\"relay\"", "\"ip-address\"",
  "\"ip-addresses\"", "\"hooks-libraries\"", "\"library\"",
  "\"parameters\"", "\"expired-leases-processing\"",
  "\"reclaim-timer-wait-time\"", "\"flush-reclaimed-timer-wait-time\"",
  "\"hold-reclaimed-time\"", "\"max-reclaim-leases\"",
  "\"max-reclaim-time\"", "\"unwarned-reclaim-cycles\"",
  "\"dhcp4o6-port\"", "\"multi-threading\"", "\"enable-multi-threading\"",
  "\"thread-pool-size\"", "\"packet-queue-size\"", "\"control-socket\"",
  "\"socket-type\"", "\"socket-name\"", "\"dhcp-queue-control\"",
  "\"enable-queue\"", "\"queue-type\"", "\"capacity\"", "\"dhcp-ddns\"",
  "\"enable-updates\"", "\"qualifying-suffix\"", "\"server-ip\"",
  "\"server-port\"", "\"sender-ip\"", "\"sender-port\"",
  "\"max-queue-size\"", "\"ncr-protocol\"", "\"ncr-format\"",
  "\"override-no-update\"", "\"override-client-update\"",
  "\"replace-client-name\"", "\"generated-prefix\"", "\"tcp\"", "\"JSON\"",
  "\"when-present\"", "\"never\"", "\"always\"", "\"when-not-present\"",
  "\"hostname-char-set\"", "\"hostname-char-replacement\"",
  "\"early-global-reservations-lookup\"", "\"ip-reservations-unique\"",
  "\"reservations-lookup-first\"", "\"loggers\"", "\"output_options\"",
  "\"output\"", "\"debuglevel\"", "\"severity\"", "\"flush\"",
  "\"maxsize\"", "\"maxver\"", "\"pattern\"", "\"compatibility\"",
  "\"lenient-option-parsing\"", "\"ignore-rai-link-selection\"",
  "TOPLEVEL_JSON", "TOPLEVEL_DHCP4", "SUB_DHCP4", "SUB_INTERFACES4",
  "SUB_SUBNET4", "SUB_POOL4", "SUB_RESERVATION", "SUB_OPTION_DEFS",
  "SUB_OPTION_DEF", "SUB_OPTION_DATA", "SUB_HOOKS_LIBRARY",
  "SUB_DHCP_DDNS", "SUB_CONFIG_CONTROL", "\"constant string\"",
  "\"integer\"", "\"floating point\"", "\"boolean\"", "$accept", "start",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "$@11", "$@12", "$@13", "value", "sub_json", "map2", "$@14", "map_value",
  "map_content", "not_empty_map", "list_generic", "$@15", "list_content",
  "not_empty_list", "list_strings", "$@16", "list_strings_content",
  "not_empty_list_strings", "unknown_map_entry", "syntax_map", "$@17",
  "global_object", "$@18", "global_object_comma", "sub_dhcp4", "$@19",
  "global_params", "global_param", "valid_lifetime", "min_valid_lifetime",
  "max_valid_lifetime", "renew_timer", "rebind_timer",
  "calculate_tee_times", "t1_percent", "t2_percent", "cache_threshold",
  "cache_max_age", "decline_probation_period", "server_tag", "$@20",
  "parked_packet_limit", "echo_client_id", "match_client_id",
  "authoritative", "ddns_send_updates", "ddns_override_no_update",
  "ddns_override_client_update", "ddns_replace_client_name", "$@21",
  "ddns_replace_client_name_value", "ddns_generated_prefix", "$@22",
  "ddns_qualifying_suffix", "$@23", "ddns_update_on_renew",
  "ddns_use_conflict_resolution", "hostname_char_set", "$@24",
  "hostname_char_replacement", "$@25", "store_extended_info",
  "statistic_default_sample_count", "statistic_default_sample_age",
  "early_global_reservations_lookup", "ip_reservations_unique",
  "reservations_lookup_first", "interfaces_config", "$@26",
  "interfaces_config_params", "interfaces_config_param", "sub_interfaces4",
  "$@27", "interfaces_list", "$@28", "dhcp_socket_type", "$@29",
  "socket_type", "outbound_interface", "$@30", "outbound_interface_value",
  "re_detect", "service_sockets_require_all",
  "service_sockets_retry_wait_time", "service_sockets_max_retries",
  "lease_database", "$@31", "sanity_checks", "$@32",
  "sanity_checks_params", "sanity_checks_param", "lease_checks", "$@33",
  "extended_info_checks", "$@34", "hosts_database", "$@35",
  "hosts_databases", "$@36", "database_list", "not_empty_database_list",
  "database", "$@37", "database_map_params", "database_map_param",
  "database_type", "$@38", "db_type", "user", "$@39", "password", "$@40",
  "host", "$@41", "port", "name", "$@42", "persist", "lfc_interval",
  "readonly", "connect_timeout", "max_reconnect_tries",
  "reconnect_wait_time", "on_fail", "$@43", "on_fail_mode",
  "max_row_errors", "trust_anchor", "$@44", "cert_file", "$@45",
  "key_file", "$@46", "cipher_list", "$@47",
  "host_reservation_identifiers", "$@48",
  "host_reservation_identifiers_list", "host_reservation_identifier",
  "duid_id", "hw_address_id", "circuit_id", "client_id", "flex_id",
  "dhcp_multi_threading", "$@49", "multi_threading_params",
  "multi_threading_param", "enable_multi_threading", "thread_pool_size",
  "packet_queue_size", "hooks_libraries", "$@50", "hooks_libraries_list",
  "not_empty_hooks_libraries_list", "hooks_library", "$@51",
  "sub_hooks_library", "$@52", "hooks_params", "hooks_param", "library",
  "$@53", "parameters", "$@54", "expired_leases_processing", "$@55",
  "expired_leases_params", "expired_leases_param",
  "reclaim_timer_wait_time", "flush_reclaimed_timer_wait_time",
  "hold_reclaimed_time", "max_reclaim_leases", "max_reclaim_time",
  "unwarned_reclaim_cycles", "subnet4_list", "$@56",
  "subnet4_list_content", "not_empty_subnet4_list", "subnet4", "$@57",
  "sub_subnet4", "$@58", "subnet4_params", "subnet4_param", "subnet",
  "$@59", "subnet_4o6_interface", "$@60", "subnet_4o6_interface_id",
  "$@61", "subnet_4o6_subnet", "$@62", "interface", "$@63", "client_class",
  "$@64", "require_client_classes", "$@65", "reservations_global",
  "reservations_in_subnet", "reservations_out_of_pool", "reservation_mode",
  "$@66", "hr_mode", "id", "shared_networks", "$@67",
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
  "$@82", "sub_pool4", "$@83", "pool_params", "pool_param", "pool_entry",
  "$@84", "user_context", "$@85", "comment", "$@86", "reservations",
  "$@87", "reservations_list", "not_empty_reservations_list",
  "reservation", "$@88", "sub_reservation", "$@89", "reservation_params",
  "not_empty_reservation_params", "reservation_param", "next_server",
  "$@90", "server_hostname", "$@91", "boot_file_name", "$@92",
  "ip_address", "$@93", "ip_addresses", "$@94", "duid", "$@95",
  "hw_address", "$@96", "client_id_value", "$@97", "circuit_id_value",
  "$@98", "flex_id_value", "$@99", "hostname", "$@100",
  "reservation_client_classes", "$@101", "relay", "$@102", "relay_map",
  "client_classes", "$@103", "client_classes_list", "client_class_entry",
  "$@104", "client_class_params", "not_empty_client_class_params",
  "client_class_param", "client_class_name", "client_class_test", "$@105",
  "client_class_template_test", "$@106", "only_if_required",
  "dhcp4o6_port", "control_socket", "$@107", "control_socket_params",
  "control_socket_param", "control_socket_type", "$@108",
  "control_socket_name", "$@109", "dhcp_queue_control", "$@110",
  "queue_control_params", "queue_control_param", "enable_queue",
  "queue_type", "$@111", "capacity", "arbitrary_map_entry", "$@112",
  "dhcp_ddns", "$@113", "sub_dhcp_ddns", "$@114", "dhcp_ddns_params",
  "dhcp_ddns_param", "enable_updates", "server_ip", "$@115", "server_port",
  "sender_ip", "$@116", "sender_port", "max_queue_size", "ncr_protocol",
  "$@117", "ncr_protocol_value", "ncr_format", "$@118",
  "dep_qualifying_suffix", "$@119", "dep_override_no_update",
  "dep_override_client_update", "dep_replace_client_name", "$@120",
  "dep_generated_prefix", "$@121", "dep_hostname_char_set", "$@122",
  "dep_hostname_char_replacement", "$@123", "config_control", "$@124",
  "sub_config_control", "$@125", "config_control_params",
  "config_control_param", "config_databases", "$@126",
  "config_fetch_wait_time", "loggers", "$@127", "loggers_entries",
  "logger_entry", "$@128", "logger_params", "logger_param", "debuglevel",
  "severity", "$@129", "output_options_list", "$@130",
  "output_options_list_content", "output_entry", "$@131",
  "output_params_list", "output_params", "output", "$@132", "flush",
  "maxsize", "maxver", "pattern", "$@133", "compatibility", "$@134",
  "compatibility_params", "compatibility_param", "lenient_option_parsing",
  "ignore-rai-link-selection", YY_NULLPTR
  };
#endif


#if PARSER4_DEBUG
  const short
  Dhcp4Parser::yyrline_[] =
  {
       0,   299,   299,   299,   300,   300,   301,   301,   302,   302,
     303,   303,   304,   304,   305,   305,   306,   306,   307,   307,
     308,   308,   309,   309,   310,   310,   311,   311,   319,   320,
     321,   322,   323,   324,   325,   328,   333,   333,   344,   347,
     348,   351,   356,   362,   367,   367,   374,   375,   378,   382,
     386,   392,   392,   399,   400,   403,   407,   411,   421,   430,
     430,   445,   445,   459,   462,   468,   468,   477,   478,   479,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   552,   558,   564,   570,   576,   582,
     588,   594,   600,   606,   612,   618,   618,   627,   633,   639,
     645,   651,   657,   663,   669,   669,   678,   681,   684,   687,
     690,   696,   696,   705,   705,   714,   720,   726,   726,   735,
     735,   744,   750,   756,   762,   768,   774,   780,   780,   792,
     793,   794,   799,   800,   801,   802,   803,   804,   805,   806,
     807,   808,   811,   811,   820,   820,   831,   831,   839,   840,
     843,   843,   851,   853,   857,   863,   869,   875,   881,   881,
     894,   894,   905,   906,   907,   912,   913,   916,   916,   935,
     935,   953,   953,   966,   966,   977,   978,   981,   982,   983,
     988,   988,   998,   999,  1000,  1005,  1006,  1007,  1008,  1009,
    1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
    1020,  1021,  1022,  1023,  1026,  1026,  1034,  1035,  1036,  1039,
    1039,  1048,  1048,  1057,  1057,  1066,  1072,  1072,  1081,  1087,
    1093,  1099,  1105,  1111,  1117,  1117,  1125,  1126,  1127,  1130,
    1136,  1136,  1145,  1145,  1154,  1154,  1163,  1163,  1172,  1172,
    1183,  1184,  1185,  1190,  1191,  1192,  1193,  1194,  1197,  1202,
    1207,  1212,  1217,  1224,  1224,  1237,  1238,  1239,  1244,  1245,
    1246,  1247,  1248,  1249,  1252,  1258,  1264,  1270,  1270,  1281,
    1282,  1285,  1286,  1287,  1292,  1292,  1302,  1302,  1312,  1313,
    1314,  1317,  1320,  1321,  1324,  1324,  1333,  1333,  1342,  1342,
    1354,  1355,  1356,  1361,  1362,  1363,  1364,  1365,  1366,  1369,
    1375,  1381,  1387,  1393,  1399,  1408,  1408,  1422,  1423,  1426,
    1427,  1428,  1437,  1437,  1463,  1463,  1474,  1475,  1476,  1482,
    1483,  1484,  1485,  1486,  1487,  1488,  1489,  1490,  1491,  1492,
    1493,  1494,  1495,  1496,  1497,  1498,  1499,  1500,  1501,  1502,
    1503,  1504,  1505,  1506,  1507,  1508,  1509,  1510,  1511,  1512,
    1513,  1514,  1515,  1516,  1517,  1518,  1519,  1520,  1521,  1522,
    1523,  1524,  1525,  1526,  1529,  1529,  1538,  1538,  1547,  1547,
    1556,  1556,  1565,  1565,  1574,  1574,  1583,  1583,  1594,  1600,
    1606,  1612,  1612,  1620,  1621,  1622,  1623,  1626,  1634,  1634,
    1646,  1647,  1651,  1652,  1653,  1658,  1658,  1666,  1667,  1668,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,
    1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,
    1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,
    1719,  1719,  1733,  1733,  1742,  1743,  1746,  1747,  1748,  1755,
    1755,  1770,  1770,  1784,  1785,  1788,  1789,  1790,  1795,  1796,
    1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,  1807,  1809,
    1815,  1817,  1817,  1826,  1826,  1835,  1835,  1844,  1846,  1846,
    1855,  1865,  1865,  1878,  1879,  1884,  1885,  1886,  1893,  1893,
    1905,  1905,  1917,  1918,  1923,  1924,  1925,  1932,  1933,  1934,
    1935,  1936,  1937,  1938,  1939,  1940,  1941,  1944,  1946,  1946,
    1955,  1957,  1959,  1965,  1971,  1980,  1980,  1993,  1994,  1997,
    1998,  1999,  2004,  2004,  2014,  2014,  2024,  2025,  2026,  2031,
    2032,  2033,  2034,  2035,  2036,  2037,  2040,  2040,  2049,  2049,
    2074,  2074,  2104,  2104,  2115,  2116,  2119,  2120,  2121,  2126,
    2126,  2135,  2135,  2144,  2145,  2148,  2149,  2150,  2156,  2157,
    2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2168,  2169,  2170,  2173,  2173,  2182,  2182,  2191,  2191,  2200,
    2200,  2209,  2209,  2220,  2220,  2229,  2229,  2238,  2238,  2247,
    2247,  2256,  2256,  2265,  2265,  2274,  2274,  2288,  2288,  2299,
    2300,  2306,  2306,  2317,  2318,  2319,  2324,  2324,  2334,  2335,
    2338,  2339,  2340,  2345,  2346,  2347,  2348,  2349,  2350,  2351,
    2352,  2353,  2354,  2355,  2356,  2357,  2358,  2359,  2362,  2364,
    2364,  2373,  2373,  2382,  2390,  2398,  2398,  2409,  2410,  2411,
    2416,  2417,  2418,  2419,  2420,  2423,  2423,  2432,  2432,  2444,
    2444,  2457,  2458,  2459,  2464,  2465,  2466,  2467,  2468,  2469,
    2472,  2478,  2478,  2487,  2493,  2493,  2503,  2503,  2516,  2516,
    2526,  2527,  2528,  2533,  2534,  2535,  2536,  2537,  2538,  2539,
    2540,  2541,  2542,  2543,  2544,  2545,  2546,  2547,  2548,  2549,
    2550,  2553,  2559,  2559,  2568,  2574,  2574,  2583,  2589,  2595,
    2595,  2604,  2605,  2608,  2608,  2618,  2618,  2628,  2635,  2642,
    2642,  2651,  2651,  2661,  2661,  2671,  2671,  2683,  2683,  2695,
    2695,  2705,  2706,  2707,  2713,  2714,  2717,  2717,  2728,  2736,
    2736,  2749,  2750,  2751,  2757,  2757,  2765,  2766,  2767,  2772,
    2773,  2774,  2775,  2776,  2777,  2778,  2781,  2787,  2787,  2796,
    2796,  2807,  2808,  2809,  2814,  2814,  2822,  2823,  2824,  2829,
    2830,  2831,  2832,  2833,  2836,  2836,  2845,  2851,  2857,  2863,
    2863,  2872,  2872,  2883,  2884,  2885,  2890,  2891,  2892,  2895,
    2901
  };

  void
  Dhcp4Parser::yy_stack_print_ () const
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
  Dhcp4Parser::yy_reduce_print_ (int yyrule) const
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
#endif // PARSER4_DEBUG


#line 14 "dhcp4_parser.yy"
} } // isc::dhcp
#line 6225 "dhcp4_parser.cc"

#line 2907 "dhcp4_parser.yy"


void
isc::dhcp::Dhcp4Parser::error(const location_type& loc,
                              const std::string& what)
{
    ctx.error(loc, what);
}
