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
#line 294 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 408 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_INTEGER: // "integer"
#line 294 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < int64_t > (); }
#line 414 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_FLOAT: // "floating point"
#line 294 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < double > (); }
#line 420 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
#line 294 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < bool > (); }
#line 426 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_value: // value
#line 294 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 432 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_map_value: // map_value
#line 294 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 438 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_ddns_replace_client_name_value: // ddns_replace_client_name_value
#line 294 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 444 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_socket_type: // socket_type
#line 294 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 450 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_outbound_interface_value: // outbound_interface_value
#line 294 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 456 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_db_type: // db_type
#line 294 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 462 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_on_fail_mode: // on_fail_mode
#line 294 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 468 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_hr_mode: // hr_mode
#line 294 "dhcp4_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 474 "dhcp4_parser.cc"
        break;

      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
#line 294 "dhcp4_parser.yy"
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
#line 303 "dhcp4_parser.yy"
                     { ctx.ctx_ = ctx.NO_KEYWORD; }
#line 761 "dhcp4_parser.cc"
    break;

  case 4: // $@2: %empty
#line 304 "dhcp4_parser.yy"
                      { ctx.ctx_ = ctx.CONFIG; }
#line 767 "dhcp4_parser.cc"
    break;

  case 6: // $@3: %empty
#line 305 "dhcp4_parser.yy"
                 { ctx.ctx_ = ctx.DHCP4; }
#line 773 "dhcp4_parser.cc"
    break;

  case 8: // $@4: %empty
#line 306 "dhcp4_parser.yy"
                       { ctx.ctx_ = ctx.INTERFACES_CONFIG; }
#line 779 "dhcp4_parser.cc"
    break;

  case 10: // $@5: %empty
#line 307 "dhcp4_parser.yy"
                   { ctx.ctx_ = ctx.SUBNET4; }
#line 785 "dhcp4_parser.cc"
    break;

  case 12: // $@6: %empty
#line 308 "dhcp4_parser.yy"
                 { ctx.ctx_ = ctx.POOLS; }
#line 791 "dhcp4_parser.cc"
    break;

  case 14: // $@7: %empty
#line 309 "dhcp4_parser.yy"
                       { ctx.ctx_ = ctx.RESERVATIONS; }
#line 797 "dhcp4_parser.cc"
    break;

  case 16: // $@8: %empty
#line 310 "dhcp4_parser.yy"
                       { ctx.ctx_ = ctx.DHCP4; }
#line 803 "dhcp4_parser.cc"
    break;

  case 18: // $@9: %empty
#line 311 "dhcp4_parser.yy"
                      { ctx.ctx_ = ctx.OPTION_DEF; }
#line 809 "dhcp4_parser.cc"
    break;

  case 20: // $@10: %empty
#line 312 "dhcp4_parser.yy"
                       { ctx.ctx_ = ctx.OPTION_DATA; }
#line 815 "dhcp4_parser.cc"
    break;

  case 22: // $@11: %empty
#line 313 "dhcp4_parser.yy"
                         { ctx.ctx_ = ctx.HOOKS_LIBRARIES; }
#line 821 "dhcp4_parser.cc"
    break;

  case 24: // $@12: %empty
#line 314 "dhcp4_parser.yy"
                     { ctx.ctx_ = ctx.DHCP_DDNS; }
#line 827 "dhcp4_parser.cc"
    break;

  case 26: // $@13: %empty
#line 315 "dhcp4_parser.yy"
                          { ctx.ctx_ = ctx.CONFIG_CONTROL; }
#line 833 "dhcp4_parser.cc"
    break;

  case 28: // value: "integer"
#line 323 "dhcp4_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location))); }
#line 839 "dhcp4_parser.cc"
    break;

  case 29: // value: "floating point"
#line 324 "dhcp4_parser.yy"
             { yylhs.value.as < ElementPtr > () = ElementPtr(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location))); }
#line 845 "dhcp4_parser.cc"
    break;

  case 30: // value: "boolean"
#line 325 "dhcp4_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location))); }
#line 851 "dhcp4_parser.cc"
    break;

  case 31: // value: "constant string"
#line 326 "dhcp4_parser.yy"
              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location))); }
#line 857 "dhcp4_parser.cc"
    break;

  case 32: // value: "null"
#line 327 "dhcp4_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new NullElement(ctx.loc2pos(yystack_[0].location))); }
#line 863 "dhcp4_parser.cc"
    break;

  case 33: // value: map2
#line 328 "dhcp4_parser.yy"
            { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 869 "dhcp4_parser.cc"
    break;

  case 34: // value: list_generic
#line 329 "dhcp4_parser.yy"
                    { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 875 "dhcp4_parser.cc"
    break;

  case 35: // sub_json: value
#line 332 "dhcp4_parser.yy"
                {
    // Push back the JSON value on the stack
    ctx.stack_.push_back(yystack_[0].value.as < ElementPtr > ());
}
#line 884 "dhcp4_parser.cc"
    break;

  case 36: // $@14: %empty
#line 337 "dhcp4_parser.yy"
                     {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 895 "dhcp4_parser.cc"
    break;

  case 37: // map2: "{" $@14 map_content "}"
#line 342 "dhcp4_parser.yy"
                             {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.
}
#line 905 "dhcp4_parser.cc"
    break;

  case 38: // map_value: map2
#line 348 "dhcp4_parser.yy"
                { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 911 "dhcp4_parser.cc"
    break;

  case 41: // not_empty_map: "constant string" ":" value
#line 355 "dhcp4_parser.yy"
                                  {
                  // map containing a single entry
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 921 "dhcp4_parser.cc"
    break;

  case 42: // not_empty_map: not_empty_map "," "constant string" ":" value
#line 360 "dhcp4_parser.yy"
                                                      {
                  // map consisting of a shorter map followed by
                  // comma and string:value
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 932 "dhcp4_parser.cc"
    break;

  case 43: // not_empty_map: not_empty_map ","
#line 366 "dhcp4_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 940 "dhcp4_parser.cc"
    break;

  case 44: // $@15: %empty
#line 371 "dhcp4_parser.yy"
                              {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 949 "dhcp4_parser.cc"
    break;

  case 45: // list_generic: "[" $@15 list_content "]"
#line 374 "dhcp4_parser.yy"
                               {
    // list parsing complete. Put any sanity checking here
}
#line 957 "dhcp4_parser.cc"
    break;

  case 48: // not_empty_list: value
#line 382 "dhcp4_parser.yy"
                      {
                  // List consisting of a single element.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 966 "dhcp4_parser.cc"
    break;

  case 49: // not_empty_list: not_empty_list "," value
#line 386 "dhcp4_parser.yy"
                                           {
                  // List ending with , and a value.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 975 "dhcp4_parser.cc"
    break;

  case 50: // not_empty_list: not_empty_list ","
#line 390 "dhcp4_parser.yy"
                                     {
                  ctx.warnAboutExtraCommas(yystack_[0].location);
                  }
#line 983 "dhcp4_parser.cc"
    break;

  case 51: // $@16: %empty
#line 396 "dhcp4_parser.yy"
                              {
    // List parsing about to start
}
#line 991 "dhcp4_parser.cc"
    break;

  case 52: // list_strings: "[" $@16 list_strings_content "]"
#line 398 "dhcp4_parser.yy"
                                       {
    // list parsing complete. Put any sanity checking here
    //ctx.stack_.pop_back();
}
#line 1000 "dhcp4_parser.cc"
    break;

  case 55: // not_empty_list_strings: "constant string"
#line 407 "dhcp4_parser.yy"
                               {
                          ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
                          ctx.stack_.back()->add(s);
                          }
#line 1009 "dhcp4_parser.cc"
    break;

  case 56: // not_empty_list_strings: not_empty_list_strings "," "constant string"
#line 411 "dhcp4_parser.yy"
                                                            {
                          ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
                          ctx.stack_.back()->add(s);
                          }
#line 1018 "dhcp4_parser.cc"
    break;

  case 57: // not_empty_list_strings: not_empty_list_strings ","
#line 415 "dhcp4_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 1026 "dhcp4_parser.cc"
    break;

  case 58: // unknown_map_entry: "constant string" ":"
#line 425 "dhcp4_parser.yy"
                                {
    const std::string& where = ctx.contextName();
    const std::string& keyword = yystack_[1].value.as < std::string > ();
    error(yystack_[1].location,
          "got unexpected keyword \"" + keyword + "\" in " + where + " map.");
}
#line 1037 "dhcp4_parser.cc"
    break;

  case 59: // $@17: %empty
#line 434 "dhcp4_parser.yy"
                           {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1048 "dhcp4_parser.cc"
    break;

  case 60: // syntax_map: "{" $@17 global_object "}"
#line 439 "dhcp4_parser.yy"
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
#line 449 "dhcp4_parser.yy"
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
#line 458 "dhcp4_parser.yy"
                                                    {
    // No global parameter is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1086 "dhcp4_parser.cc"
    break;

  case 64: // global_object_comma: global_object ","
#line 466 "dhcp4_parser.yy"
                                         {
    ctx.warnAboutExtraCommas(yystack_[0].location);
}
#line 1094 "dhcp4_parser.cc"
    break;

  case 65: // $@19: %empty
#line 472 "dhcp4_parser.yy"
                          {
    // Parse the Dhcp4 map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1104 "dhcp4_parser.cc"
    break;

  case 66: // sub_dhcp4: "{" $@19 global_params "}"
#line 476 "dhcp4_parser.yy"
                               {
    // No global parameter is required
    // parsing completed
}
#line 1113 "dhcp4_parser.cc"
    break;

  case 69: // global_params: global_params ","
#line 483 "dhcp4_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 1121 "dhcp4_parser.cc"
    break;

  case 136: // valid_lifetime: "valid-lifetime" ":" "integer"
#line 558 "dhcp4_parser.yy"
                                             {
    ctx.unique("valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("valid-lifetime", prf);
}
#line 1131 "dhcp4_parser.cc"
    break;

  case 137: // min_valid_lifetime: "min-valid-lifetime" ":" "integer"
#line 564 "dhcp4_parser.yy"
                                                     {
    ctx.unique("min-valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("min-valid-lifetime", prf);
}
#line 1141 "dhcp4_parser.cc"
    break;

  case 138: // max_valid_lifetime: "max-valid-lifetime" ":" "integer"
#line 570 "dhcp4_parser.yy"
                                                     {
    ctx.unique("max-valid-lifetime", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-valid-lifetime", prf);
}
#line 1151 "dhcp4_parser.cc"
    break;

  case 139: // renew_timer: "renew-timer" ":" "integer"
#line 576 "dhcp4_parser.yy"
                                       {
    ctx.unique("renew-timer", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("renew-timer", prf);
}
#line 1161 "dhcp4_parser.cc"
    break;

  case 140: // rebind_timer: "rebind-timer" ":" "integer"
#line 582 "dhcp4_parser.yy"
                                         {
    ctx.unique("rebind-timer", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("rebind-timer", prf);
}
#line 1171 "dhcp4_parser.cc"
    break;

  case 141: // calculate_tee_times: "calculate-tee-times" ":" "boolean"
#line 588 "dhcp4_parser.yy"
                                                       {
    ctx.unique("calculate-tee-times", ctx.loc2pos(yystack_[2].location));
    ElementPtr ctt(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("calculate-tee-times", ctt);
}
#line 1181 "dhcp4_parser.cc"
    break;

  case 142: // t1_percent: "t1-percent" ":" "floating point"
#line 594 "dhcp4_parser.yy"
                                   {
    ctx.unique("t1-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr t1(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("t1-percent", t1);
}
#line 1191 "dhcp4_parser.cc"
    break;

  case 143: // t2_percent: "t2-percent" ":" "floating point"
#line 600 "dhcp4_parser.yy"
                                   {
    ctx.unique("t2-percent", ctx.loc2pos(yystack_[2].location));
    ElementPtr t2(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("t2-percent", t2);
}
#line 1201 "dhcp4_parser.cc"
    break;

  case 144: // cache_threshold: "cache-threshold" ":" "floating point"
#line 606 "dhcp4_parser.yy"
                                             {
    ctx.unique("cache-threshold", ctx.loc2pos(yystack_[2].location));
    ElementPtr ct(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cache-threshold", ct);
}
#line 1211 "dhcp4_parser.cc"
    break;

  case 145: // cache_max_age: "cache-max-age" ":" "integer"
#line 612 "dhcp4_parser.yy"
                                           {
    ctx.unique("cache-max-age", ctx.loc2pos(yystack_[2].location));
    ElementPtr cm(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cache-max-age", cm);
}
#line 1221 "dhcp4_parser.cc"
    break;

  case 146: // decline_probation_period: "decline-probation-period" ":" "integer"
#line 618 "dhcp4_parser.yy"
                                                                 {
    ctx.unique("decline-probation-period", ctx.loc2pos(yystack_[2].location));
    ElementPtr dpp(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("decline-probation-period", dpp);
}
#line 1231 "dhcp4_parser.cc"
    break;

  case 147: // $@20: %empty
#line 624 "dhcp4_parser.yy"
                       {
    ctx.unique("server-tag", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1240 "dhcp4_parser.cc"
    break;

  case 148: // server_tag: "server-tag" $@20 ":" "constant string"
#line 627 "dhcp4_parser.yy"
               {
    ElementPtr stag(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-tag", stag);
    ctx.leave();
}
#line 1250 "dhcp4_parser.cc"
    break;

  case 149: // parked_packet_limit: "parked-packet-limit" ":" "integer"
#line 633 "dhcp4_parser.yy"
                                                       {
    ctx.unique("parked-packet-limit", ctx.loc2pos(yystack_[2].location));
    ElementPtr ppl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("parked-packet-limit", ppl);
}
#line 1260 "dhcp4_parser.cc"
    break;

  case 150: // $@21: %empty
#line 639 "dhcp4_parser.yy"
                     {
    ctx.unique("allocator", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1269 "dhcp4_parser.cc"
    break;

  case 151: // allocator: "allocator" $@21 ":" "constant string"
#line 642 "dhcp4_parser.yy"
               {
    ElementPtr al(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("allocator", al);
    ctx.leave();
}
#line 1279 "dhcp4_parser.cc"
    break;

  case 152: // exclude_first_last_24: "exclude-first-last-24" ":" "boolean"
#line 648 "dhcp4_parser.yy"
                                                           {
    ctx.unique("exclude-first-last-24", ctx.loc2pos(yystack_[2].location));
    ElementPtr exfl(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("exclude-first-last-24", exfl);
}
#line 1289 "dhcp4_parser.cc"
    break;

  case 153: // echo_client_id: "echo-client-id" ":" "boolean"
#line 654 "dhcp4_parser.yy"
                                             {
    ctx.unique("echo-client-id", ctx.loc2pos(yystack_[2].location));
    ElementPtr echo(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("echo-client-id", echo);
}
#line 1299 "dhcp4_parser.cc"
    break;

  case 154: // match_client_id: "match-client-id" ":" "boolean"
#line 660 "dhcp4_parser.yy"
                                               {
    ctx.unique("match-client-id", ctx.loc2pos(yystack_[2].location));
    ElementPtr match(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("match-client-id", match);
}
#line 1309 "dhcp4_parser.cc"
    break;

  case 155: // authoritative: "authoritative" ":" "boolean"
#line 666 "dhcp4_parser.yy"
                                           {
    ctx.unique("authoritative", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("authoritative", prf);
}
#line 1319 "dhcp4_parser.cc"
    break;

  case 156: // ddns_send_updates: "ddns-send-updates" ":" "boolean"
#line 672 "dhcp4_parser.yy"
                                                   {
    ctx.unique("ddns-send-updates", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-send-updates", b);
}
#line 1329 "dhcp4_parser.cc"
    break;

  case 157: // ddns_override_no_update: "ddns-override-no-update" ":" "boolean"
#line 678 "dhcp4_parser.yy"
                                                               {
    ctx.unique("ddns-override-no-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-override-no-update", b);
}
#line 1339 "dhcp4_parser.cc"
    break;

  case 158: // ddns_override_client_update: "ddns-override-client-update" ":" "boolean"
#line 684 "dhcp4_parser.yy"
                                                                       {
    ctx.unique("ddns-override-client-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-override-client-update", b);
}
#line 1349 "dhcp4_parser.cc"
    break;

  case 159: // $@22: %empty
#line 690 "dhcp4_parser.yy"
                                                   {
    ctx.enter(ctx.REPLACE_CLIENT_NAME);
    ctx.unique("ddns-replace-client-name", ctx.loc2pos(yystack_[0].location));
}
#line 1358 "dhcp4_parser.cc"
    break;

  case 160: // ddns_replace_client_name: "ddns-replace-client-name" $@22 ":" ddns_replace_client_name_value
#line 693 "dhcp4_parser.yy"
                                       {
    ctx.stack_.back()->set("ddns-replace-client-name", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1367 "dhcp4_parser.cc"
    break;

  case 161: // ddns_replace_client_name_value: "when-present"
#line 699 "dhcp4_parser.yy"
                 {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("when-present", ctx.loc2pos(yystack_[0].location)));
      }
#line 1375 "dhcp4_parser.cc"
    break;

  case 162: // ddns_replace_client_name_value: "never"
#line 702 "dhcp4_parser.yy"
          {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("never", ctx.loc2pos(yystack_[0].location)));
      }
#line 1383 "dhcp4_parser.cc"
    break;

  case 163: // ddns_replace_client_name_value: "always"
#line 705 "dhcp4_parser.yy"
           {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("always", ctx.loc2pos(yystack_[0].location)));
      }
#line 1391 "dhcp4_parser.cc"
    break;

  case 164: // ddns_replace_client_name_value: "when-not-present"
#line 708 "dhcp4_parser.yy"
                     {
      yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("when-not-present", ctx.loc2pos(yystack_[0].location)));
      }
#line 1399 "dhcp4_parser.cc"
    break;

  case 165: // ddns_replace_client_name_value: "boolean"
#line 711 "dhcp4_parser.yy"
            {
      error(yystack_[0].location, "boolean values for the replace-client-name are "
                "no longer supported");
      }
#line 1408 "dhcp4_parser.cc"
    break;

  case 166: // $@23: %empty
#line 717 "dhcp4_parser.yy"
                                             {
    ctx.unique("ddns-generated-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1417 "dhcp4_parser.cc"
    break;

  case 167: // ddns_generated_prefix: "ddns-generated-prefix" $@23 ":" "constant string"
#line 720 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-generated-prefix", s);
    ctx.leave();
}
#line 1427 "dhcp4_parser.cc"
    break;

  case 168: // $@24: %empty
#line 726 "dhcp4_parser.yy"
                                               {
    ctx.unique("ddns-qualifying-suffix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1436 "dhcp4_parser.cc"
    break;

  case 169: // ddns_qualifying_suffix: "ddns-qualifying-suffix" $@24 ":" "constant string"
#line 729 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-qualifying-suffix", s);
    ctx.leave();
}
#line 1446 "dhcp4_parser.cc"
    break;

  case 170: // ddns_update_on_renew: "ddns-update-on-renew" ":" "boolean"
#line 735 "dhcp4_parser.yy"
                                                         {
    ctx.unique("ddns-update-on-renew", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-update-on-renew", b);
}
#line 1456 "dhcp4_parser.cc"
    break;

  case 171: // ddns_use_conflict_resolution: "ddns-use-conflict-resolution" ":" "boolean"
#line 741 "dhcp4_parser.yy"
                                                                         {
    ctx.unique("ddns-use-conflict-resolution", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-use-conflict-resolution", b);
}
#line 1466 "dhcp4_parser.cc"
    break;

  case 172: // $@25: %empty
#line 747 "dhcp4_parser.yy"
                                     {
    ctx.unique("hostname-char-set", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1475 "dhcp4_parser.cc"
    break;

  case 173: // hostname_char_set: "hostname-char-set" $@25 ":" "constant string"
#line 750 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-set", s);
    ctx.leave();
}
#line 1485 "dhcp4_parser.cc"
    break;

  case 174: // $@26: %empty
#line 756 "dhcp4_parser.yy"
                                                     {
    ctx.unique("hostname-char-replacement", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1494 "dhcp4_parser.cc"
    break;

  case 175: // hostname_char_replacement: "hostname-char-replacement" $@26 ":" "constant string"
#line 759 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-replacement", s);
    ctx.leave();
}
#line 1504 "dhcp4_parser.cc"
    break;

  case 176: // store_extended_info: "store-extended-info" ":" "boolean"
#line 765 "dhcp4_parser.yy"
                                                       {
    ctx.unique("store-extended-info", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("store-extended-info", b);
}
#line 1514 "dhcp4_parser.cc"
    break;

  case 177: // statistic_default_sample_count: "statistic-default-sample-count" ":" "integer"
#line 771 "dhcp4_parser.yy"
                                                                             {
    ctx.unique("statistic-default-sample-count", ctx.loc2pos(yystack_[2].location));
    ElementPtr count(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("statistic-default-sample-count", count);
}
#line 1524 "dhcp4_parser.cc"
    break;

  case 178: // statistic_default_sample_age: "statistic-default-sample-age" ":" "integer"
#line 777 "dhcp4_parser.yy"
                                                                         {
    ctx.unique("statistic-default-sample-age", ctx.loc2pos(yystack_[2].location));
    ElementPtr age(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("statistic-default-sample-age", age);
}
#line 1534 "dhcp4_parser.cc"
    break;

  case 179: // early_global_reservations_lookup: "early-global-reservations-lookup" ":" "boolean"
#line 783 "dhcp4_parser.yy"
                                                                                 {
    ctx.unique("early-global-reservations-lookup", ctx.loc2pos(yystack_[2].location));
    ElementPtr early(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("early-global-reservations-lookup", early);
}
#line 1544 "dhcp4_parser.cc"
    break;

  case 180: // ip_reservations_unique: "ip-reservations-unique" ":" "boolean"
#line 789 "dhcp4_parser.yy"
                                                             {
    ctx.unique("ip-reservations-unique", ctx.loc2pos(yystack_[2].location));
    ElementPtr unique(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-reservations-unique", unique);
}
#line 1554 "dhcp4_parser.cc"
    break;

  case 181: // reservations_lookup_first: "reservations-lookup-first" ":" "boolean"
#line 795 "dhcp4_parser.yy"
                                                                   {
    ctx.unique("reservations-lookup-first", ctx.loc2pos(yystack_[2].location));
    ElementPtr first(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-lookup-first", first);
}
#line 1564 "dhcp4_parser.cc"
    break;

  case 182: // $@27: %empty
#line 801 "dhcp4_parser.yy"
                                     {
    ctx.unique("interfaces-config", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interfaces-config", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.INTERFACES_CONFIG);
}
#line 1576 "dhcp4_parser.cc"
    break;

  case 183: // interfaces_config: "interfaces-config" $@27 ":" "{" interfaces_config_params "}"
#line 807 "dhcp4_parser.yy"
                                                               {
    // No interfaces config param is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1586 "dhcp4_parser.cc"
    break;

  case 186: // interfaces_config_params: interfaces_config_params ","
#line 815 "dhcp4_parser.yy"
                                                         {
                            ctx.warnAboutExtraCommas(yystack_[0].location);
                            }
#line 1594 "dhcp4_parser.cc"
    break;

  case 197: // $@28: %empty
#line 832 "dhcp4_parser.yy"
                                {
    // Parse the interfaces-config map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1604 "dhcp4_parser.cc"
    break;

  case 198: // sub_interfaces4: "{" $@28 interfaces_config_params "}"
#line 836 "dhcp4_parser.yy"
                                          {
    // No interfaces config param is required
    // parsing completed
}
#line 1613 "dhcp4_parser.cc"
    break;

  case 199: // $@29: %empty
#line 841 "dhcp4_parser.yy"
                            {
    ctx.unique("interfaces", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interfaces", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1625 "dhcp4_parser.cc"
    break;

  case 200: // interfaces_list: "interfaces" $@29 ":" list_strings
#line 847 "dhcp4_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1634 "dhcp4_parser.cc"
    break;

  case 201: // $@30: %empty
#line 852 "dhcp4_parser.yy"
                                   {
    ctx.unique("dhcp-socket-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DHCP_SOCKET_TYPE);
}
#line 1643 "dhcp4_parser.cc"
    break;

  case 202: // dhcp_socket_type: "dhcp-socket-type" $@30 ":" socket_type
#line 855 "dhcp4_parser.yy"
                    {
    ctx.stack_.back()->set("dhcp-socket-type", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1652 "dhcp4_parser.cc"
    break;

  case 203: // socket_type: "raw"
#line 860 "dhcp4_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("raw", ctx.loc2pos(yystack_[0].location))); }
#line 1658 "dhcp4_parser.cc"
    break;

  case 204: // socket_type: "udp"
#line 861 "dhcp4_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("udp", ctx.loc2pos(yystack_[0].location))); }
#line 1664 "dhcp4_parser.cc"
    break;

  case 205: // $@31: %empty
#line 864 "dhcp4_parser.yy"
                                       {
    ctx.unique("outbound-interface", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.OUTBOUND_INTERFACE);
}
#line 1673 "dhcp4_parser.cc"
    break;

  case 206: // outbound_interface: "outbound-interface" $@31 ":" outbound_interface_value
#line 867 "dhcp4_parser.yy"
                                 {
    ctx.stack_.back()->set("outbound-interface", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1682 "dhcp4_parser.cc"
    break;

  case 207: // outbound_interface_value: "same-as-inbound"
#line 872 "dhcp4_parser.yy"
                                          {
    yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("same-as-inbound", ctx.loc2pos(yystack_[0].location)));
}
#line 1690 "dhcp4_parser.cc"
    break;

  case 208: // outbound_interface_value: "use-routing"
#line 874 "dhcp4_parser.yy"
                {
    yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("use-routing", ctx.loc2pos(yystack_[0].location)));
    }
#line 1698 "dhcp4_parser.cc"
    break;

  case 209: // re_detect: "re-detect" ":" "boolean"
#line 878 "dhcp4_parser.yy"
                                   {
    ctx.unique("re-detect", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("re-detect", b);
}
#line 1708 "dhcp4_parser.cc"
    break;

  case 210: // service_sockets_require_all: "service-sockets-require-all" ":" "boolean"
#line 884 "dhcp4_parser.yy"
                                                                       {
    ctx.unique("service-sockets-require-all", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-require-all", b);
}
#line 1718 "dhcp4_parser.cc"
    break;

  case 211: // service_sockets_retry_wait_time: "service-sockets-retry-wait-time" ":" "integer"
#line 890 "dhcp4_parser.yy"
                                                                               {
    ctx.unique("service-sockets-retry-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-retry-wait-time", n);
}
#line 1728 "dhcp4_parser.cc"
    break;

  case 212: // service_sockets_max_retries: "service-sockets-max-retries" ":" "integer"
#line 896 "dhcp4_parser.yy"
                                                                       {
    ctx.unique("service-sockets-max-retries", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("service-sockets-max-retries", n);
}
#line 1738 "dhcp4_parser.cc"
    break;

  case 213: // $@32: %empty
#line 902 "dhcp4_parser.yy"
                               {
    ctx.unique("lease-database", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lease-database", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.LEASE_DATABASE);
}
#line 1750 "dhcp4_parser.cc"
    break;

  case 214: // lease_database: "lease-database" $@32 ":" "{" database_map_params "}"
#line 908 "dhcp4_parser.yy"
                                                          {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1761 "dhcp4_parser.cc"
    break;

  case 215: // $@33: %empty
#line 915 "dhcp4_parser.yy"
                             {
    ctx.unique("sanity-checks", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sanity-checks", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.SANITY_CHECKS);
}
#line 1773 "dhcp4_parser.cc"
    break;

  case 216: // sanity_checks: "sanity-checks" $@33 ":" "{" sanity_checks_params "}"
#line 921 "dhcp4_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1782 "dhcp4_parser.cc"
    break;

  case 219: // sanity_checks_params: sanity_checks_params ","
#line 928 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 1790 "dhcp4_parser.cc"
    break;

  case 222: // $@34: %empty
#line 937 "dhcp4_parser.yy"
                           {
    ctx.unique("lease-checks", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1799 "dhcp4_parser.cc"
    break;

  case 223: // lease_checks: "lease-checks" $@34 ":" "constant string"
#line 940 "dhcp4_parser.yy"
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
#line 1819 "dhcp4_parser.cc"
    break;

  case 224: // $@35: %empty
#line 956 "dhcp4_parser.yy"
                                           {
    ctx.unique("extended-info-checks", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1828 "dhcp4_parser.cc"
    break;

  case 225: // extended_info_checks: "extended-info-checks" $@35 ":" "constant string"
#line 959 "dhcp4_parser.yy"
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
#line 1847 "dhcp4_parser.cc"
    break;

  case 226: // $@36: %empty
#line 974 "dhcp4_parser.yy"
                               {
    ctx.unique("hosts-database", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hosts-database", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.HOSTS_DATABASE);
}
#line 1859 "dhcp4_parser.cc"
    break;

  case 227: // hosts_database: "hosts-database" $@36 ":" "{" database_map_params "}"
#line 980 "dhcp4_parser.yy"
                                                          {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1870 "dhcp4_parser.cc"
    break;

  case 228: // $@37: %empty
#line 987 "dhcp4_parser.yy"
                                 {
    ctx.unique("hosts-databases", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hosts-databases", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOSTS_DATABASE);
}
#line 1882 "dhcp4_parser.cc"
    break;

  case 229: // hosts_databases: "hosts-databases" $@37 ":" "[" database_list "]"
#line 993 "dhcp4_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1891 "dhcp4_parser.cc"
    break;

  case 234: // not_empty_database_list: not_empty_database_list ","
#line 1004 "dhcp4_parser.yy"
                                                       {
                           ctx.warnAboutExtraCommas(yystack_[0].location);
                           }
#line 1899 "dhcp4_parser.cc"
    break;

  case 235: // $@38: %empty
#line 1009 "dhcp4_parser.yy"
                         {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1909 "dhcp4_parser.cc"
    break;

  case 236: // database: "{" $@38 database_map_params "}"
#line 1013 "dhcp4_parser.yy"
                                     {
    // The type parameter is required
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 1919 "dhcp4_parser.cc"
    break;

  case 239: // database_map_params: database_map_params ","
#line 1021 "dhcp4_parser.yy"
                                               {
                       ctx.warnAboutExtraCommas(yystack_[0].location);
                       }
#line 1927 "dhcp4_parser.cc"
    break;

  case 262: // $@39: %empty
#line 1050 "dhcp4_parser.yy"
                    {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DATABASE_TYPE);
}
#line 1936 "dhcp4_parser.cc"
    break;

  case 263: // database_type: "type" $@39 ":" db_type
#line 1053 "dhcp4_parser.yy"
                {
    ctx.stack_.back()->set("type", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1945 "dhcp4_parser.cc"
    break;

  case 264: // db_type: "memfile"
#line 1058 "dhcp4_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("memfile", ctx.loc2pos(yystack_[0].location))); }
#line 1951 "dhcp4_parser.cc"
    break;

  case 265: // db_type: "mysql"
#line 1059 "dhcp4_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("mysql", ctx.loc2pos(yystack_[0].location))); }
#line 1957 "dhcp4_parser.cc"
    break;

  case 266: // db_type: "postgresql"
#line 1060 "dhcp4_parser.yy"
                    { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("postgresql", ctx.loc2pos(yystack_[0].location))); }
#line 1963 "dhcp4_parser.cc"
    break;

  case 267: // $@40: %empty
#line 1063 "dhcp4_parser.yy"
           {
    ctx.unique("user", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1972 "dhcp4_parser.cc"
    break;

  case 268: // user: "user" $@40 ":" "constant string"
#line 1066 "dhcp4_parser.yy"
               {
    ElementPtr user(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("user", user);
    ctx.leave();
}
#line 1982 "dhcp4_parser.cc"
    break;

  case 269: // $@41: %empty
#line 1072 "dhcp4_parser.yy"
                   {
    ctx.unique("password", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1991 "dhcp4_parser.cc"
    break;

  case 270: // password: "password" $@41 ":" "constant string"
#line 1075 "dhcp4_parser.yy"
               {
    ElementPtr pwd(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("password", pwd);
    ctx.leave();
}
#line 2001 "dhcp4_parser.cc"
    break;

  case 271: // $@42: %empty
#line 1081 "dhcp4_parser.yy"
           {
    ctx.unique("host", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2010 "dhcp4_parser.cc"
    break;

  case 272: // host: "host" $@42 ":" "constant string"
#line 1084 "dhcp4_parser.yy"
               {
    ElementPtr h(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("host", h);
    ctx.leave();
}
#line 2020 "dhcp4_parser.cc"
    break;

  case 273: // port: "port" ":" "integer"
#line 1090 "dhcp4_parser.yy"
                         {
    ctx.unique("port", ctx.loc2pos(yystack_[2].location));
    ElementPtr p(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("port", p);
}
#line 2030 "dhcp4_parser.cc"
    break;

  case 274: // $@43: %empty
#line 1096 "dhcp4_parser.yy"
           {
    ctx.unique("name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2039 "dhcp4_parser.cc"
    break;

  case 275: // name: "name" $@43 ":" "constant string"
#line 1099 "dhcp4_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("name", name);
    ctx.leave();
}
#line 2049 "dhcp4_parser.cc"
    break;

  case 276: // persist: "persist" ":" "boolean"
#line 1105 "dhcp4_parser.yy"
                               {
    ctx.unique("persist", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("persist", n);
}
#line 2059 "dhcp4_parser.cc"
    break;

  case 277: // lfc_interval: "lfc-interval" ":" "integer"
#line 1111 "dhcp4_parser.yy"
                                         {
    ctx.unique("lfc-interval", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lfc-interval", n);
}
#line 2069 "dhcp4_parser.cc"
    break;

  case 278: // readonly: "readonly" ":" "boolean"
#line 1117 "dhcp4_parser.yy"
                                 {
    ctx.unique("readonly", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("readonly", n);
}
#line 2079 "dhcp4_parser.cc"
    break;

  case 279: // connect_timeout: "connect-timeout" ":" "integer"
#line 1123 "dhcp4_parser.yy"
                                               {
    ctx.unique("connect-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("connect-timeout", n);
}
#line 2089 "dhcp4_parser.cc"
    break;

  case 280: // read_timeout: "read-timeout" ":" "integer"
#line 1129 "dhcp4_parser.yy"
                                         {
    ctx.unique("read-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("read-timeout", n);
}
#line 2099 "dhcp4_parser.cc"
    break;

  case 281: // write_timeout: "write-timeout" ":" "integer"
#line 1135 "dhcp4_parser.yy"
                                           {
    ctx.unique("write-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("write-timeout", n);
}
#line 2109 "dhcp4_parser.cc"
    break;

  case 282: // tcp_user_timeout: "tcp-user-timeout" ":" "integer"
#line 1141 "dhcp4_parser.yy"
                                                 {
    ctx.unique("tcp-user-timeout", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("tcp-user-timeout", n);
}
#line 2119 "dhcp4_parser.cc"
    break;

  case 283: // max_reconnect_tries: "max-reconnect-tries" ":" "integer"
#line 1147 "dhcp4_parser.yy"
                                                       {
    ctx.unique("max-reconnect-tries", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reconnect-tries", n);
}
#line 2129 "dhcp4_parser.cc"
    break;

  case 284: // reconnect_wait_time: "reconnect-wait-time" ":" "integer"
#line 1153 "dhcp4_parser.yy"
                                                       {
    ctx.unique("reconnect-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reconnect-wait-time", n);
}
#line 2139 "dhcp4_parser.cc"
    break;

  case 285: // $@44: %empty
#line 1159 "dhcp4_parser.yy"
                 {
    ctx.unique("on-fail", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.DATABASE_ON_FAIL);
}
#line 2148 "dhcp4_parser.cc"
    break;

  case 286: // on_fail: "on-fail" $@44 ":" on_fail_mode
#line 1162 "dhcp4_parser.yy"
                     {
    ctx.stack_.back()->set("on-fail", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2157 "dhcp4_parser.cc"
    break;

  case 287: // on_fail_mode: "stop-retry-exit"
#line 1167 "dhcp4_parser.yy"
                              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("stop-retry-exit", ctx.loc2pos(yystack_[0].location))); }
#line 2163 "dhcp4_parser.cc"
    break;

  case 288: // on_fail_mode: "serve-retry-exit"
#line 1168 "dhcp4_parser.yy"
                               { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("serve-retry-exit", ctx.loc2pos(yystack_[0].location))); }
#line 2169 "dhcp4_parser.cc"
    break;

  case 289: // on_fail_mode: "serve-retry-continue"
#line 1169 "dhcp4_parser.yy"
                                   { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("serve-retry-continue", ctx.loc2pos(yystack_[0].location))); }
#line 2175 "dhcp4_parser.cc"
    break;

  case 290: // max_row_errors: "max-row-errors" ":" "integer"
#line 1172 "dhcp4_parser.yy"
                                             {
    ctx.unique("max-row-errors", ctx.loc2pos(yystack_[2].location));
    ElementPtr n(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-row-errors", n);
}
#line 2185 "dhcp4_parser.cc"
    break;

  case 291: // $@45: %empty
#line 1178 "dhcp4_parser.yy"
                           {
    ctx.unique("trust-anchor", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2194 "dhcp4_parser.cc"
    break;

  case 292: // trust_anchor: "trust-anchor" $@45 ":" "constant string"
#line 1181 "dhcp4_parser.yy"
               {
    ElementPtr ca(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("trust-anchor", ca);
    ctx.leave();
}
#line 2204 "dhcp4_parser.cc"
    break;

  case 293: // $@46: %empty
#line 1187 "dhcp4_parser.yy"
                     {
    ctx.unique("cert-file", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2213 "dhcp4_parser.cc"
    break;

  case 294: // cert_file: "cert-file" $@46 ":" "constant string"
#line 1190 "dhcp4_parser.yy"
               {
    ElementPtr cert(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cert-file", cert);
    ctx.leave();
}
#line 2223 "dhcp4_parser.cc"
    break;

  case 295: // $@47: %empty
#line 1196 "dhcp4_parser.yy"
                   {
    ctx.unique("key-file", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2232 "dhcp4_parser.cc"
    break;

  case 296: // key_file: "key-file" $@47 ":" "constant string"
#line 1199 "dhcp4_parser.yy"
               {
    ElementPtr key(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("key-file", key);
    ctx.leave();
}
#line 2242 "dhcp4_parser.cc"
    break;

  case 297: // $@48: %empty
#line 1205 "dhcp4_parser.yy"
                         {
    ctx.unique("cipher-list", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2251 "dhcp4_parser.cc"
    break;

  case 298: // cipher_list: "cipher-list" $@48 ":" "constant string"
#line 1208 "dhcp4_parser.yy"
               {
    ElementPtr cl(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("cipher-list", cl);
    ctx.leave();
}
#line 2261 "dhcp4_parser.cc"
    break;

  case 299: // $@49: %empty
#line 1214 "dhcp4_parser.yy"
                                                           {
    ctx.unique("host-reservation-identifiers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("host-reservation-identifiers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOST_RESERVATION_IDENTIFIERS);
}
#line 2273 "dhcp4_parser.cc"
    break;

  case 300: // host_reservation_identifiers: "host-reservation-identifiers" $@49 ":" "[" host_reservation_identifiers_list "]"
#line 1220 "dhcp4_parser.yy"
                                                                          {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2282 "dhcp4_parser.cc"
    break;

  case 303: // host_reservation_identifiers_list: host_reservation_identifiers_list ","
#line 1227 "dhcp4_parser.yy"
                                              {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 2290 "dhcp4_parser.cc"
    break;

  case 309: // duid_id: "duid"
#line 1239 "dhcp4_parser.yy"
              {
    ElementPtr duid(new StringElement("duid", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(duid);
}
#line 2299 "dhcp4_parser.cc"
    break;

  case 310: // hw_address_id: "hw-address"
#line 1244 "dhcp4_parser.yy"
                          {
    ElementPtr hwaddr(new StringElement("hw-address", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(hwaddr);
}
#line 2308 "dhcp4_parser.cc"
    break;

  case 311: // circuit_id: "circuit-id"
#line 1249 "dhcp4_parser.yy"
                       {
    ElementPtr circuit(new StringElement("circuit-id", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(circuit);
}
#line 2317 "dhcp4_parser.cc"
    break;

  case 312: // client_id: "client-id"
#line 1254 "dhcp4_parser.yy"
                     {
    ElementPtr client(new StringElement("client-id", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(client);
}
#line 2326 "dhcp4_parser.cc"
    break;

  case 313: // flex_id: "flex-id"
#line 1259 "dhcp4_parser.yy"
                 {
    ElementPtr flex_id(new StringElement("flex-id", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(flex_id);
}
#line 2335 "dhcp4_parser.cc"
    break;

  case 314: // $@50: %empty
#line 1266 "dhcp4_parser.yy"
                                           {
    ctx.unique("multi-threading", ctx.loc2pos(yystack_[0].location));
    ElementPtr mt(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("multi-threading", mt);
    ctx.stack_.push_back(mt);
    ctx.enter(ctx.DHCP_MULTI_THREADING);
}
#line 2347 "dhcp4_parser.cc"
    break;

  case 315: // dhcp_multi_threading: "multi-threading" $@50 ":" "{" multi_threading_params "}"
#line 1272 "dhcp4_parser.yy"
                                                             {
    // The enable parameter is required.
    ctx.require("enable-multi-threading", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2358 "dhcp4_parser.cc"
    break;

  case 318: // multi_threading_params: multi_threading_params ","
#line 1281 "dhcp4_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 2366 "dhcp4_parser.cc"
    break;

  case 325: // enable_multi_threading: "enable-multi-threading" ":" "boolean"
#line 1294 "dhcp4_parser.yy"
                                                             {
    ctx.unique("enable-multi-threading", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-multi-threading", b);
}
#line 2376 "dhcp4_parser.cc"
    break;

  case 326: // thread_pool_size: "thread-pool-size" ":" "integer"
#line 1300 "dhcp4_parser.yy"
                                                 {
    ctx.unique("thread-pool-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("thread-pool-size", prf);
}
#line 2386 "dhcp4_parser.cc"
    break;

  case 327: // packet_queue_size: "packet-queue-size" ":" "integer"
#line 1306 "dhcp4_parser.yy"
                                                   {
    ctx.unique("packet-queue-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr prf(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("packet-queue-size", prf);
}
#line 2396 "dhcp4_parser.cc"
    break;

  case 328: // $@51: %empty
#line 1312 "dhcp4_parser.yy"
                                 {
    ctx.unique("hooks-libraries", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hooks-libraries", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOOKS_LIBRARIES);
}
#line 2408 "dhcp4_parser.cc"
    break;

  case 329: // hooks_libraries: "hooks-libraries" $@51 ":" "[" hooks_libraries_list "]"
#line 1318 "dhcp4_parser.yy"
                                                             {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2417 "dhcp4_parser.cc"
    break;

  case 334: // not_empty_hooks_libraries_list: not_empty_hooks_libraries_list ","
#line 1329 "dhcp4_parser.yy"
                                           {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 2425 "dhcp4_parser.cc"
    break;

  case 335: // $@52: %empty
#line 1334 "dhcp4_parser.yy"
                              {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2435 "dhcp4_parser.cc"
    break;

  case 336: // hooks_library: "{" $@52 hooks_params "}"
#line 1338 "dhcp4_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 2445 "dhcp4_parser.cc"
    break;

  case 337: // $@53: %empty
#line 1344 "dhcp4_parser.yy"
                                  {
    // Parse the hooks-libraries list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2455 "dhcp4_parser.cc"
    break;

  case 338: // sub_hooks_library: "{" $@53 hooks_params "}"
#line 1348 "dhcp4_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2465 "dhcp4_parser.cc"
    break;

  case 341: // hooks_params: hooks_params ","
#line 1356 "dhcp4_parser.yy"
                                 {
                ctx.warnAboutExtraCommas(yystack_[0].location);
                }
#line 2473 "dhcp4_parser.cc"
    break;

  case 345: // $@54: %empty
#line 1366 "dhcp4_parser.yy"
                 {
    ctx.unique("library", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2482 "dhcp4_parser.cc"
    break;

  case 346: // library: "library" $@54 ":" "constant string"
#line 1369 "dhcp4_parser.yy"
               {
    ElementPtr lib(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("library", lib);
    ctx.leave();
}
#line 2492 "dhcp4_parser.cc"
    break;

  case 347: // $@55: %empty
#line 1375 "dhcp4_parser.yy"
                       {
    ctx.unique("parameters", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2501 "dhcp4_parser.cc"
    break;

  case 348: // parameters: "parameters" $@55 ":" map_value
#line 1378 "dhcp4_parser.yy"
                  {
    ctx.stack_.back()->set("parameters", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2510 "dhcp4_parser.cc"
    break;

  case 349: // $@56: %empty
#line 1384 "dhcp4_parser.yy"
                                                     {
    ctx.unique("expired-leases-processing", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("expired-leases-processing", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.EXPIRED_LEASES_PROCESSING);
}
#line 2522 "dhcp4_parser.cc"
    break;

  case 350: // expired_leases_processing: "expired-leases-processing" $@56 ":" "{" expired_leases_params "}"
#line 1390 "dhcp4_parser.yy"
                                                            {
    // No expired lease parameter is required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2532 "dhcp4_parser.cc"
    break;

  case 353: // expired_leases_params: expired_leases_params ","
#line 1398 "dhcp4_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 2540 "dhcp4_parser.cc"
    break;

  case 360: // reclaim_timer_wait_time: "reclaim-timer-wait-time" ":" "integer"
#line 1411 "dhcp4_parser.yy"
                                                               {
    ctx.unique("reclaim-timer-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reclaim-timer-wait-time", value);
}
#line 2550 "dhcp4_parser.cc"
    break;

  case 361: // flush_reclaimed_timer_wait_time: "flush-reclaimed-timer-wait-time" ":" "integer"
#line 1417 "dhcp4_parser.yy"
                                                                               {
    ctx.unique("flush-reclaimed-timer-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush-reclaimed-timer-wait-time", value);
}
#line 2560 "dhcp4_parser.cc"
    break;

  case 362: // hold_reclaimed_time: "hold-reclaimed-time" ":" "integer"
#line 1423 "dhcp4_parser.yy"
                                                       {
    ctx.unique("hold-reclaimed-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hold-reclaimed-time", value);
}
#line 2570 "dhcp4_parser.cc"
    break;

  case 363: // max_reclaim_leases: "max-reclaim-leases" ":" "integer"
#line 1429 "dhcp4_parser.yy"
                                                     {
    ctx.unique("max-reclaim-leases", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reclaim-leases", value);
}
#line 2580 "dhcp4_parser.cc"
    break;

  case 364: // max_reclaim_time: "max-reclaim-time" ":" "integer"
#line 1435 "dhcp4_parser.yy"
                                                 {
    ctx.unique("max-reclaim-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-reclaim-time", value);
}
#line 2590 "dhcp4_parser.cc"
    break;

  case 365: // unwarned_reclaim_cycles: "unwarned-reclaim-cycles" ":" "integer"
#line 1441 "dhcp4_parser.yy"
                                                               {
    ctx.unique("unwarned-reclaim-cycles", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("unwarned-reclaim-cycles", value);
}
#line 2600 "dhcp4_parser.cc"
    break;

  case 366: // $@57: %empty
#line 1450 "dhcp4_parser.yy"
                      {
    ctx.unique("subnet4", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("subnet4", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.SUBNET4);
}
#line 2612 "dhcp4_parser.cc"
    break;

  case 367: // subnet4_list: "subnet4" $@57 ":" "[" subnet4_list_content "]"
#line 1456 "dhcp4_parser.yy"
                                                             {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2621 "dhcp4_parser.cc"
    break;

  case 372: // not_empty_subnet4_list: not_empty_subnet4_list ","
#line 1470 "dhcp4_parser.yy"
                                                     {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 2629 "dhcp4_parser.cc"
    break;

  case 373: // $@58: %empty
#line 1479 "dhcp4_parser.yy"
                        {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2639 "dhcp4_parser.cc"
    break;

  case 374: // subnet4: "{" $@58 subnet4_params "}"
#line 1483 "dhcp4_parser.yy"
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
#line 2665 "dhcp4_parser.cc"
    break;

  case 375: // $@59: %empty
#line 1505 "dhcp4_parser.yy"
                            {
    // Parse the subnet4 list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2675 "dhcp4_parser.cc"
    break;

  case 376: // sub_subnet4: "{" $@59 subnet4_params "}"
#line 1509 "dhcp4_parser.yy"
                                {
    // The subnet subnet4 parameter is required
    ctx.require("subnet", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 2685 "dhcp4_parser.cc"
    break;

  case 379: // subnet4_params: subnet4_params ","
#line 1518 "dhcp4_parser.yy"
                                     {
                  ctx.warnAboutExtraCommas(yystack_[0].location);
                  }
#line 2693 "dhcp4_parser.cc"
    break;

  case 426: // $@60: %empty
#line 1572 "dhcp4_parser.yy"
               {
    ctx.unique("subnet", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2702 "dhcp4_parser.cc"
    break;

  case 427: // subnet: "subnet" $@60 ":" "constant string"
#line 1575 "dhcp4_parser.yy"
               {
    ElementPtr subnet(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("subnet", subnet);
    ctx.leave();
}
#line 2712 "dhcp4_parser.cc"
    break;

  case 428: // $@61: %empty
#line 1581 "dhcp4_parser.yy"
                                           {
    ctx.unique("4o6-interface", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2721 "dhcp4_parser.cc"
    break;

  case 429: // subnet_4o6_interface: "4o6-interface" $@61 ":" "constant string"
#line 1584 "dhcp4_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("4o6-interface", iface);
    ctx.leave();
}
#line 2731 "dhcp4_parser.cc"
    break;

  case 430: // $@62: %empty
#line 1590 "dhcp4_parser.yy"
                                                 {
    ctx.unique("4o6-interface-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2740 "dhcp4_parser.cc"
    break;

  case 431: // subnet_4o6_interface_id: "4o6-interface-id" $@62 ":" "constant string"
#line 1593 "dhcp4_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("4o6-interface-id", iface);
    ctx.leave();
}
#line 2750 "dhcp4_parser.cc"
    break;

  case 432: // $@63: %empty
#line 1599 "dhcp4_parser.yy"
                                     {
    ctx.unique("4o6-subnet", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2759 "dhcp4_parser.cc"
    break;

  case 433: // subnet_4o6_subnet: "4o6-subnet" $@63 ":" "constant string"
#line 1602 "dhcp4_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("4o6-subnet", iface);
    ctx.leave();
}
#line 2769 "dhcp4_parser.cc"
    break;

  case 434: // $@64: %empty
#line 1608 "dhcp4_parser.yy"
                     {
    ctx.unique("interface", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2778 "dhcp4_parser.cc"
    break;

  case 435: // interface: "interface" $@64 ":" "constant string"
#line 1611 "dhcp4_parser.yy"
               {
    ElementPtr iface(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("interface", iface);
    ctx.leave();
}
#line 2788 "dhcp4_parser.cc"
    break;

  case 436: // $@65: %empty
#line 1617 "dhcp4_parser.yy"
                           {
    ctx.unique("client-class", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2797 "dhcp4_parser.cc"
    break;

  case 437: // client_class: "client-class" $@65 ":" "constant string"
#line 1620 "dhcp4_parser.yy"
               {
    ElementPtr cls(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-class", cls);
    ctx.leave();
}
#line 2807 "dhcp4_parser.cc"
    break;

  case 438: // $@66: %empty
#line 1626 "dhcp4_parser.yy"
                                               {
    ctx.unique("require-client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr c(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("require-client-classes", c);
    ctx.stack_.push_back(c);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 2819 "dhcp4_parser.cc"
    break;

  case 439: // require_client_classes: "require-client-classes" $@66 ":" list_strings
#line 1632 "dhcp4_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2828 "dhcp4_parser.cc"
    break;

  case 440: // reservations_global: "reservations-global" ":" "boolean"
#line 1637 "dhcp4_parser.yy"
                                                       {
    ctx.unique("reservations-global", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-global", b);
}
#line 2838 "dhcp4_parser.cc"
    break;

  case 441: // reservations_in_subnet: "reservations-in-subnet" ":" "boolean"
#line 1643 "dhcp4_parser.yy"
                                                             {
    ctx.unique("reservations-in-subnet", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-in-subnet", b);
}
#line 2848 "dhcp4_parser.cc"
    break;

  case 442: // reservations_out_of_pool: "reservations-out-of-pool" ":" "boolean"
#line 1649 "dhcp4_parser.yy"
                                                                 {
    ctx.unique("reservations-out-of-pool", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations-out-of-pool", b);
}
#line 2858 "dhcp4_parser.cc"
    break;

  case 443: // $@67: %empty
#line 1655 "dhcp4_parser.yy"
                                   {
    ctx.unique("reservation-mode", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.RESERVATION_MODE);
}
#line 2867 "dhcp4_parser.cc"
    break;

  case 444: // reservation_mode: "reservation-mode" $@67 ":" hr_mode
#line 1658 "dhcp4_parser.yy"
                {
    ctx.stack_.back()->set("reservation-mode", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 2876 "dhcp4_parser.cc"
    break;

  case 445: // hr_mode: "disabled"
#line 1663 "dhcp4_parser.yy"
                  { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("disabled", ctx.loc2pos(yystack_[0].location))); }
#line 2882 "dhcp4_parser.cc"
    break;

  case 446: // hr_mode: "out-of-pool"
#line 1664 "dhcp4_parser.yy"
                     { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("out-of-pool", ctx.loc2pos(yystack_[0].location))); }
#line 2888 "dhcp4_parser.cc"
    break;

  case 447: // hr_mode: "global"
#line 1665 "dhcp4_parser.yy"
                { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("global", ctx.loc2pos(yystack_[0].location))); }
#line 2894 "dhcp4_parser.cc"
    break;

  case 448: // hr_mode: "all"
#line 1666 "dhcp4_parser.yy"
             { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("all", ctx.loc2pos(yystack_[0].location))); }
#line 2900 "dhcp4_parser.cc"
    break;

  case 449: // id: "id" ":" "integer"
#line 1669 "dhcp4_parser.yy"
                     {
    ctx.unique("id", ctx.loc2pos(yystack_[2].location));
    ElementPtr id(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("id", id);
}
#line 2910 "dhcp4_parser.cc"
    break;

  case 450: // $@68: %empty
#line 1677 "dhcp4_parser.yy"
                                 {
    ctx.unique("shared-networks", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("shared-networks", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.SHARED_NETWORK);
}
#line 2922 "dhcp4_parser.cc"
    break;

  case 451: // shared_networks: "shared-networks" $@68 ":" "[" shared_networks_content "]"
#line 1683 "dhcp4_parser.yy"
                                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2931 "dhcp4_parser.cc"
    break;

  case 456: // shared_networks_list: shared_networks_list ","
#line 1696 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 2939 "dhcp4_parser.cc"
    break;

  case 457: // $@69: %empty
#line 1701 "dhcp4_parser.yy"
                               {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 2949 "dhcp4_parser.cc"
    break;

  case 458: // shared_network: "{" $@69 shared_network_params "}"
#line 1705 "dhcp4_parser.yy"
                                       {
    ctx.stack_.pop_back();
}
#line 2957 "dhcp4_parser.cc"
    break;

  case 461: // shared_network_params: shared_network_params ","
#line 1711 "dhcp4_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 2965 "dhcp4_parser.cc"
    break;

  case 503: // $@70: %empty
#line 1763 "dhcp4_parser.yy"
                            {
    ctx.unique("option-def", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("option-def", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OPTION_DEF);
}
#line 2977 "dhcp4_parser.cc"
    break;

  case 504: // option_def_list: "option-def" $@70 ":" "[" option_def_list_content "]"
#line 1769 "dhcp4_parser.yy"
                                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 2986 "dhcp4_parser.cc"
    break;

  case 505: // $@71: %empty
#line 1777 "dhcp4_parser.yy"
                                    {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 2995 "dhcp4_parser.cc"
    break;

  case 506: // sub_option_def_list: "{" $@71 option_def_list "}"
#line 1780 "dhcp4_parser.yy"
                                 {
    // parsing completed
}
#line 3003 "dhcp4_parser.cc"
    break;

  case 511: // not_empty_option_def_list: not_empty_option_def_list ","
#line 1792 "dhcp4_parser.yy"
                                                           {
                             ctx.warnAboutExtraCommas(yystack_[0].location);
                             }
#line 3011 "dhcp4_parser.cc"
    break;

  case 512: // $@72: %empty
#line 1799 "dhcp4_parser.yy"
                                 {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3021 "dhcp4_parser.cc"
    break;

  case 513: // option_def_entry: "{" $@72 option_def_params "}"
#line 1803 "dhcp4_parser.yy"
                                   {
    // The name, code and type option def parameters are required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("code", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3033 "dhcp4_parser.cc"
    break;

  case 514: // $@73: %empty
#line 1814 "dhcp4_parser.yy"
                               {
    // Parse the option-def list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3043 "dhcp4_parser.cc"
    break;

  case 515: // sub_option_def: "{" $@73 option_def_params "}"
#line 1818 "dhcp4_parser.yy"
                                   {
    // The name, code and type option def parameters are required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("code", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.require("type", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 3055 "dhcp4_parser.cc"
    break;

  case 520: // not_empty_option_def_params: not_empty_option_def_params ","
#line 1834 "dhcp4_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 3063 "dhcp4_parser.cc"
    break;

  case 532: // code: "code" ":" "integer"
#line 1853 "dhcp4_parser.yy"
                         {
    ctx.unique("code", ctx.loc2pos(yystack_[2].location));
    ElementPtr code(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("code", code);
}
#line 3073 "dhcp4_parser.cc"
    break;

  case 534: // $@74: %empty
#line 1861 "dhcp4_parser.yy"
                      {
    ctx.unique("type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3082 "dhcp4_parser.cc"
    break;

  case 535: // option_def_type: "type" $@74 ":" "constant string"
#line 1864 "dhcp4_parser.yy"
               {
    ElementPtr prf(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("type", prf);
    ctx.leave();
}
#line 3092 "dhcp4_parser.cc"
    break;

  case 536: // $@75: %empty
#line 1870 "dhcp4_parser.yy"
                                      {
    ctx.unique("record-types", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3101 "dhcp4_parser.cc"
    break;

  case 537: // option_def_record_types: "record-types" $@75 ":" "constant string"
#line 1873 "dhcp4_parser.yy"
               {
    ElementPtr rtypes(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("record-types", rtypes);
    ctx.leave();
}
#line 3111 "dhcp4_parser.cc"
    break;

  case 538: // $@76: %empty
#line 1879 "dhcp4_parser.yy"
             {
    ctx.unique("space", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3120 "dhcp4_parser.cc"
    break;

  case 539: // space: "space" $@76 ":" "constant string"
#line 1882 "dhcp4_parser.yy"
               {
    ElementPtr space(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("space", space);
    ctx.leave();
}
#line 3130 "dhcp4_parser.cc"
    break;

  case 541: // $@77: %empty
#line 1890 "dhcp4_parser.yy"
                                    {
    ctx.unique("encapsulate", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3139 "dhcp4_parser.cc"
    break;

  case 542: // option_def_encapsulate: "encapsulate" $@77 ":" "constant string"
#line 1893 "dhcp4_parser.yy"
               {
    ElementPtr encap(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("encapsulate", encap);
    ctx.leave();
}
#line 3149 "dhcp4_parser.cc"
    break;

  case 543: // option_def_array: "array" ":" "boolean"
#line 1899 "dhcp4_parser.yy"
                                      {
    ctx.unique("array", ctx.loc2pos(yystack_[2].location));
    ElementPtr array(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("array", array);
}
#line 3159 "dhcp4_parser.cc"
    break;

  case 544: // $@78: %empty
#line 1909 "dhcp4_parser.yy"
                              {
    ctx.unique("option-data", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("option-data", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OPTION_DATA);
}
#line 3171 "dhcp4_parser.cc"
    break;

  case 545: // option_data_list: "option-data" $@78 ":" "[" option_data_list_content "]"
#line 1915 "dhcp4_parser.yy"
                                                                 {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3180 "dhcp4_parser.cc"
    break;

  case 550: // not_empty_option_data_list: not_empty_option_data_list ","
#line 1930 "dhcp4_parser.yy"
                                                             {
                              ctx.warnAboutExtraCommas(yystack_[0].location);
                              }
#line 3188 "dhcp4_parser.cc"
    break;

  case 551: // $@79: %empty
#line 1937 "dhcp4_parser.yy"
                                  {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3198 "dhcp4_parser.cc"
    break;

  case 552: // option_data_entry: "{" $@79 option_data_params "}"
#line 1941 "dhcp4_parser.yy"
                                    {
    /// @todo: the code or name parameters are required.
    ctx.stack_.pop_back();
}
#line 3207 "dhcp4_parser.cc"
    break;

  case 553: // $@80: %empty
#line 1949 "dhcp4_parser.yy"
                                {
    // Parse the option-data list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3217 "dhcp4_parser.cc"
    break;

  case 554: // sub_option_data: "{" $@80 option_data_params "}"
#line 1953 "dhcp4_parser.yy"
                                    {
    /// @todo: the code or name parameters are required.
    // parsing completed
}
#line 3226 "dhcp4_parser.cc"
    break;

  case 559: // not_empty_option_data_params: not_empty_option_data_params ","
#line 1969 "dhcp4_parser.yy"
                                         {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3234 "dhcp4_parser.cc"
    break;

  case 570: // $@81: %empty
#line 1989 "dhcp4_parser.yy"
                       {
    ctx.unique("data", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3243 "dhcp4_parser.cc"
    break;

  case 571: // option_data_data: "data" $@81 ":" "constant string"
#line 1992 "dhcp4_parser.yy"
               {
    ElementPtr data(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("data", data);
    ctx.leave();
}
#line 3253 "dhcp4_parser.cc"
    break;

  case 574: // option_data_csv_format: "csv-format" ":" "boolean"
#line 2002 "dhcp4_parser.yy"
                                                 {
    ctx.unique("csv-format", ctx.loc2pos(yystack_[2].location));
    ElementPtr space(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("csv-format", space);
}
#line 3263 "dhcp4_parser.cc"
    break;

  case 575: // option_data_always_send: "always-send" ":" "boolean"
#line 2008 "dhcp4_parser.yy"
                                                   {
    ctx.unique("always-send", ctx.loc2pos(yystack_[2].location));
    ElementPtr persist(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("always-send", persist);
}
#line 3273 "dhcp4_parser.cc"
    break;

  case 576: // $@82: %empty
#line 2017 "dhcp4_parser.yy"
                  {
    ctx.unique("pools", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pools", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.POOLS);
}
#line 3285 "dhcp4_parser.cc"
    break;

  case 577: // pools_list: "pools" $@82 ":" "[" pools_list_content "]"
#line 2023 "dhcp4_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3294 "dhcp4_parser.cc"
    break;

  case 582: // not_empty_pools_list: not_empty_pools_list ","
#line 2036 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 3302 "dhcp4_parser.cc"
    break;

  case 583: // $@83: %empty
#line 2041 "dhcp4_parser.yy"
                                {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3312 "dhcp4_parser.cc"
    break;

  case 584: // pool_list_entry: "{" $@83 pool_params "}"
#line 2045 "dhcp4_parser.yy"
                             {
    // The pool parameter is required.
    ctx.require("pool", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3322 "dhcp4_parser.cc"
    break;

  case 585: // $@84: %empty
#line 2051 "dhcp4_parser.yy"
                          {
    // Parse the pool list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3332 "dhcp4_parser.cc"
    break;

  case 586: // sub_pool4: "{" $@84 pool_params "}"
#line 2055 "dhcp4_parser.yy"
                             {
    // The pool parameter is required.
    ctx.require("pool", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 3342 "dhcp4_parser.cc"
    break;

  case 589: // pool_params: pool_params ","
#line 2063 "dhcp4_parser.yy"
                               {
               ctx.warnAboutExtraCommas(yystack_[0].location);
               }
#line 3350 "dhcp4_parser.cc"
    break;

  case 597: // $@85: %empty
#line 2077 "dhcp4_parser.yy"
                 {
    ctx.unique("pool", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3359 "dhcp4_parser.cc"
    break;

  case 598: // pool_entry: "pool" $@85 ":" "constant string"
#line 2080 "dhcp4_parser.yy"
               {
    ElementPtr pool(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pool", pool);
    ctx.leave();
}
#line 3369 "dhcp4_parser.cc"
    break;

  case 599: // $@86: %empty
#line 2086 "dhcp4_parser.yy"
                           {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3377 "dhcp4_parser.cc"
    break;

  case 600: // user_context: "user-context" $@86 ":" map_value
#line 2088 "dhcp4_parser.yy"
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
#line 3404 "dhcp4_parser.cc"
    break;

  case 601: // $@87: %empty
#line 2111 "dhcp4_parser.yy"
                 {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3412 "dhcp4_parser.cc"
    break;

  case 602: // comment: "comment" $@87 ":" "constant string"
#line 2113 "dhcp4_parser.yy"
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
#line 3441 "dhcp4_parser.cc"
    break;

  case 603: // $@88: %empty
#line 2141 "dhcp4_parser.yy"
                           {
    ctx.unique("reservations", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reservations", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.RESERVATIONS);
}
#line 3453 "dhcp4_parser.cc"
    break;

  case 604: // reservations: "reservations" $@88 ":" "[" reservations_list "]"
#line 2147 "dhcp4_parser.yy"
                                                          {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3462 "dhcp4_parser.cc"
    break;

  case 609: // not_empty_reservations_list: not_empty_reservations_list ","
#line 2158 "dhcp4_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 3470 "dhcp4_parser.cc"
    break;

  case 610: // $@89: %empty
#line 2163 "dhcp4_parser.yy"
                            {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3480 "dhcp4_parser.cc"
    break;

  case 611: // reservation: "{" $@89 reservation_params "}"
#line 2167 "dhcp4_parser.yy"
                                    {
    /// @todo: an identifier parameter is required.
    ctx.stack_.pop_back();
}
#line 3489 "dhcp4_parser.cc"
    break;

  case 612: // $@90: %empty
#line 2172 "dhcp4_parser.yy"
                                {
    // Parse the reservations list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 3499 "dhcp4_parser.cc"
    break;

  case 613: // sub_reservation: "{" $@90 reservation_params "}"
#line 2176 "dhcp4_parser.yy"
                                    {
    /// @todo: an identifier parameter is required.
    // parsing completed
}
#line 3508 "dhcp4_parser.cc"
    break;

  case 618: // not_empty_reservation_params: not_empty_reservation_params ","
#line 2187 "dhcp4_parser.yy"
                                         {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3516 "dhcp4_parser.cc"
    break;

  case 634: // $@91: %empty
#line 2210 "dhcp4_parser.yy"
                         {
    ctx.unique("next-server", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3525 "dhcp4_parser.cc"
    break;

  case 635: // next_server: "next-server" $@91 ":" "constant string"
#line 2213 "dhcp4_parser.yy"
               {
    ElementPtr next_server(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("next-server", next_server);
    ctx.leave();
}
#line 3535 "dhcp4_parser.cc"
    break;

  case 636: // $@92: %empty
#line 2219 "dhcp4_parser.yy"
                                 {
    ctx.unique("server-hostname", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3544 "dhcp4_parser.cc"
    break;

  case 637: // server_hostname: "server-hostname" $@92 ":" "constant string"
#line 2222 "dhcp4_parser.yy"
               {
    ElementPtr srv(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-hostname", srv);
    ctx.leave();
}
#line 3554 "dhcp4_parser.cc"
    break;

  case 638: // $@93: %empty
#line 2228 "dhcp4_parser.yy"
                               {
    ctx.unique("boot-file-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3563 "dhcp4_parser.cc"
    break;

  case 639: // boot_file_name: "boot-file-name" $@93 ":" "constant string"
#line 2231 "dhcp4_parser.yy"
               {
    ElementPtr bootfile(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("boot-file-name", bootfile);
    ctx.leave();
}
#line 3573 "dhcp4_parser.cc"
    break;

  case 640: // $@94: %empty
#line 2237 "dhcp4_parser.yy"
                       {
    ctx.unique("ip-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3582 "dhcp4_parser.cc"
    break;

  case 641: // ip_address: "ip-address" $@94 ":" "constant string"
#line 2240 "dhcp4_parser.yy"
               {
    ElementPtr addr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-address", addr);
    ctx.leave();
}
#line 3592 "dhcp4_parser.cc"
    break;

  case 642: // $@95: %empty
#line 2246 "dhcp4_parser.yy"
                           {
    ctx.unique("ip-addresses", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-addresses", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3604 "dhcp4_parser.cc"
    break;

  case 643: // ip_addresses: "ip-addresses" $@95 ":" list_strings
#line 2252 "dhcp4_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3613 "dhcp4_parser.cc"
    break;

  case 644: // $@96: %empty
#line 2257 "dhcp4_parser.yy"
           {
    ctx.unique("duid", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3622 "dhcp4_parser.cc"
    break;

  case 645: // duid: "duid" $@96 ":" "constant string"
#line 2260 "dhcp4_parser.yy"
               {
    ElementPtr d(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("duid", d);
    ctx.leave();
}
#line 3632 "dhcp4_parser.cc"
    break;

  case 646: // $@97: %empty
#line 2266 "dhcp4_parser.yy"
                       {
    ctx.unique("hw-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3641 "dhcp4_parser.cc"
    break;

  case 647: // hw_address: "hw-address" $@97 ":" "constant string"
#line 2269 "dhcp4_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hw-address", hw);
    ctx.leave();
}
#line 3651 "dhcp4_parser.cc"
    break;

  case 648: // $@98: %empty
#line 2275 "dhcp4_parser.yy"
                           {
    ctx.unique("client-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3660 "dhcp4_parser.cc"
    break;

  case 649: // client_id_value: "client-id" $@98 ":" "constant string"
#line 2278 "dhcp4_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-id", hw);
    ctx.leave();
}
#line 3670 "dhcp4_parser.cc"
    break;

  case 650: // $@99: %empty
#line 2284 "dhcp4_parser.yy"
                             {
    ctx.unique("circuit-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3679 "dhcp4_parser.cc"
    break;

  case 651: // circuit_id_value: "circuit-id" $@99 ":" "constant string"
#line 2287 "dhcp4_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("circuit-id", hw);
    ctx.leave();
}
#line 3689 "dhcp4_parser.cc"
    break;

  case 652: // $@100: %empty
#line 2293 "dhcp4_parser.yy"
                       {
    ctx.unique("flex-id", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3698 "dhcp4_parser.cc"
    break;

  case 653: // flex_id_value: "flex-id" $@100 ":" "constant string"
#line 2296 "dhcp4_parser.yy"
               {
    ElementPtr hw(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flex-id", hw);
    ctx.leave();
}
#line 3708 "dhcp4_parser.cc"
    break;

  case 654: // $@101: %empty
#line 2302 "dhcp4_parser.yy"
                   {
    ctx.unique("hostname", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3717 "dhcp4_parser.cc"
    break;

  case 655: // hostname: "hostname" $@101 ":" "constant string"
#line 2305 "dhcp4_parser.yy"
               {
    ElementPtr host(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname", host);
    ctx.leave();
}
#line 3727 "dhcp4_parser.cc"
    break;

  case 656: // $@102: %empty
#line 2311 "dhcp4_parser.yy"
                                           {
    ctx.unique("client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr c(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-classes", c);
    ctx.stack_.push_back(c);
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3739 "dhcp4_parser.cc"
    break;

  case 657: // reservation_client_classes: "client-classes" $@102 ":" list_strings
#line 2317 "dhcp4_parser.yy"
                     {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3748 "dhcp4_parser.cc"
    break;

  case 658: // $@103: %empty
#line 2325 "dhcp4_parser.yy"
             {
    ctx.unique("relay", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("relay", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.RELAY);
}
#line 3760 "dhcp4_parser.cc"
    break;

  case 659: // relay: "relay" $@103 ":" "{" relay_map "}"
#line 2331 "dhcp4_parser.yy"
                                                {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3769 "dhcp4_parser.cc"
    break;

  case 662: // $@104: %empty
#line 2343 "dhcp4_parser.yy"
                               {
    ctx.unique("client-classes", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("client-classes", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.CLIENT_CLASSES);
}
#line 3781 "dhcp4_parser.cc"
    break;

  case 663: // client_classes: "client-classes" $@104 ":" "[" client_classes_list "]"
#line 2349 "dhcp4_parser.yy"
                                                            {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3790 "dhcp4_parser.cc"
    break;

  case 666: // client_classes_list: client_classes_list ","
#line 2356 "dhcp4_parser.yy"
                                               {
                       ctx.warnAboutExtraCommas(yystack_[0].location);
                       }
#line 3798 "dhcp4_parser.cc"
    break;

  case 667: // $@105: %empty
#line 2361 "dhcp4_parser.yy"
                                   {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 3808 "dhcp4_parser.cc"
    break;

  case 668: // client_class_entry: "{" $@105 client_class_params "}"
#line 2365 "dhcp4_parser.yy"
                                     {
    // The name client class parameter is required.
    ctx.require("name", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 3818 "dhcp4_parser.cc"
    break;

  case 673: // not_empty_client_class_params: not_empty_client_class_params ","
#line 2377 "dhcp4_parser.yy"
                                          {
        ctx.warnAboutExtraCommas(yystack_[0].location);
        }
#line 3826 "dhcp4_parser.cc"
    break;

  case 690: // $@106: %empty
#line 2401 "dhcp4_parser.yy"
                        {
    ctx.unique("test", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3835 "dhcp4_parser.cc"
    break;

  case 691: // client_class_test: "test" $@106 ":" "constant string"
#line 2404 "dhcp4_parser.yy"
               {
    ElementPtr test(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("test", test);
    ctx.leave();
}
#line 3845 "dhcp4_parser.cc"
    break;

  case 692: // $@107: %empty
#line 2410 "dhcp4_parser.yy"
                                          {
    ctx.unique("template-test", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3854 "dhcp4_parser.cc"
    break;

  case 693: // client_class_template_test: "template-test" $@107 ":" "constant string"
#line 2413 "dhcp4_parser.yy"
               {
    ElementPtr template_test(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("template-test", template_test);
    ctx.leave();
}
#line 3864 "dhcp4_parser.cc"
    break;

  case 694: // only_if_required: "only-if-required" ":" "boolean"
#line 2419 "dhcp4_parser.yy"
                                                 {
    ctx.unique("only-if-required", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("only-if-required", b);
}
#line 3874 "dhcp4_parser.cc"
    break;

  case 695: // dhcp4o6_port: "dhcp4o6-port" ":" "integer"
#line 2427 "dhcp4_parser.yy"
                                         {
    ctx.unique("dhcp4o6-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr time(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp4o6-port", time);
}
#line 3884 "dhcp4_parser.cc"
    break;

  case 696: // $@108: %empty
#line 2435 "dhcp4_parser.yy"
                               {
    ctx.unique("control-socket", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("control-socket", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.CONTROL_SOCKET);
}
#line 3896 "dhcp4_parser.cc"
    break;

  case 697: // control_socket: "control-socket" $@108 ":" "{" control_socket_params "}"
#line 2441 "dhcp4_parser.yy"
                                                            {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3905 "dhcp4_parser.cc"
    break;

  case 700: // control_socket_params: control_socket_params ","
#line 2448 "dhcp4_parser.yy"
                                                   {
                          ctx.warnAboutExtraCommas(yystack_[0].location);
                          }
#line 3913 "dhcp4_parser.cc"
    break;

  case 706: // $@109: %empty
#line 2460 "dhcp4_parser.yy"
                                 {
    ctx.unique("socket-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3922 "dhcp4_parser.cc"
    break;

  case 707: // control_socket_type: "socket-type" $@109 ":" "constant string"
#line 2463 "dhcp4_parser.yy"
               {
    ElementPtr stype(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-type", stype);
    ctx.leave();
}
#line 3932 "dhcp4_parser.cc"
    break;

  case 708: // $@110: %empty
#line 2469 "dhcp4_parser.yy"
                                 {
    ctx.unique("socket-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 3941 "dhcp4_parser.cc"
    break;

  case 709: // control_socket_name: "socket-name" $@110 ":" "constant string"
#line 2472 "dhcp4_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-name", name);
    ctx.leave();
}
#line 3951 "dhcp4_parser.cc"
    break;

  case 710: // $@111: %empty
#line 2481 "dhcp4_parser.yy"
                                       {
    ctx.unique("dhcp-queue-control", ctx.loc2pos(yystack_[0].location));
    ElementPtr qc(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp-queue-control", qc);
    ctx.stack_.push_back(qc);
    ctx.enter(ctx.DHCP_QUEUE_CONTROL);
}
#line 3963 "dhcp4_parser.cc"
    break;

  case 711: // dhcp_queue_control: "dhcp-queue-control" $@111 ":" "{" queue_control_params "}"
#line 2487 "dhcp4_parser.yy"
                                                           {
    // The enable queue parameter is required.
    ctx.require("enable-queue", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 3974 "dhcp4_parser.cc"
    break;

  case 714: // queue_control_params: queue_control_params ","
#line 2496 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 3982 "dhcp4_parser.cc"
    break;

  case 721: // enable_queue: "enable-queue" ":" "boolean"
#line 2509 "dhcp4_parser.yy"
                                         {
    ctx.unique("enable-queue", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-queue", b);
}
#line 3992 "dhcp4_parser.cc"
    break;

  case 722: // $@112: %empty
#line 2515 "dhcp4_parser.yy"
                       {
    ctx.unique("queue-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4001 "dhcp4_parser.cc"
    break;

  case 723: // queue_type: "queue-type" $@112 ":" "constant string"
#line 2518 "dhcp4_parser.yy"
               {
    ElementPtr qt(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("queue-type", qt);
    ctx.leave();
}
#line 4011 "dhcp4_parser.cc"
    break;

  case 724: // capacity: "capacity" ":" "integer"
#line 2524 "dhcp4_parser.yy"
                                 {
    ctx.unique("capacity", ctx.loc2pos(yystack_[2].location));
    ElementPtr c(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("capacity", c);
}
#line 4021 "dhcp4_parser.cc"
    break;

  case 725: // $@113: %empty
#line 2530 "dhcp4_parser.yy"
                            {
    ctx.unique(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4030 "dhcp4_parser.cc"
    break;

  case 726: // arbitrary_map_entry: "constant string" $@113 ":" value
#line 2533 "dhcp4_parser.yy"
              {
    ctx.stack_.back()->set(yystack_[3].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4039 "dhcp4_parser.cc"
    break;

  case 727: // $@114: %empty
#line 2540 "dhcp4_parser.yy"
                     {
    ctx.unique("dhcp-ddns", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dhcp-ddns", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.DHCP_DDNS);
}
#line 4051 "dhcp4_parser.cc"
    break;

  case 728: // dhcp_ddns: "dhcp-ddns" $@114 ":" "{" dhcp_ddns_params "}"
#line 2546 "dhcp4_parser.yy"
                                                       {
    // The enable updates DHCP DDNS parameter is required.
    ctx.require("enable-updates", ctx.loc2pos(yystack_[2].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4062 "dhcp4_parser.cc"
    break;

  case 729: // $@115: %empty
#line 2553 "dhcp4_parser.yy"
                              {
    // Parse the dhcp-ddns map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 4072 "dhcp4_parser.cc"
    break;

  case 730: // sub_dhcp_ddns: "{" $@115 dhcp_ddns_params "}"
#line 2557 "dhcp4_parser.yy"
                                  {
    // The enable updates DHCP DDNS parameter is required.
    ctx.require("enable-updates", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 4082 "dhcp4_parser.cc"
    break;

  case 733: // dhcp_ddns_params: dhcp_ddns_params ","
#line 2565 "dhcp4_parser.yy"
                                         {
                    ctx.warnAboutExtraCommas(yystack_[0].location);
                    }
#line 4090 "dhcp4_parser.cc"
    break;

  case 752: // enable_updates: "enable-updates" ":" "boolean"
#line 2590 "dhcp4_parser.yy"
                                             {
    ctx.unique("enable-updates", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("enable-updates", b);
}
#line 4100 "dhcp4_parser.cc"
    break;

  case 753: // $@116: %empty
#line 2596 "dhcp4_parser.yy"
                     {
    ctx.unique("server-ip", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4109 "dhcp4_parser.cc"
    break;

  case 754: // server_ip: "server-ip" $@116 ":" "constant string"
#line 2599 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-ip", s);
    ctx.leave();
}
#line 4119 "dhcp4_parser.cc"
    break;

  case 755: // server_port: "server-port" ":" "integer"
#line 2605 "dhcp4_parser.yy"
                                       {
    ctx.unique("server-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("server-port", i);
}
#line 4129 "dhcp4_parser.cc"
    break;

  case 756: // $@117: %empty
#line 2611 "dhcp4_parser.yy"
                     {
    ctx.unique("sender-ip", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4138 "dhcp4_parser.cc"
    break;

  case 757: // sender_ip: "sender-ip" $@117 ":" "constant string"
#line 2614 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sender-ip", s);
    ctx.leave();
}
#line 4148 "dhcp4_parser.cc"
    break;

  case 758: // sender_port: "sender-port" ":" "integer"
#line 2620 "dhcp4_parser.yy"
                                       {
    ctx.unique("sender-port", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("sender-port", i);
}
#line 4158 "dhcp4_parser.cc"
    break;

  case 759: // max_queue_size: "max-queue-size" ":" "integer"
#line 2626 "dhcp4_parser.yy"
                                             {
    ctx.unique("max-queue-size", ctx.loc2pos(yystack_[2].location));
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("max-queue-size", i);
}
#line 4168 "dhcp4_parser.cc"
    break;

  case 760: // $@118: %empty
#line 2632 "dhcp4_parser.yy"
                           {
    ctx.unique("ncr-protocol", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_PROTOCOL);
}
#line 4177 "dhcp4_parser.cc"
    break;

  case 761: // ncr_protocol: "ncr-protocol" $@118 ":" ncr_protocol_value
#line 2635 "dhcp4_parser.yy"
                           {
    ctx.stack_.back()->set("ncr-protocol", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4186 "dhcp4_parser.cc"
    break;

  case 762: // ncr_protocol_value: "udp"
#line 2641 "dhcp4_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("UDP", ctx.loc2pos(yystack_[0].location))); }
#line 4192 "dhcp4_parser.cc"
    break;

  case 763: // ncr_protocol_value: "tcp"
#line 2642 "dhcp4_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("TCP", ctx.loc2pos(yystack_[0].location))); }
#line 4198 "dhcp4_parser.cc"
    break;

  case 764: // $@119: %empty
#line 2645 "dhcp4_parser.yy"
                       {
    ctx.unique("ncr-format", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_FORMAT);
}
#line 4207 "dhcp4_parser.cc"
    break;

  case 765: // ncr_format: "ncr-format" $@119 ":" "JSON"
#line 2648 "dhcp4_parser.yy"
             {
    ElementPtr json(new StringElement("JSON", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ncr-format", json);
    ctx.leave();
}
#line 4217 "dhcp4_parser.cc"
    break;

  case 766: // $@120: %empty
#line 2655 "dhcp4_parser.yy"
                                         {
    ctx.unique("qualifying-suffix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4226 "dhcp4_parser.cc"
    break;

  case 767: // dep_qualifying_suffix: "qualifying-suffix" $@120 ":" "constant string"
#line 2658 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("qualifying-suffix", s);
    ctx.leave();
}
#line 4236 "dhcp4_parser.cc"
    break;

  case 768: // dep_override_no_update: "override-no-update" ":" "boolean"
#line 2665 "dhcp4_parser.yy"
                                                         {
    ctx.unique("override-no-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("override-no-update", b);
}
#line 4246 "dhcp4_parser.cc"
    break;

  case 769: // dep_override_client_update: "override-client-update" ":" "boolean"
#line 2672 "dhcp4_parser.yy"
                                                                 {
    ctx.unique("override-client-update", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("override-client-update", b);
}
#line 4256 "dhcp4_parser.cc"
    break;

  case 770: // $@121: %empty
#line 2679 "dhcp4_parser.yy"
                                             {
    ctx.unique("replace-client-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.REPLACE_CLIENT_NAME);
}
#line 4265 "dhcp4_parser.cc"
    break;

  case 771: // dep_replace_client_name: "replace-client-name" $@121 ":" ddns_replace_client_name_value
#line 2682 "dhcp4_parser.yy"
                                       {
    ctx.stack_.back()->set("replace-client-name", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 4274 "dhcp4_parser.cc"
    break;

  case 772: // $@122: %empty
#line 2688 "dhcp4_parser.yy"
                                       {
    ctx.unique("generated-prefix", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4283 "dhcp4_parser.cc"
    break;

  case 773: // dep_generated_prefix: "generated-prefix" $@122 ":" "constant string"
#line 2691 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("generated-prefix", s);
    ctx.leave();
}
#line 4293 "dhcp4_parser.cc"
    break;

  case 774: // $@123: %empty
#line 2698 "dhcp4_parser.yy"
                                         {
    ctx.unique("hostname-char-set", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4302 "dhcp4_parser.cc"
    break;

  case 775: // dep_hostname_char_set: "hostname-char-set" $@123 ":" "constant string"
#line 2701 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-set", s);
    ctx.leave();
}
#line 4312 "dhcp4_parser.cc"
    break;

  case 776: // $@124: %empty
#line 2708 "dhcp4_parser.yy"
                                                         {
    ctx.unique("hostname-char-replacement", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4321 "dhcp4_parser.cc"
    break;

  case 777: // dep_hostname_char_replacement: "hostname-char-replacement" $@124 ":" "constant string"
#line 2711 "dhcp4_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname-char-replacement", s);
    ctx.leave();
}
#line 4331 "dhcp4_parser.cc"
    break;

  case 778: // $@125: %empty
#line 2720 "dhcp4_parser.yy"
                               {
    ctx.unique("config-control", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-control", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.CONFIG_CONTROL);
}
#line 4343 "dhcp4_parser.cc"
    break;

  case 779: // config_control: "config-control" $@125 ":" "{" config_control_params "}"
#line 2726 "dhcp4_parser.yy"
                                                            {
    // No config control params are required
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4353 "dhcp4_parser.cc"
    break;

  case 780: // $@126: %empty
#line 2732 "dhcp4_parser.yy"
                                   {
    // Parse the config-control map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 4363 "dhcp4_parser.cc"
    break;

  case 781: // sub_config_control: "{" $@126 config_control_params "}"
#line 2736 "dhcp4_parser.yy"
                                       {
    // No config_control params are required
    // parsing completed
}
#line 4372 "dhcp4_parser.cc"
    break;

  case 784: // config_control_params: config_control_params ","
#line 2744 "dhcp4_parser.yy"
                                                   {
                         ctx.warnAboutExtraCommas(yystack_[0].location);
                         }
#line 4380 "dhcp4_parser.cc"
    break;

  case 787: // $@127: %empty
#line 2754 "dhcp4_parser.yy"
                                   {
    ctx.unique("config-databases", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-databases", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.CONFIG_DATABASE);
}
#line 4392 "dhcp4_parser.cc"
    break;

  case 788: // config_databases: "config-databases" $@127 ":" "[" database_list "]"
#line 2760 "dhcp4_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4401 "dhcp4_parser.cc"
    break;

  case 789: // config_fetch_wait_time: "config-fetch-wait-time" ":" "integer"
#line 2765 "dhcp4_parser.yy"
                                                             {
    ctx.unique("config-fetch-wait-time", ctx.loc2pos(yystack_[2].location));
    ElementPtr value(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("config-fetch-wait-time", value);
}
#line 4411 "dhcp4_parser.cc"
    break;

  case 790: // $@128: %empty
#line 2773 "dhcp4_parser.yy"
                 {
    ctx.unique("loggers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("loggers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.LOGGERS);
}
#line 4423 "dhcp4_parser.cc"
    break;

  case 791: // loggers: "loggers" $@128 ":" "[" loggers_entries "]"
#line 2779 "dhcp4_parser.yy"
                                                         {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4432 "dhcp4_parser.cc"
    break;

  case 794: // loggers_entries: loggers_entries ","
#line 2788 "dhcp4_parser.yy"
                                       {
                   ctx.warnAboutExtraCommas(yystack_[0].location);
                   }
#line 4440 "dhcp4_parser.cc"
    break;

  case 795: // $@129: %empty
#line 2794 "dhcp4_parser.yy"
                             {
    ElementPtr l(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(l);
    ctx.stack_.push_back(l);
}
#line 4450 "dhcp4_parser.cc"
    break;

  case 796: // logger_entry: "{" $@129 logger_params "}"
#line 2798 "dhcp4_parser.yy"
                               {
    ctx.stack_.pop_back();
}
#line 4458 "dhcp4_parser.cc"
    break;

  case 799: // logger_params: logger_params ","
#line 2804 "dhcp4_parser.yy"
                                   {
                 ctx.warnAboutExtraCommas(yystack_[0].location);
                 }
#line 4466 "dhcp4_parser.cc"
    break;

  case 807: // debuglevel: "debuglevel" ":" "integer"
#line 2818 "dhcp4_parser.yy"
                                     {
    ctx.unique("debuglevel", ctx.loc2pos(yystack_[2].location));
    ElementPtr dl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("debuglevel", dl);
}
#line 4476 "dhcp4_parser.cc"
    break;

  case 808: // $@130: %empty
#line 2824 "dhcp4_parser.yy"
                   {
    ctx.unique("severity", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4485 "dhcp4_parser.cc"
    break;

  case 809: // severity: "severity" $@130 ":" "constant string"
#line 2827 "dhcp4_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("severity", sev);
    ctx.leave();
}
#line 4495 "dhcp4_parser.cc"
    break;

  case 810: // $@131: %empty
#line 2833 "dhcp4_parser.yy"
                                    {
    ctx.unique("output_options", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output_options", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OUTPUT_OPTIONS);
}
#line 4507 "dhcp4_parser.cc"
    break;

  case 811: // output_options_list: "output_options" $@131 ":" "[" output_options_list_content "]"
#line 2839 "dhcp4_parser.yy"
                                                                    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4516 "dhcp4_parser.cc"
    break;

  case 814: // output_options_list_content: output_options_list_content ","
#line 2846 "dhcp4_parser.yy"
                                                               {
                               ctx.warnAboutExtraCommas(yystack_[0].location);
                               }
#line 4524 "dhcp4_parser.cc"
    break;

  case 815: // $@132: %empty
#line 2851 "dhcp4_parser.yy"
                             {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 4534 "dhcp4_parser.cc"
    break;

  case 816: // output_entry: "{" $@132 output_params_list "}"
#line 2855 "dhcp4_parser.yy"
                                    {
    ctx.stack_.pop_back();
}
#line 4542 "dhcp4_parser.cc"
    break;

  case 819: // output_params_list: output_params_list ","
#line 2861 "dhcp4_parser.yy"
                                             {
                      ctx.warnAboutExtraCommas(yystack_[0].location);
                      }
#line 4550 "dhcp4_parser.cc"
    break;

  case 825: // $@133: %empty
#line 2873 "dhcp4_parser.yy"
               {
    ctx.unique("output", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4559 "dhcp4_parser.cc"
    break;

  case 826: // output: "output" $@133 ":" "constant string"
#line 2876 "dhcp4_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output", sev);
    ctx.leave();
}
#line 4569 "dhcp4_parser.cc"
    break;

  case 827: // flush: "flush" ":" "boolean"
#line 2882 "dhcp4_parser.yy"
                           {
    ctx.unique("flush", ctx.loc2pos(yystack_[2].location));
    ElementPtr flush(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush", flush);
}
#line 4579 "dhcp4_parser.cc"
    break;

  case 828: // maxsize: "maxsize" ":" "integer"
#line 2888 "dhcp4_parser.yy"
                               {
    ctx.unique("maxsize", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxsize(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxsize", maxsize);
}
#line 4589 "dhcp4_parser.cc"
    break;

  case 829: // maxver: "maxver" ":" "integer"
#line 2894 "dhcp4_parser.yy"
                             {
    ctx.unique("maxver", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxver(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxver", maxver);
}
#line 4599 "dhcp4_parser.cc"
    break;

  case 830: // $@134: %empty
#line 2900 "dhcp4_parser.yy"
                 {
    ctx.unique("pattern", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 4608 "dhcp4_parser.cc"
    break;

  case 831: // pattern: "pattern" $@134 ":" "constant string"
#line 2903 "dhcp4_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pattern", sev);
    ctx.leave();
}
#line 4618 "dhcp4_parser.cc"
    break;

  case 832: // $@135: %empty
#line 2909 "dhcp4_parser.yy"
                             {
    ctx.unique("compatibility", ctx.loc2pos(yystack_[0].location));
    ElementPtr i(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("compatibility", i);
    ctx.stack_.push_back(i);
    ctx.enter(ctx.COMPATIBILITY);
}
#line 4630 "dhcp4_parser.cc"
    break;

  case 833: // compatibility: "compatibility" $@135 ":" "{" compatibility_params "}"
#line 2915 "dhcp4_parser.yy"
                                                           {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 4639 "dhcp4_parser.cc"
    break;

  case 836: // compatibility_params: compatibility_params ","
#line 2922 "dhcp4_parser.yy"
                                                 {
                        ctx.warnAboutExtraCommas(yystack_[0].location);
                        }
#line 4647 "dhcp4_parser.cc"
    break;

  case 840: // lenient_option_parsing: "lenient-option-parsing" ":" "boolean"
#line 2932 "dhcp4_parser.yy"
                                                             {
    ctx.unique("lenient-option-parsing", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("lenient-option-parsing", b);
}
#line 4657 "dhcp4_parser.cc"
    break;

  case 841: // ignore-rai-link-selection: "ignore-rai-link-selection" ":" "boolean"
#line 2938 "dhcp4_parser.yy"
                                                             {
    ctx.unique("ignore-rai-link-selection", ctx.loc2pos(yystack_[2].location));
    ElementPtr b(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ignore-rai-link-selection", b);
}
#line 4667 "dhcp4_parser.cc"
    break;


#line 4671 "dhcp4_parser.cc"

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


  const short Dhcp4Parser::yypact_ninf_ = -993;

  const signed char Dhcp4Parser::yytable_ninf_ = -1;

  const short
  Dhcp4Parser::yypact_[] =
  {
     622,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,    35,    44,    47,    62,    65,   127,
     134,   136,   140,   153,   205,   238,   240,   272,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,    44,  -165,    70,   122,   150,   314,
      54,   233,    23,   550,   -34,   -46,   561,    79,  -993,   114,
     280,    46,   309,   330,  -993,    24,  -993,  -993,  -993,  -993,
     336,   339,   345,  -993,  -993,  -993,  -993,  -993,  -993,   346,
     347,   348,   350,   352,   353,   354,   355,   357,   364,   366,
    -993,   367,   368,   369,   372,   373,  -993,  -993,  -993,   384,
     385,   386,  -993,  -993,  -993,   387,  -993,   397,  -993,  -993,
    -993,  -993,   401,   403,   404,  -993,  -993,  -993,  -993,  -993,
     405,  -993,  -993,  -993,  -993,  -993,  -993,   406,   407,   408,
    -993,  -993,   409,  -993,    49,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,   410,   411,   412,   414,  -993,    87,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,   415,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,    97,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,   105,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
     413,   425,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,   421,  -993,  -993,   426,  -993,  -993,
    -993,   431,  -993,  -993,   428,   435,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   440,
     441,  -993,  -993,  -993,  -993,   438,   436,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   107,
    -993,  -993,  -993,   443,  -993,  -993,   444,  -993,   446,   447,
    -993,  -993,   449,   450,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,   113,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   452,
     120,  -993,  -993,  -993,  -993,    44,    44,  -993,   248,   455,
    -993,  -993,   456,   457,   459,   252,   255,   256,   466,   468,
     469,   471,   475,   478,   275,   276,   286,   291,   294,   270,
     278,   288,   297,   300,   301,   480,   302,   304,   308,   318,
     319,   487,   510,   513,   320,   321,   322,   514,   518,   521,
     325,   525,   324,   538,   539,   540,   543,   335,   337,   338,
     548,   549,   551,   554,   556,   343,   559,   560,   562,   564,
     566,   567,   360,   363,   365,   577,   580,  -993,   122,  -993,
     582,   585,   589,   381,   388,   389,   391,   150,  -993,   594,
     595,   599,   600,   601,   602,   396,   604,   606,   607,   314,
    -993,   608,    54,  -993,   631,   632,   633,   634,   635,   636,
     637,   643,  -993,   233,  -993,   644,   648,   442,   656,   657,
     658,   454,  -993,   550,   659,   460,   461,  -993,   -34,   661,
     664,   182,  -993,   462,   672,   673,   467,   677,   472,   473,
     681,   686,   479,   481,   687,   689,   691,   692,   561,  -993,
     693,   488,    79,  -993,  -993,  -993,   694,   698,   699,   700,
     702,  -993,  -993,  -993,   490,   500,   501,   705,   711,   714,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,   511,  -993,  -993,  -993,  -993,  -993,   -95,   526,   527,
    -993,  -993,  -993,   715,   730,   733,  -993,   529,  -993,   735,
     750,   568,   212,  -993,  -993,  -993,   753,   754,   767,   769,
     770,  -993,   772,   773,   775,   776,   574,   575,  -993,  -993,
    -993,   782,   781,  -993,   784,   219,   241,  -993,  -993,  -993,
    -993,  -993,   583,   587,   588,   785,   590,   597,  -993,   784,
     598,   788,  -993,   603,  -993,   784,   605,   623,   624,   625,
     626,   627,   628,  -993,   629,   630,  -993,   638,   639,   640,
    -993,  -993,   641,  -993,  -993,  -993,   642,   750,  -993,  -993,
     645,   646,  -993,   647,  -993,  -993,     4,   666,  -993,  -993,
     -95,   649,   650,   651,  -993,   794,  -993,  -993,    44,   122,
      79,   150,   303,  -993,  -993,  -993,   571,   571,   797,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   798,   802,
     804,  -993,   805,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,   157,   807,   809,   810,    76,   143,    74,   -72,   561,
    -993,  -993,   825,  -155,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,   835,  -993,  -993,  -993,  -993,
     202,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   797,
    -993,   123,   141,   142,  -993,  -993,   176,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,   839,   840,   841,   842,   843,   849,
     850,   854,   858,   861,  -993,   862,  -993,  -993,  -993,  -993,
    -993,   177,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,   207,  -993,   863,   864,  -993,  -993,
     865,   867,  -993,  -993,   866,   870,  -993,  -993,   868,   872,
    -993,  -993,   871,   873,  -993,  -993,  -993,  -993,  -993,  -993,
     164,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   165,  -993,
    -993,   874,   875,  -993,  -993,   876,   878,  -993,   879,   880,
     881,   882,   883,   884,   208,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,   885,   886,   887,  -993,   245,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   265,  -993,
    -993,  -993,   888,  -993,   890,  -993,  -993,  -993,   266,  -993,
    -993,  -993,  -993,  -993,   269,  -993,   243,  -993,   891,   892,
    -993,   273,  -993,  -993,  -993,   669,  -993,   893,   894,  -993,
    -993,  -993,  -993,   860,   895,  -993,  -993,  -993,   896,   898,
     303,  -993,   899,   900,   901,   902,   696,   685,   697,   701,
     704,   706,   707,   708,   709,   710,   905,   712,   906,   907,
     908,   909,   571,  -993,  -993,   571,  -993,   797,   314,  -993,
     798,   550,  -993,   802,   -34,  -993,   804,   683,  -993,   805,
     157,  -993,   563,   807,  -993,   233,  -993,   809,   -46,  -993,
     810,   713,   716,   717,   718,   719,   721,    76,  -993,   703,
     722,   724,   143,  -993,   918,   921,    74,  -993,   723,   922,
     728,   943,   -72,  -993,  -993,   124,   825,  -993,   741,   748,
    -155,  -993,  -993,   960,   970,    54,  -993,   835,   972,  -993,
    -993,   764,   783,  -993,   259,   786,   793,   801,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   279,  -993,
     803,   812,   814,   820,  -993,   277,  -993,   289,  -993,   971,
    -993,  1000,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,   293,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    1015,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  1035,  1069,  -993,  -993,  -993,  -993,  -993,
    -993,  1066,  -993,   306,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,   869,   877,  -993,  -993,
     889,  -993,    44,  -993,  -993,  1073,  -993,  -993,  -993,  -993,
    -993,   312,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,   897,   315,  -993,   784,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,   683,  -993,  1077,  1078,
     903,  -993,   563,  -993,  -993,  -993,  -993,  -993,  -993,  1079,
     904,  1080,   124,  -993,  -993,  -993,  -993,  -993,   910,   911,
    -993,  -993,  1081,  -993,   912,  -993,  -993,  -993,  1082,  -993,
    -993,   305,  -993,   -89,  1082,  -993,  -993,  1084,  1086,  1087,
    -993,   316,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  1088,
     913,   914,   916,  1089,   -89,  -993,   919,  -993,  -993,  -993,
     920,  -993,  -993,  -993
  };

  const short
  Dhcp4Parser::yydefact_[] =
  {
       0,     2,     4,     6,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,    44,
      36,    32,    31,    28,    29,    30,    35,     3,    33,    34,
      59,     5,    65,     7,   197,     9,   375,    11,   585,    13,
     612,    15,   505,    17,   514,    19,   553,    21,   337,    23,
     729,    25,   780,    27,    46,    39,     0,     0,     0,     0,
       0,   614,     0,   516,   555,     0,     0,     0,    48,     0,
      47,     0,     0,    40,    61,     0,    63,   778,   182,   215,
       0,     0,     0,   634,   636,   638,   213,   226,   228,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,     0,     0,     0,     0,     0,   159,   166,   168,     0,
       0,     0,   366,   503,   544,     0,   150,     0,   450,   599,
     601,   443,     0,     0,     0,   299,   662,   603,   328,   349,
       0,   314,   696,   710,   727,   172,   174,     0,     0,     0,
     790,   832,     0,   135,     0,    67,    70,    71,    72,    73,
      74,   108,   109,   110,   111,   112,    75,   103,   132,   133,
     134,    92,    93,    94,   116,   117,   118,   119,   120,   121,
     122,   123,   114,   115,   124,   125,   126,   128,   129,   130,
      78,    79,   100,    80,    81,    82,   127,    86,    87,    76,
     105,   106,   107,   104,    77,    84,    85,    98,    99,   101,
      95,    96,    97,    83,    88,    89,    90,    91,   102,   113,
     131,   199,   201,   205,     0,     0,     0,     0,   196,     0,
     184,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     428,   430,   432,   576,   426,   434,     0,   438,   436,   658,
     425,   380,   381,   382,   383,   384,   408,   409,   410,   411,
     412,   424,   398,   399,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,     0,   377,   387,   403,   404,
     405,   388,   390,   391,   394,   395,   396,   393,   389,   385,
     386,   406,   407,   392,   400,   401,   402,   397,   597,   596,
     592,   593,   591,     0,   587,   590,   594,   595,   656,   644,
     646,   650,   648,   654,   652,   640,   633,   627,   631,   632,
       0,   615,   616,   628,   629,   630,   624,   619,   625,   621,
     622,   623,   626,   620,     0,   534,   274,     0,   538,   536,
     541,     0,   530,   531,     0,   517,   518,   521,   533,   522,
     523,   524,   540,   525,   526,   527,   528,   529,   570,     0,
       0,   568,   569,   572,   573,     0,   556,   557,   560,   561,
     562,   563,   564,   565,   566,   567,   345,   347,   342,     0,
     339,   343,   344,     0,   766,   753,     0,   756,     0,     0,
     760,   764,     0,     0,   770,   772,   774,   776,   751,   749,
     750,     0,   731,   734,   735,   736,   737,   738,   739,   740,
     741,   746,   742,   743,   744,   745,   747,   748,   787,     0,
       0,   782,   785,   786,    45,    50,     0,    37,    43,     0,
      64,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    69,    66,
       0,     0,     0,     0,     0,     0,     0,   186,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   379,
     376,     0,   589,   586,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   618,   506,     0,     0,     0,     0,     0,
       0,     0,   515,   520,     0,     0,     0,   554,   559,     0,
       0,   341,   338,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   733,   730,
       0,     0,   784,   781,    49,    41,     0,     0,     0,     0,
       0,   153,   154,   155,     0,     0,     0,     0,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,   177,   178,   156,   157,   158,     0,     0,     0,
     170,   171,   176,     0,     0,     0,   149,     0,   152,     0,
       0,     0,     0,   440,   441,   442,     0,     0,     0,     0,
       0,   695,     0,     0,     0,     0,     0,     0,   179,   180,
     181,     0,     0,    68,     0,     0,     0,   209,   210,   211,
     212,   185,     0,     0,     0,     0,     0,     0,   449,     0,
       0,     0,   378,     0,   588,     0,     0,     0,     0,     0,
       0,     0,     0,   617,     0,     0,   532,     0,     0,     0,
     543,   519,     0,   574,   575,   558,     0,     0,   340,   752,
       0,     0,   755,     0,   758,   759,     0,     0,   768,   769,
       0,     0,     0,     0,   732,     0,   789,   783,     0,     0,
       0,     0,     0,   635,   637,   639,     0,     0,   230,   148,
     161,   162,   163,   164,   165,   160,   167,   169,   368,   507,
     546,   151,   452,    38,   600,   602,   445,   446,   447,   448,
     444,     0,     0,   605,   330,     0,     0,     0,     0,     0,
     173,   175,     0,     0,    51,   200,   203,   204,   202,   207,
     208,   206,   429,   431,   433,   578,   427,   435,   439,   437,
       0,   598,   657,   645,   647,   651,   649,   655,   653,   641,
     535,   275,   539,   537,   542,   571,   346,   348,   767,   754,
     757,   762,   763,   761,   765,   771,   773,   775,   777,   230,
      42,     0,     0,     0,   222,   224,     0,   217,   220,   221,
     262,   267,   269,   271,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,     0,   291,   293,   295,   297,
     261,     0,   237,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,     0,   235,     0,   231,   232,   373,
       0,   369,   370,   512,     0,   508,   509,   551,     0,   547,
     548,   457,     0,   453,   454,   309,   310,   311,   312,   313,
       0,   301,   304,   305,   306,   307,   308,   667,     0,   664,
     610,     0,   606,   607,   335,     0,   331,   332,     0,     0,
       0,     0,     0,     0,     0,   351,   354,   355,   356,   357,
     358,   359,     0,     0,     0,   324,     0,   316,   319,   320,
     321,   322,   323,   706,   708,   705,   703,   704,     0,   698,
     701,   702,     0,   722,     0,   725,   718,   719,     0,   712,
     715,   716,   717,   720,     0,   795,     0,   792,     0,     0,
     839,     0,   834,   837,   838,    53,   583,     0,   579,   580,
     642,   660,   661,     0,     0,    62,   779,   183,     0,     0,
     219,   216,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   214,   227,     0,   229,   234,     0,   367,
     372,   516,   504,   511,   555,   545,   550,     0,   451,   456,
     303,   300,   669,   666,   663,   614,   604,   609,     0,   329,
     334,     0,     0,     0,     0,     0,     0,   353,   350,     0,
       0,     0,   318,   315,     0,     0,   700,   697,     0,     0,
       0,     0,   714,   711,   728,     0,   794,   791,     0,     0,
     836,   833,    55,     0,    54,     0,   577,   582,     0,   659,
     788,     0,     0,   218,     0,     0,     0,     0,   273,   276,
     277,   278,   279,   280,   281,   282,   283,   284,     0,   290,
       0,     0,     0,     0,   238,     0,   233,     0,   371,     0,
     510,     0,   549,   502,   480,   481,   482,   465,   466,   485,
     486,   487,   488,   489,   501,   468,   469,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   462,   463,
     464,   478,   479,   475,   476,   477,   474,     0,   459,   467,
     483,   484,   470,   471,   472,   473,   455,   302,   690,   692,
       0,   685,   686,   687,   688,   689,   678,   679,   683,   684,
     680,   681,   682,     0,   670,   671,   674,   675,   676,   677,
     665,     0,   608,     0,   333,   360,   361,   362,   363,   364,
     365,   352,   325,   326,   327,   317,     0,     0,   699,   721,
       0,   724,     0,   713,   810,     0,   808,   806,   800,   804,
     805,     0,   797,   802,   803,   801,   793,   840,   841,   835,
      52,    57,     0,   581,     0,   223,   225,   264,   265,   266,
     263,   268,   270,   272,   287,   288,   289,   286,   292,   294,
     296,   298,   236,   374,   513,   552,   461,   458,     0,     0,
       0,   668,   673,   611,   336,   707,   709,   723,   726,     0,
       0,     0,   799,   796,    56,   584,   643,   460,     0,     0,
     694,   672,     0,   807,     0,   798,   691,   693,     0,   809,
     815,     0,   812,     0,   814,   811,   825,     0,     0,     0,
     830,     0,   817,   820,   821,   822,   823,   824,   813,     0,
       0,     0,     0,     0,   819,   816,     0,   827,   828,   829,
       0,   818,   826,   831
  };

  const short
  Dhcp4Parser::yypgoto_[] =
  {
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,   -51,  -993,  -590,  -993,   398,
    -993,  -993,  -993,  -993,  -993,  -993,  -621,  -993,  -993,  -993,
     -67,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   392,   596,
     -26,     9,    19,   -52,   -30,   -27,     7,    20,    27,    30,
    -993,  -993,  -993,  -993,    37,  -993,  -993,  -993,    38,    40,
      42,    43,    48,    50,  -993,   395,    53,  -993,    55,  -993,
      56,    58,    60,  -993,    61,  -993,    63,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,   393,   591,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,   126,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,   298,  -993,   103,  -993,  -705,   110,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
     -63,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,    93,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,    77,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,    85,  -993,  -993,  -993,    88,   557,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,    83,  -993,  -993,  -993,
    -993,  -993,  -993,  -992,  -993,  -993,  -993,   111,  -993,  -993,
    -993,   115,   593,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -988,  -993,   -65,  -993,    69,  -993,    66,    68,    71,
      73,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   108,  -993,
    -993,  -112,   -54,  -993,  -993,  -993,  -993,  -993,   116,  -993,
    -993,  -993,   117,  -993,   592,  -993,   -41,  -993,  -993,  -993,
    -993,  -993,   -40,  -993,  -993,  -993,  -993,  -993,   -23,  -993,
    -993,  -993,   128,  -993,  -993,  -993,   119,  -993,   584,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
      80,  -993,  -993,  -993,    78,   614,  -993,  -993,   -45,  -993,
      -3,  -993,   -48,  -993,  -993,  -993,   121,  -993,  -993,  -993,
     125,  -993,   609,   -55,  -993,   -13,  -993,     8,  -993,   358,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -987,  -993,  -993,
    -993,  -993,  -993,   130,  -993,  -993,  -993,   -93,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   109,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,    99,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,   399,   576,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,   437,   578,
    -993,  -993,  -993,  -993,  -993,  -993,   100,  -993,  -993,   -91,
    -993,  -993,  -993,  -993,  -993,  -993,  -115,  -993,  -993,  -132,
    -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,  -993,
     104,  -993,  -993
  };

  const short
  Dhcp4Parser::yydefgoto_[] =
  {
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    36,    37,    38,    65,   734,
      82,    83,    39,    64,    79,    80,   755,   955,  1053,  1054,
     830,    41,    66,    85,   429,    86,    43,    67,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   455,   168,   169,   471,   170,   171,   172,   173,
     174,   175,   176,   177,   461,   725,   178,   462,   179,   463,
     180,   181,   182,   490,   183,   491,   184,   185,   186,   187,
     188,   189,   190,   433,   229,   230,    45,    68,   231,   500,
     232,   501,   758,   233,   502,   761,   234,   235,   236,   237,
     191,   441,   192,   434,   806,   807,   808,   968,   809,   969,
     193,   442,   194,   443,   856,   857,   858,   995,   831,   832,
     833,   972,  1210,   834,   973,   835,   974,   836,   975,   837,
     838,   536,   839,   840,   841,   842,   843,   844,   845,   846,
     847,   848,   986,  1217,   849,   850,   988,   851,   989,   852,
     990,   853,   991,   195,   480,   880,   881,   882,   883,   884,
     885,   886,   196,   486,   916,   917,   918,   919,   920,   197,
     483,   895,   896,   897,  1018,    59,    75,   379,   380,   381,
     549,   382,   550,   198,   484,   904,   905,   906,   907,   908,
     909,   910,   911,   199,   467,   860,   861,   862,   998,    47,
      69,   275,   276,   277,   513,   278,   509,   279,   510,   280,
     511,   281,   514,   282,   517,   283,   516,   200,   201,   202,
     203,   476,   740,   288,   204,   473,   872,   873,   874,  1007,
    1127,  1128,   205,   468,    53,    72,   864,   865,   866,  1001,
      55,    73,   344,   345,   346,   347,   348,   349,   350,   535,
     351,   539,   352,   538,   353,   354,   540,   355,   206,   469,
     868,   869,   870,  1004,    57,    74,   365,   366,   367,   368,
     369,   544,   370,   371,   372,   373,   290,   512,   957,   958,
     959,  1055,    49,    70,   303,   304,   305,   521,   207,   474,
     208,   475,   209,   482,   891,   892,   893,  1015,    51,    71,
     320,   321,   322,   210,   438,   211,   439,   212,   440,   326,
     531,   962,  1058,   327,   525,   328,   526,   329,   528,   330,
     527,   331,   530,   332,   529,   333,   524,   297,   518,   963,
     213,   481,   888,   889,  1012,  1153,  1154,  1155,  1156,  1157,
    1228,  1158,  1229,  1159,   214,   215,   487,   928,   929,   930,
    1034,   931,  1035,   216,   488,   938,   939,   940,   941,  1039,
     942,   943,  1041,   217,   489,    61,    76,   401,   402,   403,
     404,   555,   405,   406,   557,   407,   408,   409,   560,   793,
     410,   561,   411,   554,   412,   413,   414,   564,   415,   565,
     416,   566,   417,   567,   218,   432,    63,    77,   420,   421,
     422,   570,   423,   219,   495,   946,   947,  1045,  1191,  1192,
    1193,  1194,  1241,  1195,  1239,  1261,  1262,  1263,  1271,  1272,
    1273,  1279,  1274,  1275,  1276,  1277,  1283,   220,   496,   951,
     952,   953,   954
  };

  const short
  Dhcp4Parser::yytable_[] =
  {
     153,   228,   250,   299,   316,   300,   342,   361,   378,   398,
     343,   362,   854,    78,   294,  1119,   323,   254,   334,  1120,
    1135,   293,   791,   238,   291,   306,   318,   430,   356,   374,
     733,   399,   431,   363,   364,    28,   129,   130,   768,   255,
     948,   949,   256,   251,   772,    81,   289,   302,   317,    29,
     426,    30,   498,    31,    40,   152,   295,   499,   324,   336,
     358,   337,   338,   359,   360,   239,   292,   307,   319,    42,
     357,   375,    44,   400,   129,   130,   257,   296,   252,   325,
      84,   720,   721,   722,   723,   932,   933,   934,   253,   258,
     507,   418,   419,   376,   377,   508,   259,   733,  1266,   260,
     519,  1267,  1268,  1269,  1270,   520,   261,   262,   522,   263,
     551,   264,   265,   523,   123,   552,   568,   266,   724,   267,
     424,   569,   268,   572,   269,   270,   498,   271,   573,   272,
     273,   965,   274,    87,    46,   284,    88,   285,   935,   301,
     286,    48,   287,    50,   572,   507,   124,    52,    89,   966,
     967,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      54,   298,   129,   130,   152,   221,   222,  1010,  1013,   223,
    1011,  1014,   224,   225,   226,   227,   152,   247,   792,   970,
     992,   248,   129,   130,   971,   993,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     992,  1027,    56,   123,   124,   994,  1028,   336,   898,   899,
     900,   901,   902,   903,   125,   126,   127,   128,   923,   924,
     129,   130,   129,   130,  1119,   131,   756,   757,  1120,  1135,
     132,   133,   134,   135,   136,    58,  1046,    60,  1032,  1047,
     137,   129,   130,  1033,    32,    33,    34,    35,   129,   130,
     138,   759,   760,   139,   152,    93,    94,    95,  1036,  1042,
     140,   141,   568,  1037,  1043,   142,  1050,  1044,   143,    62,
     992,  1051,   144,   425,   152,  1222,   875,   876,   877,   878,
    1085,   879,   519,   912,   913,   914,  1226,  1223,  1207,  1208,
    1209,  1227,   145,   146,   147,   148,   149,   150,  1264,   551,
    1184,  1265,  1185,  1186,  1234,  1242,   151,   427,   522,  1284,
    1243,   376,   377,  1245,  1285,   124,   736,   737,   738,   739,
     804,   805,   152,   428,   152,  1214,  1215,  1216,   315,   960,
     435,   129,   130,   436,    91,    92,    93,    94,    95,   437,
     444,   445,   446,   152,   447,   308,   448,   449,   450,   451,
     152,   452,   309,   310,   311,   312,   313,   314,   453,   315,
     454,   456,   457,   458,   574,   575,   459,   460,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   464,   465,
     466,   470,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   472,   240,   241,   242,   477,   124,   478,   479,   485,
     492,   493,   494,   497,   503,   504,   505,   126,   506,   515,
     243,   532,   129,   130,   244,   245,   246,   131,   533,   534,
     537,   153,   132,   133,   134,   541,   542,   247,   543,   548,
     228,   248,   137,   152,   545,   546,   547,   553,   556,   249,
     558,   559,   250,   562,   563,   299,   571,   300,   576,   577,
     578,   579,   238,   580,   294,   581,   316,   254,   582,   583,
     584,   293,   585,   586,   291,   587,   342,   306,   323,   588,
     343,   361,   589,   595,   601,   362,   590,   591,   318,   255,
     596,   607,   256,   251,   145,   146,   289,   592,   356,   302,
     597,   398,   593,   374,   239,   594,   295,   363,   364,   598,
     317,   599,   600,   602,   608,   603,   292,   609,   613,   307,
     324,   604,   614,   399,   152,   615,   257,   296,   252,   617,
     319,   605,   606,   610,   611,   612,   616,   618,   253,   258,
     357,   325,   619,   620,   621,   375,   259,   622,   623,   260,
     624,   625,   626,   627,   631,   628,   261,   262,   629,   263,
     630,   264,   265,   632,   633,   400,   634,   266,   635,   267,
     636,   637,   268,   638,   269,   270,   639,   271,   640,   272,
     273,   641,   274,  1246,   642,   284,   644,   285,   335,   645,
     286,   301,   287,   646,   647,    93,    94,    95,   652,   653,
     649,   648,   650,   654,   655,   656,   657,   658,   659,   810,
     660,   661,   663,   811,   812,   813,   814,   815,   816,   817,
     818,   819,   820,   821,   822,   823,   824,    99,   100,   101,
     825,   826,   827,   828,   829,   665,   666,   667,   668,   669,
     670,   671,   153,   336,   228,   337,   338,   672,   674,   339,
     340,   341,   675,   676,   123,   124,   336,   800,   129,   130,
     677,   678,   679,   682,   336,   686,   238,   680,   687,   129,
     130,   129,   130,   683,   684,   689,   690,   691,   692,   915,
     925,   693,   398,   694,   695,   696,   950,  1138,  1139,  1140,
     697,   700,   698,   701,   699,   702,   703,   705,   708,   706,
     713,   921,   926,   936,   399,   709,   710,   711,   239,   712,
     714,   715,   716,    91,    92,    93,    94,    95,   717,   718,
     728,   719,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   729,   726,   727,   730,   731,
     732,   396,   397,   922,   927,   937,   400,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    30,   741,   742,
     152,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   152,   743,   152,   744,   124,   336,   745,   735,   746,
     747,   152,   748,   749,   750,   751,   126,   752,   753,   754,
     765,   129,   130,   762,   245,   770,   131,   763,   764,   799,
     766,   132,   133,   134,   855,   859,   247,   767,   769,   863,
     248,   867,   871,   771,   887,   773,   890,   894,   249,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,   945,   774,   775,   776,   777,   778,   779,   780,
     781,   794,   956,   976,   977,   978,   979,   980,   782,   783,
     784,   785,   786,   981,   982,   788,   789,   790,   983,   796,
     797,   798,   984,   145,   146,   985,   987,   997,  1059,   996,
    1000,   999,  1002,  1003,  1005,  1006,  1009,  1008,  1017,  1052,
    1016,  1020,  1019,  1021,  1022,  1023,  1024,  1025,  1026,  1029,
    1030,  1031,  1038,   152,  1040,  1048,  1049,  1057,  1069,  1056,
    1061,  1060,  1062,  1064,  1065,  1066,  1067,  1068,  1070,  1078,
    1080,  1081,  1082,  1083,  1071,  1072,  1172,  1073,  1074,  1075,
    1076,  1077,  1176,  1079,  1165,  1177,  1180,  1166,  1167,  1168,
    1169,   250,  1170,  1173,   342,  1174,  1179,   361,   343,  1181,
    1093,   362,  1121,   294,  1118,  1141,   254,  1182,   316,  1145,
     293,   378,  1132,   291,  1197,  1097,   356,  1150,  1146,   374,
     323,  1198,  1130,   363,   364,   915,  1200,  1148,   255,   925,
     318,   256,   251,  1201,  1205,   289,  1204,  1098,  1187,  1224,
    1099,  1094,  1188,   950,  1129,   295,  1142,   921,   299,  1147,
     300,   926,   317,  1206,  1133,   292,  1211,   936,   357,  1151,
    1189,   375,   324,  1212,  1131,   257,   296,   252,  1225,  1149,
     306,  1213,   319,  1218,  1100,  1134,  1095,   253,   258,  1230,
    1152,  1143,  1219,   325,  1220,   259,  1096,  1101,   260,   922,
    1221,  1144,   302,   927,  1102,   261,   262,  1103,   263,   937,
     264,   265,  1190,  1231,  1104,  1105,   266,  1106,   267,  1107,
    1108,   268,   307,   269,   270,  1109,   271,  1110,   272,   273,
    1111,   274,  1112,  1113,   284,  1114,   285,  1115,  1116,   286,
    1117,   287,  1232,  1123,  1233,  1124,  1122,  1240,  1125,  1235,
    1126,  1248,  1249,  1252,  1254,   787,  1258,  1236,  1280,  1260,
    1281,  1282,  1286,  1290,   643,   795,  1063,   964,   651,  1237,
    1086,   801,  1084,  1137,   803,  1164,  1163,  1244,   688,  1175,
    1171,  1088,   662,  1087,  1247,  1253,  1250,  1136,  1089,  1090,
    1256,  1257,  1259,  1091,   301,  1288,  1287,  1289,   961,  1292,
    1293,  1238,   685,  1202,  1092,   681,   664,  1203,  1162,  1251,
    1161,  1183,   673,  1160,   704,  1178,  1196,   802,   944,  1278,
     707,  1255,  1291,     0,  1199,     0,     0,     0,     0,  1093,
       0,  1121,     0,  1118,     0,  1141,     0,     0,     0,  1145,
       0,  1132,     0,     0,  1097,  1187,     0,  1150,  1146,  1188,
       0,  1130,     0,     0,     0,     0,     0,  1148,     0,     0,
       0,     0,     0,     0,     0,     0,  1098,  1189,     0,  1099,
    1094,     0,     0,  1129,     0,     0,  1142,     0,     0,  1147,
       0,     0,     0,  1133,     0,     0,     0,     0,     0,  1151,
       0,     0,     0,  1131,     0,     0,     0,     0,     0,  1149,
       0,     0,     0,  1100,  1134,  1095,     0,     0,     0,  1190,
    1152,  1143,     0,     0,     0,  1096,  1101,     0,     0,     0,
       0,  1144,     0,  1102,     0,     0,  1103,     0,     0,     0,
       0,     0,     0,  1104,  1105,     0,  1106,     0,  1107,  1108,
       0,     0,     0,     0,  1109,     0,  1110,     0,     0,  1111,
       0,  1112,  1113,     0,  1114,     0,  1115,  1116,     0,  1117,
       0,     0,  1123,     0,  1124,  1122,     0,  1125,     0,  1126
  };

  const short
  Dhcp4Parser::yycheck_[] =
  {
      67,    68,    69,    70,    71,    70,    73,    74,    75,    76,
      73,    74,   717,    64,    69,  1007,    71,    69,    72,  1007,
    1007,    69,    18,    68,    69,    70,    71,     3,    73,    74,
     620,    76,     8,    74,    74,     0,   108,   109,   659,    69,
     195,   196,    69,    69,   665,   210,    69,    70,    71,     5,
       4,     7,     3,     9,     7,   210,    69,     8,    71,    93,
      94,    95,    96,    97,    98,    68,    69,    70,    71,     7,
      73,    74,     7,    76,   108,   109,    69,    69,    69,    71,
      10,   176,   177,   178,   179,   157,   158,   159,    69,    69,
       3,    12,    13,   139,   140,     8,    69,   687,   187,    69,
       3,   190,   191,   192,   193,     8,    69,    69,     3,    69,
       3,    69,    69,     8,    91,     8,     3,    69,   213,    69,
       6,     8,    69,     3,    69,    69,     3,    69,     8,    69,
      69,     8,    69,    11,     7,    69,    14,    69,   210,    70,
      69,     7,    69,     7,     3,     3,    92,     7,    26,     8,
       8,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       7,   107,   108,   109,   210,    15,    16,     3,     3,    19,
       6,     6,    22,    23,    24,    25,   210,   123,   174,     3,
       3,   127,   108,   109,     8,     8,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       3,     3,     7,    91,    92,     8,     8,    93,   142,   143,
     144,   145,   146,   147,   102,   103,   104,   105,   154,   155,
     108,   109,   108,   109,  1226,   113,    17,    18,  1226,  1226,
     118,   119,   120,   121,   122,     7,     3,     7,     3,     6,
     128,   108,   109,     8,   210,   211,   212,   213,   108,   109,
     138,    20,    21,   141,   210,    32,    33,    34,     3,     3,
     148,   149,     3,     8,     8,   153,     3,     8,   156,     7,
       3,     8,   160,     3,   210,     8,   129,   130,   131,   132,
     995,   134,     3,   150,   151,   152,     3,     8,    39,    40,
      41,     8,   180,   181,   182,   183,   184,   185,     3,     3,
     186,     6,   188,   189,     8,     3,   194,     8,     3,     3,
       8,   139,   140,     8,     8,    92,   114,   115,   116,   117,
      27,    28,   210,     3,   210,    56,    57,    58,   136,   137,
       4,   108,   109,     4,    30,    31,    32,    33,    34,     4,
       4,     4,     4,   210,     4,   122,     4,     4,     4,     4,
     210,     4,   129,   130,   131,   132,   133,   134,     4,   136,
       4,     4,     4,     4,   425,   426,     4,     4,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     4,     4,
       4,     4,    78,    79,    80,    81,    82,    83,    84,    85,
      86,     4,    88,    89,    90,     4,    92,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,   103,     4,     4,
     106,     8,   108,   109,   110,   111,   112,   113,     3,     8,
       4,   498,   118,   119,   120,     4,     8,   123,     3,     3,
     507,   127,   128,   210,     4,     4,     8,     4,     4,   135,
       4,     4,   519,     4,     4,   522,     4,   522,   210,     4,
       4,     4,   507,     4,   519,   213,   533,   519,   213,   213,
       4,   519,     4,     4,   519,     4,   543,   522,   533,     4,
     543,   548,     4,   213,     4,   548,   211,   211,   533,   519,
     212,     4,   519,   519,   180,   181,   519,   211,   543,   522,
     212,   568,   211,   548,   507,   211,   519,   548,   548,   212,
     533,   211,   211,   211,     4,   211,   519,     4,     4,   522,
     533,   213,     4,   568,   210,     4,   519,   519,   519,     4,
     533,   213,   213,   213,   213,   213,   211,   213,   519,   519,
     543,   533,     4,     4,     4,   548,   519,     4,   213,   519,
     213,   213,     4,     4,   211,     4,   519,   519,     4,   519,
       4,   519,   519,     4,     4,   568,     4,   519,     4,   519,
       4,     4,   519,   213,   519,   519,   213,   519,   213,   519,
     519,     4,   519,  1204,     4,   519,     4,   519,    38,     4,
     519,   522,   519,     4,   213,    32,    33,    34,     4,     4,
     211,   213,   211,     4,     4,     4,     4,   211,     4,    38,
       4,     4,     4,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    64,    65,    66,
      59,    60,    61,    62,    63,     4,     4,     4,     4,     4,
       4,     4,   709,    93,   711,    95,    96,     4,     4,    99,
     100,   101,     4,   211,    91,    92,    93,   708,   108,   109,
       4,     4,     4,     4,    93,     4,   711,   213,     4,   108,
     109,   108,   109,   213,   213,   213,     4,     4,   211,   746,
     747,     4,   749,   211,   211,     4,   753,   124,   125,   126,
       4,     4,   213,     4,   213,     4,     4,     4,     4,   211,
     210,   746,   747,   748,   749,     7,     7,     7,   711,     7,
     210,   210,     7,    30,    31,    32,    33,    34,     7,     5,
       5,   210,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     5,   210,   210,     5,   210,
       5,   180,   181,   746,   747,   748,   749,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     7,     5,     5,
     210,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   210,     5,   210,     5,    92,    93,     7,   210,     7,
       7,   210,     7,     7,   210,   210,   103,     5,     7,     5,
       5,   108,   109,   210,   111,     7,   113,   210,   210,     5,
     210,   118,   119,   120,     7,     7,   123,   210,   210,     7,
     127,     7,     7,   210,     7,   210,     7,     7,   135,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,     7,   210,   210,   210,   210,   210,   210,   210,
     210,   175,     7,     4,     4,     4,     4,     4,   210,   210,
     210,   210,   210,     4,     4,   210,   210,   210,     4,   210,
     210,   210,     4,   180,   181,     4,     4,     3,     8,     6,
       3,     6,     6,     3,     6,     3,     3,     6,     3,   210,
       6,     3,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,   210,     4,     4,     4,     3,   213,     6,
       4,     6,     4,     4,     4,     4,     4,   211,   211,     4,
       4,     4,     4,     4,   213,   211,   213,   211,   211,   211,
     211,   211,     4,   211,   211,     4,     4,   211,   211,   211,
     211,   998,   211,   211,  1001,   211,   213,  1004,  1001,   211,
    1007,  1004,  1007,   998,  1007,  1012,   998,     4,  1015,  1012,
     998,  1018,  1007,   998,   213,  1007,  1001,  1012,  1012,  1004,
    1015,   213,  1007,  1004,  1004,  1032,     6,  1012,   998,  1036,
    1015,   998,   998,     3,   210,   998,     4,  1007,  1045,     8,
    1007,  1007,  1045,  1050,  1007,   998,  1012,  1032,  1055,  1012,
    1055,  1036,  1015,   210,  1007,   998,   210,  1042,  1001,  1012,
    1045,  1004,  1015,   210,  1007,   998,   998,   998,     8,  1012,
    1055,   210,  1015,   210,  1007,  1007,  1007,   998,   998,     4,
    1012,  1012,   210,  1015,   210,   998,  1007,  1007,   998,  1032,
     210,  1012,  1055,  1036,  1007,   998,   998,  1007,   998,  1042,
     998,   998,  1045,     8,  1007,  1007,   998,  1007,   998,  1007,
    1007,   998,  1055,   998,   998,  1007,   998,  1007,   998,   998,
    1007,   998,  1007,  1007,   998,  1007,   998,  1007,  1007,   998,
    1007,   998,     3,  1007,     8,  1007,  1007,     4,  1007,   210,
    1007,     4,     4,     4,     4,   687,     5,   210,     4,     7,
       4,     4,     4,     4,   498,   700,   970,   799,   507,   210,
     997,   709,   992,  1010,   711,  1020,  1018,   210,   551,  1032,
    1027,  1000,   519,   998,  1226,   211,   213,  1009,  1001,  1003,
     210,   210,   210,  1004,  1055,   211,   213,   211,   770,   210,
     210,  1182,   548,  1055,  1006,   543,   522,  1057,  1017,  1232,
    1015,  1042,   533,  1013,   568,  1036,  1046,   710,   749,  1264,
     572,  1242,  1284,    -1,  1050,    -1,    -1,    -1,    -1,  1226,
      -1,  1226,    -1,  1226,    -1,  1232,    -1,    -1,    -1,  1232,
      -1,  1226,    -1,    -1,  1226,  1242,    -1,  1232,  1232,  1242,
      -1,  1226,    -1,    -1,    -1,    -1,    -1,  1232,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1226,  1242,    -1,  1226,
    1226,    -1,    -1,  1226,    -1,    -1,  1232,    -1,    -1,  1232,
      -1,    -1,    -1,  1226,    -1,    -1,    -1,    -1,    -1,  1232,
      -1,    -1,    -1,  1226,    -1,    -1,    -1,    -1,    -1,  1232,
      -1,    -1,    -1,  1226,  1226,  1226,    -1,    -1,    -1,  1242,
    1232,  1232,    -1,    -1,    -1,  1226,  1226,    -1,    -1,    -1,
      -1,  1232,    -1,  1226,    -1,    -1,  1226,    -1,    -1,    -1,
      -1,    -1,    -1,  1226,  1226,    -1,  1226,    -1,  1226,  1226,
      -1,    -1,    -1,    -1,  1226,    -1,  1226,    -1,    -1,  1226,
      -1,  1226,  1226,    -1,  1226,    -1,  1226,  1226,    -1,  1226,
      -1,    -1,  1226,    -1,  1226,  1226,    -1,  1226,    -1,  1226
  };

  const short
  Dhcp4Parser::yystos_[] =
  {
       0,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,     0,     5,
       7,     9,   210,   211,   212,   213,   229,   230,   231,   236,
       7,   245,     7,   250,     7,   300,     7,   413,     7,   496,
       7,   512,     7,   448,     7,   454,     7,   478,     7,   389,
       7,   579,     7,   610,   237,   232,   246,   251,   301,   414,
     497,   513,   449,   455,   479,   390,   580,   611,   229,   238,
     239,   210,   234,   235,    10,   247,   249,    11,    14,    26,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    91,    92,   102,   103,   104,   105,   108,
     109,   113,   118,   119,   120,   121,   122,   128,   138,   141,
     148,   149,   153,   156,   160,   180,   181,   182,   183,   184,
     185,   194,   210,   244,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   267,   268,
     270,   271,   272,   273,   274,   275,   276,   277,   280,   282,
     284,   285,   286,   288,   290,   291,   292,   293,   294,   295,
     296,   314,   316,   324,   326,   367,   376,   383,   397,   407,
     431,   432,   433,   434,   438,   446,   472,   502,   504,   506,
     517,   519,   521,   544,   558,   559,   567,   577,   608,   617,
     641,    15,    16,    19,    22,    23,    24,    25,   244,   298,
     299,   302,   304,   307,   310,   311,   312,   313,   502,   504,
      88,    89,    90,   106,   110,   111,   112,   123,   127,   135,
     244,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   268,   272,   273,   274,   275,   276,   277,   280,   282,
     284,   285,   286,   288,   290,   415,   416,   417,   419,   421,
     423,   425,   427,   429,   431,   432,   433,   434,   437,   472,
     490,   502,   504,   506,   517,   519,   521,   541,   107,   244,
     427,   429,   472,   498,   499,   500,   502,   504,   122,   129,
     130,   131,   132,   133,   134,   136,   244,   472,   502,   504,
     514,   515,   516,   517,   519,   521,   523,   527,   529,   531,
     533,   535,   537,   539,   446,    38,    93,    95,    96,    99,
     100,   101,   244,   344,   456,   457,   458,   459,   460,   461,
     462,   464,   466,   468,   469,   471,   502,   504,    94,    97,
      98,   244,   344,   460,   466,   480,   481,   482,   483,   484,
     486,   487,   488,   489,   502,   504,   139,   140,   244,   391,
     392,   393,   395,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   180,   181,   244,   502,
     504,   581,   582,   583,   584,   586,   587,   589,   590,   591,
     594,   596,   598,   599,   600,   602,   604,   606,    12,    13,
     612,   613,   614,   616,     6,     3,     4,     8,     3,   248,
       3,     8,   609,   297,   317,     4,     4,     4,   518,   520,
     522,   315,   325,   327,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,   266,     4,     4,     4,     4,
       4,   278,   281,   283,     4,     4,     4,   408,   447,   473,
       4,   269,     4,   439,   503,   505,   435,     4,     4,     4,
     368,   545,   507,   384,   398,     4,   377,   560,   568,   578,
     287,   289,     4,     4,     4,   618,   642,     4,     3,     8,
     303,   305,   308,     4,     4,     4,     4,     3,     8,   420,
     422,   424,   491,   418,   426,     4,   430,   428,   542,     3,
       8,   501,     3,     8,   540,   528,   530,   534,   532,   538,
     536,   524,     8,     3,     8,   463,   345,     4,   467,   465,
     470,     4,     8,     3,   485,     4,     4,     8,     3,   394,
     396,     3,     8,     4,   597,   585,     4,   588,     4,     4,
     592,   595,     4,     4,   601,   603,   605,   607,     3,     8,
     615,     4,     3,     8,   229,   229,   210,     4,     4,     4,
       4,   213,   213,   213,     4,     4,     4,     4,     4,     4,
     211,   211,   211,   211,   211,   213,   212,   212,   212,   211,
     211,     4,   211,   211,   213,   213,   213,     4,     4,     4,
     213,   213,   213,     4,     4,     4,   211,     4,   213,     4,
       4,     4,     4,   213,   213,   213,     4,     4,     4,     4,
       4,   211,     4,     4,     4,     4,     4,     4,   213,   213,
     213,     4,     4,   253,     4,     4,     4,   213,   213,   211,
     211,   299,     4,     4,     4,     4,     4,     4,   211,     4,
       4,     4,   416,     4,   499,     4,     4,     4,     4,     4,
       4,     4,     4,   516,     4,     4,   211,     4,     4,     4,
     213,   458,     4,   213,   213,   482,     4,     4,   392,   213,
       4,     4,   211,     4,   211,   211,     4,     4,   213,   213,
       4,     4,     4,     4,   582,     4,   211,   613,     4,     7,
       7,     7,     7,   210,   210,   210,     7,     7,     5,   210,
     176,   177,   178,   179,   213,   279,   210,   210,     5,     5,
       5,   210,     5,   231,   233,   210,   114,   115,   116,   117,
     436,     5,     5,     5,     5,     7,     7,     7,     7,     7,
     210,   210,     5,     7,     5,   240,    17,    18,   306,    20,
      21,   309,   210,   210,   210,     5,   210,   210,   240,   210,
       7,   210,   240,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   233,   210,   210,
     210,    18,   174,   593,   175,   279,   210,   210,   210,     5,
     229,   252,   612,   298,    27,    28,   318,   319,   320,   322,
      38,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    59,    60,    61,    62,    63,
     244,   332,   333,   334,   337,   339,   341,   343,   344,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   358,
     359,   361,   363,   365,   332,     7,   328,   329,   330,     7,
     409,   410,   411,     7,   450,   451,   452,     7,   474,   475,
     476,     7,   440,   441,   442,   129,   130,   131,   132,   134,
     369,   370,   371,   372,   373,   374,   375,     7,   546,   547,
       7,   508,   509,   510,     7,   385,   386,   387,   142,   143,
     144,   145,   146,   147,   399,   400,   401,   402,   403,   404,
     405,   406,   150,   151,   152,   244,   378,   379,   380,   381,
     382,   502,   504,   154,   155,   244,   502,   504,   561,   562,
     563,   565,   157,   158,   159,   210,   502,   504,   569,   570,
     571,   572,   574,   575,   581,     7,   619,   620,   195,   196,
     244,   643,   644,   645,   646,   241,     7,   492,   493,   494,
     137,   523,   525,   543,   328,     8,     8,     8,   321,   323,
       3,     8,   335,   338,   340,   342,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,   356,     4,   360,   362,
     364,   366,     3,     8,     8,   331,     6,     3,   412,     6,
       3,   453,     6,     3,   477,     6,     3,   443,     6,     3,
       3,     6,   548,     3,     6,   511,     6,     3,   388,     6,
       3,     4,     4,     4,     4,     4,     4,     3,     8,     4,
       4,     4,     3,     8,   564,   566,     3,     8,     4,   573,
       4,   576,     3,     8,     8,   621,     3,     6,     4,     4,
       3,     8,   210,   242,   243,   495,     6,     3,   526,     8,
       6,     4,     4,   319,     4,     4,     4,     4,   211,   213,
     211,   213,   211,   211,   211,   211,   211,   211,     4,   211,
       4,     4,     4,     4,   333,   332,   330,   415,   411,   456,
     452,   480,   476,   244,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   268,   272,   273,   274,   275,   276,
     277,   280,   282,   284,   285,   286,   288,   290,   344,   407,
     425,   427,   429,   431,   432,   433,   434,   444,   445,   472,
     502,   504,   517,   519,   521,   541,   442,   370,   124,   125,
     126,   244,   254,   255,   256,   344,   446,   472,   502,   504,
     517,   519,   521,   549,   550,   551,   552,   553,   555,   557,
     547,   514,   510,   391,   387,   211,   211,   211,   211,   211,
     211,   400,   213,   211,   211,   379,     4,     4,   562,   213,
       4,   211,     4,   570,   186,   188,   189,   244,   344,   502,
     504,   622,   623,   624,   625,   627,   620,   213,   213,   644,
       6,     3,   498,   494,     4,   210,   210,    39,    40,    41,
     336,   210,   210,   210,    56,    57,    58,   357,   210,   210,
     210,   210,     8,     8,     8,     8,     3,     8,   554,   556,
       4,     8,     3,     8,     8,   210,   210,   210,   229,   628,
       4,   626,     3,     8,   210,     8,   240,   445,     4,     4,
     213,   551,     4,   211,     4,   623,   210,   210,     5,   210,
       7,   629,   630,   631,     3,     6,   187,   190,   191,   192,
     193,   632,   633,   634,   636,   637,   638,   639,   630,   635,
       4,     4,     4,   640,     3,     8,     4,   213,   211,   211,
       4,   633,   210,   210
  };

  const short
  Dhcp4Parser::yyr1_[] =
  {
       0,   214,   216,   215,   217,   215,   218,   215,   219,   215,
     220,   215,   221,   215,   222,   215,   223,   215,   224,   215,
     225,   215,   226,   215,   227,   215,   228,   215,   229,   229,
     229,   229,   229,   229,   229,   230,   232,   231,   233,   234,
     234,   235,   235,   235,   237,   236,   238,   238,   239,   239,
     239,   241,   240,   242,   242,   243,   243,   243,   244,   246,
     245,   248,   247,   247,   249,   251,   250,   252,   252,   252,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   266,   265,   267,
     269,   268,   270,   271,   272,   273,   274,   275,   276,   278,
     277,   279,   279,   279,   279,   279,   281,   280,   283,   282,
     284,   285,   287,   286,   289,   288,   290,   291,   292,   293,
     294,   295,   297,   296,   298,   298,   298,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   301,   300,   303,
     302,   305,   304,   306,   306,   308,   307,   309,   309,   310,
     311,   312,   313,   315,   314,   317,   316,   318,   318,   318,
     319,   319,   321,   320,   323,   322,   325,   324,   327,   326,
     328,   328,   329,   329,   329,   331,   330,   332,   332,   332,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   335,   334,   336,   336,   336,   338,   337,   340,
     339,   342,   341,   343,   345,   344,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   356,   355,   357,   357,   357,
     358,   360,   359,   362,   361,   364,   363,   366,   365,   368,
     367,   369,   369,   369,   370,   370,   370,   370,   370,   371,
     372,   373,   374,   375,   377,   376,   378,   378,   378,   379,
     379,   379,   379,   379,   379,   380,   381,   382,   384,   383,
     385,   385,   386,   386,   386,   388,   387,   390,   389,   391,
     391,   391,   391,   392,   392,   394,   393,   396,   395,   398,
     397,   399,   399,   399,   400,   400,   400,   400,   400,   400,
     401,   402,   403,   404,   405,   406,   408,   407,   409,   409,
     410,   410,   410,   412,   411,   414,   413,   415,   415,   415,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   416,   418,   417,   420,   419,
     422,   421,   424,   423,   426,   425,   428,   427,   430,   429,
     431,   432,   433,   435,   434,   436,   436,   436,   436,   437,
     439,   438,   440,   440,   441,   441,   441,   443,   442,   444,
     444,   444,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   447,   446,   449,   448,   450,   450,   451,
     451,   451,   453,   452,   455,   454,   456,   456,   457,   457,
     457,   458,   458,   458,   458,   458,   458,   458,   458,   458,
     458,   459,   460,   461,   463,   462,   465,   464,   467,   466,
     468,   470,   469,   471,   473,   472,   474,   474,   475,   475,
     475,   477,   476,   479,   478,   480,   480,   481,   481,   481,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   483,
     485,   484,   486,   487,   488,   489,   491,   490,   492,   492,
     493,   493,   493,   495,   494,   497,   496,   498,   498,   498,
     499,   499,   499,   499,   499,   499,   499,   501,   500,   503,
     502,   505,   504,   507,   506,   508,   508,   509,   509,   509,
     511,   510,   513,   512,   514,   514,   515,   515,   515,   516,
     516,   516,   516,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   516,   516,   518,   517,   520,   519,   522,   521,
     524,   523,   526,   525,   528,   527,   530,   529,   532,   531,
     534,   533,   536,   535,   538,   537,   540,   539,   542,   541,
     543,   543,   545,   544,   546,   546,   546,   548,   547,   549,
     549,   550,   550,   550,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   552,
     554,   553,   556,   555,   557,   558,   560,   559,   561,   561,
     561,   562,   562,   562,   562,   562,   564,   563,   566,   565,
     568,   567,   569,   569,   569,   570,   570,   570,   570,   570,
     570,   571,   573,   572,   574,   576,   575,   578,   577,   580,
     579,   581,   581,   581,   582,   582,   582,   582,   582,   582,
     582,   582,   582,   582,   582,   582,   582,   582,   582,   582,
     582,   582,   583,   585,   584,   586,   588,   587,   589,   590,
     592,   591,   593,   593,   595,   594,   597,   596,   598,   599,
     601,   600,   603,   602,   605,   604,   607,   606,   609,   608,
     611,   610,   612,   612,   612,   613,   613,   615,   614,   616,
     618,   617,   619,   619,   619,   621,   620,   622,   622,   622,
     623,   623,   623,   623,   623,   623,   623,   624,   626,   625,
     628,   627,   629,   629,   629,   631,   630,   632,   632,   632,
     633,   633,   633,   633,   633,   635,   634,   636,   637,   638,
     640,   639,   642,   641,   643,   643,   643,   644,   644,   644,
     645,   646
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
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     0,     4,     3,
       0,     4,     3,     3,     3,     3,     3,     3,     3,     0,
       4,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       3,     3,     0,     4,     0,     4,     3,     3,     3,     3,
       3,     3,     0,     6,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     1,     1,     0,     4,     1,     1,     3,
       3,     3,     3,     0,     6,     0,     6,     1,     3,     2,
       1,     1,     0,     4,     0,     4,     0,     6,     0,     6,
       0,     1,     1,     3,     2,     0,     4,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     3,     0,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     0,     4,     1,     1,     1,
       3,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       6,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     1,     3,     2,     1,
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
       1,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       3,     3,     3,     0,     4,     1,     1,     1,     1,     3,
       0,     6,     0,     1,     1,     3,     2,     0,     4,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     0,     4,     0,     1,     1,
       3,     2,     0,     4,     0,     4,     0,     1,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     0,     4,     0,     4,     0,     4,
       1,     0,     4,     3,     0,     6,     0,     1,     1,     3,
       2,     0,     4,     0,     4,     0,     1,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     1,     1,     3,     3,     0,     6,     0,     1,
       1,     3,     2,     0,     4,     0,     4,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     0,     6,     0,     1,     1,     3,     2,
       0,     4,     0,     4,     0,     1,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     6,
       1,     1,     0,     6,     1,     3,     2,     0,     4,     0,
       1,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     0,     4,     3,     3,     0,     6,     1,     3,
       2,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       0,     6,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     3,     0,     4,     3,     0,     4,     0,     6,     0,
       4,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     4,     3,     0,     4,     3,     3,
       0,     4,     1,     1,     0,     4,     0,     4,     3,     3,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     6,
       0,     4,     1,     3,     2,     1,     1,     0,     6,     3,
       0,     6,     1,     3,     2,     0,     4,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     4,
       0,     6,     1,     3,     2,     0,     4,     1,     3,     2,
       1,     1,     1,     1,     1,     0,     4,     3,     3,     3,
       0,     4,     0,     6,     1,     3,     2,     1,     1,     1,
       3,     3
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
  "\"connect-timeout\"", "\"read-timeout\"", "\"write-timeout\"",
  "\"tcp-user-timeout\"", "\"max-reconnect-tries\"",
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
  "\"csv-format\"", "\"always-send\"", "\"record-types\"",
  "\"encapsulate\"", "\"array\"", "\"parked-packet-limit\"",
  "\"allocator\"", "\"exclude-first-last-24\"", "\"shared-networks\"",
  "\"pools\"", "\"pool\"", "\"user-context\"", "\"comment\"", "\"subnet\"",
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
  "parked_packet_limit", "allocator", "$@21", "exclude_first_last_24",
  "echo_client_id", "match_client_id", "authoritative",
  "ddns_send_updates", "ddns_override_no_update",
  "ddns_override_client_update", "ddns_replace_client_name", "$@22",
  "ddns_replace_client_name_value", "ddns_generated_prefix", "$@23",
  "ddns_qualifying_suffix", "$@24", "ddns_update_on_renew",
  "ddns_use_conflict_resolution", "hostname_char_set", "$@25",
  "hostname_char_replacement", "$@26", "store_extended_info",
  "statistic_default_sample_count", "statistic_default_sample_age",
  "early_global_reservations_lookup", "ip_reservations_unique",
  "reservations_lookup_first", "interfaces_config", "$@27",
  "interfaces_config_params", "interfaces_config_param", "sub_interfaces4",
  "$@28", "interfaces_list", "$@29", "dhcp_socket_type", "$@30",
  "socket_type", "outbound_interface", "$@31", "outbound_interface_value",
  "re_detect", "service_sockets_require_all",
  "service_sockets_retry_wait_time", "service_sockets_max_retries",
  "lease_database", "$@32", "sanity_checks", "$@33",
  "sanity_checks_params", "sanity_checks_param", "lease_checks", "$@34",
  "extended_info_checks", "$@35", "hosts_database", "$@36",
  "hosts_databases", "$@37", "database_list", "not_empty_database_list",
  "database", "$@38", "database_map_params", "database_map_param",
  "database_type", "$@39", "db_type", "user", "$@40", "password", "$@41",
  "host", "$@42", "port", "name", "$@43", "persist", "lfc_interval",
  "readonly", "connect_timeout", "read_timeout", "write_timeout",
  "tcp_user_timeout", "max_reconnect_tries", "reconnect_wait_time",
  "on_fail", "$@44", "on_fail_mode", "max_row_errors", "trust_anchor",
  "$@45", "cert_file", "$@46", "key_file", "$@47", "cipher_list", "$@48",
  "host_reservation_identifiers", "$@49",
  "host_reservation_identifiers_list", "host_reservation_identifier",
  "duid_id", "hw_address_id", "circuit_id", "client_id", "flex_id",
  "dhcp_multi_threading", "$@50", "multi_threading_params",
  "multi_threading_param", "enable_multi_threading", "thread_pool_size",
  "packet_queue_size", "hooks_libraries", "$@51", "hooks_libraries_list",
  "not_empty_hooks_libraries_list", "hooks_library", "$@52",
  "sub_hooks_library", "$@53", "hooks_params", "hooks_param", "library",
  "$@54", "parameters", "$@55", "expired_leases_processing", "$@56",
  "expired_leases_params", "expired_leases_param",
  "reclaim_timer_wait_time", "flush_reclaimed_timer_wait_time",
  "hold_reclaimed_time", "max_reclaim_leases", "max_reclaim_time",
  "unwarned_reclaim_cycles", "subnet4_list", "$@57",
  "subnet4_list_content", "not_empty_subnet4_list", "subnet4", "$@58",
  "sub_subnet4", "$@59", "subnet4_params", "subnet4_param", "subnet",
  "$@60", "subnet_4o6_interface", "$@61", "subnet_4o6_interface_id",
  "$@62", "subnet_4o6_subnet", "$@63", "interface", "$@64", "client_class",
  "$@65", "require_client_classes", "$@66", "reservations_global",
  "reservations_in_subnet", "reservations_out_of_pool", "reservation_mode",
  "$@67", "hr_mode", "id", "shared_networks", "$@68",
  "shared_networks_content", "shared_networks_list", "shared_network",
  "$@69", "shared_network_params", "shared_network_param",
  "option_def_list", "$@70", "sub_option_def_list", "$@71",
  "option_def_list_content", "not_empty_option_def_list",
  "option_def_entry", "$@72", "sub_option_def", "$@73",
  "option_def_params", "not_empty_option_def_params", "option_def_param",
  "option_def_name", "code", "option_def_code", "option_def_type", "$@74",
  "option_def_record_types", "$@75", "space", "$@76", "option_def_space",
  "option_def_encapsulate", "$@77", "option_def_array", "option_data_list",
  "$@78", "option_data_list_content", "not_empty_option_data_list",
  "option_data_entry", "$@79", "sub_option_data", "$@80",
  "option_data_params", "not_empty_option_data_params",
  "option_data_param", "option_data_name", "option_data_data", "$@81",
  "option_data_code", "option_data_space", "option_data_csv_format",
  "option_data_always_send", "pools_list", "$@82", "pools_list_content",
  "not_empty_pools_list", "pool_list_entry", "$@83", "sub_pool4", "$@84",
  "pool_params", "pool_param", "pool_entry", "$@85", "user_context",
  "$@86", "comment", "$@87", "reservations", "$@88", "reservations_list",
  "not_empty_reservations_list", "reservation", "$@89", "sub_reservation",
  "$@90", "reservation_params", "not_empty_reservation_params",
  "reservation_param", "next_server", "$@91", "server_hostname", "$@92",
  "boot_file_name", "$@93", "ip_address", "$@94", "ip_addresses", "$@95",
  "duid", "$@96", "hw_address", "$@97", "client_id_value", "$@98",
  "circuit_id_value", "$@99", "flex_id_value", "$@100", "hostname",
  "$@101", "reservation_client_classes", "$@102", "relay", "$@103",
  "relay_map", "client_classes", "$@104", "client_classes_list",
  "client_class_entry", "$@105", "client_class_params",
  "not_empty_client_class_params", "client_class_param",
  "client_class_name", "client_class_test", "$@106",
  "client_class_template_test", "$@107", "only_if_required",
  "dhcp4o6_port", "control_socket", "$@108", "control_socket_params",
  "control_socket_param", "control_socket_type", "$@109",
  "control_socket_name", "$@110", "dhcp_queue_control", "$@111",
  "queue_control_params", "queue_control_param", "enable_queue",
  "queue_type", "$@112", "capacity", "arbitrary_map_entry", "$@113",
  "dhcp_ddns", "$@114", "sub_dhcp_ddns", "$@115", "dhcp_ddns_params",
  "dhcp_ddns_param", "enable_updates", "server_ip", "$@116", "server_port",
  "sender_ip", "$@117", "sender_port", "max_queue_size", "ncr_protocol",
  "$@118", "ncr_protocol_value", "ncr_format", "$@119",
  "dep_qualifying_suffix", "$@120", "dep_override_no_update",
  "dep_override_client_update", "dep_replace_client_name", "$@121",
  "dep_generated_prefix", "$@122", "dep_hostname_char_set", "$@123",
  "dep_hostname_char_replacement", "$@124", "config_control", "$@125",
  "sub_config_control", "$@126", "config_control_params",
  "config_control_param", "config_databases", "$@127",
  "config_fetch_wait_time", "loggers", "$@128", "loggers_entries",
  "logger_entry", "$@129", "logger_params", "logger_param", "debuglevel",
  "severity", "$@130", "output_options_list", "$@131",
  "output_options_list_content", "output_entry", "$@132",
  "output_params_list", "output_params", "output", "$@133", "flush",
  "maxsize", "maxver", "pattern", "$@134", "compatibility", "$@135",
  "compatibility_params", "compatibility_param", "lenient_option_parsing",
  "ignore-rai-link-selection", YY_NULLPTR
  };
#endif


#if PARSER4_DEBUG
  const short
  Dhcp4Parser::yyrline_[] =
  {
       0,   303,   303,   303,   304,   304,   305,   305,   306,   306,
     307,   307,   308,   308,   309,   309,   310,   310,   311,   311,
     312,   312,   313,   313,   314,   314,   315,   315,   323,   324,
     325,   326,   327,   328,   329,   332,   337,   337,   348,   351,
     352,   355,   360,   366,   371,   371,   378,   379,   382,   386,
     390,   396,   396,   403,   404,   407,   411,   415,   425,   434,
     434,   449,   449,   463,   466,   472,   472,   481,   482,   483,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   558,   564,   570,   576,
     582,   588,   594,   600,   606,   612,   618,   624,   624,   633,
     639,   639,   648,   654,   660,   666,   672,   678,   684,   690,
     690,   699,   702,   705,   708,   711,   717,   717,   726,   726,
     735,   741,   747,   747,   756,   756,   765,   771,   777,   783,
     789,   795,   801,   801,   813,   814,   815,   820,   821,   822,
     823,   824,   825,   826,   827,   828,   829,   832,   832,   841,
     841,   852,   852,   860,   861,   864,   864,   872,   874,   878,
     884,   890,   896,   902,   902,   915,   915,   926,   927,   928,
     933,   934,   937,   937,   956,   956,   974,   974,   987,   987,
     998,   999,  1002,  1003,  1004,  1009,  1009,  1019,  1020,  1021,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,
    1046,  1047,  1050,  1050,  1058,  1059,  1060,  1063,  1063,  1072,
    1072,  1081,  1081,  1090,  1096,  1096,  1105,  1111,  1117,  1123,
    1129,  1135,  1141,  1147,  1153,  1159,  1159,  1167,  1168,  1169,
    1172,  1178,  1178,  1187,  1187,  1196,  1196,  1205,  1205,  1214,
    1214,  1225,  1226,  1227,  1232,  1233,  1234,  1235,  1236,  1239,
    1244,  1249,  1254,  1259,  1266,  1266,  1279,  1280,  1281,  1286,
    1287,  1288,  1289,  1290,  1291,  1294,  1300,  1306,  1312,  1312,
    1323,  1324,  1327,  1328,  1329,  1334,  1334,  1344,  1344,  1354,
    1355,  1356,  1359,  1362,  1363,  1366,  1366,  1375,  1375,  1384,
    1384,  1396,  1397,  1398,  1403,  1404,  1405,  1406,  1407,  1408,
    1411,  1417,  1423,  1429,  1435,  1441,  1450,  1450,  1464,  1465,
    1468,  1469,  1470,  1479,  1479,  1505,  1505,  1516,  1517,  1518,
    1524,  1525,  1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,
    1534,  1535,  1536,  1537,  1538,  1539,  1540,  1541,  1542,  1543,
    1544,  1545,  1546,  1547,  1548,  1549,  1550,  1551,  1552,  1553,
    1554,  1555,  1556,  1557,  1558,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1566,  1567,  1568,  1569,  1572,  1572,  1581,  1581,
    1590,  1590,  1599,  1599,  1608,  1608,  1617,  1617,  1626,  1626,
    1637,  1643,  1649,  1655,  1655,  1663,  1664,  1665,  1666,  1669,
    1677,  1677,  1689,  1690,  1694,  1695,  1696,  1701,  1701,  1709,
    1710,  1711,  1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,
    1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,
    1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,
    1744,  1745,  1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,
    1754,  1755,  1756,  1763,  1763,  1777,  1777,  1786,  1787,  1790,
    1791,  1792,  1799,  1799,  1814,  1814,  1828,  1829,  1832,  1833,
    1834,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,  1851,  1853,  1859,  1861,  1861,  1870,  1870,  1879,  1879,
    1888,  1890,  1890,  1899,  1909,  1909,  1922,  1923,  1928,  1929,
    1930,  1937,  1937,  1949,  1949,  1961,  1962,  1967,  1968,  1969,
    1976,  1977,  1978,  1979,  1980,  1981,  1982,  1983,  1984,  1987,
    1989,  1989,  1998,  2000,  2002,  2008,  2017,  2017,  2030,  2031,
    2034,  2035,  2036,  2041,  2041,  2051,  2051,  2061,  2062,  2063,
    2068,  2069,  2070,  2071,  2072,  2073,  2074,  2077,  2077,  2086,
    2086,  2111,  2111,  2141,  2141,  2152,  2153,  2156,  2157,  2158,
    2163,  2163,  2172,  2172,  2181,  2182,  2185,  2186,  2187,  2193,
    2194,  2195,  2196,  2197,  2198,  2199,  2200,  2201,  2202,  2203,
    2204,  2205,  2206,  2207,  2210,  2210,  2219,  2219,  2228,  2228,
    2237,  2237,  2246,  2246,  2257,  2257,  2266,  2266,  2275,  2275,
    2284,  2284,  2293,  2293,  2302,  2302,  2311,  2311,  2325,  2325,
    2336,  2337,  2343,  2343,  2354,  2355,  2356,  2361,  2361,  2371,
    2372,  2375,  2376,  2377,  2382,  2383,  2384,  2385,  2386,  2387,
    2388,  2389,  2390,  2391,  2392,  2393,  2394,  2395,  2396,  2399,
    2401,  2401,  2410,  2410,  2419,  2427,  2435,  2435,  2446,  2447,
    2448,  2453,  2454,  2455,  2456,  2457,  2460,  2460,  2469,  2469,
    2481,  2481,  2494,  2495,  2496,  2501,  2502,  2503,  2504,  2505,
    2506,  2509,  2515,  2515,  2524,  2530,  2530,  2540,  2540,  2553,
    2553,  2563,  2564,  2565,  2570,  2571,  2572,  2573,  2574,  2575,
    2576,  2577,  2578,  2579,  2580,  2581,  2582,  2583,  2584,  2585,
    2586,  2587,  2590,  2596,  2596,  2605,  2611,  2611,  2620,  2626,
    2632,  2632,  2641,  2642,  2645,  2645,  2655,  2655,  2665,  2672,
    2679,  2679,  2688,  2688,  2698,  2698,  2708,  2708,  2720,  2720,
    2732,  2732,  2742,  2743,  2744,  2750,  2751,  2754,  2754,  2765,
    2773,  2773,  2786,  2787,  2788,  2794,  2794,  2802,  2803,  2804,
    2809,  2810,  2811,  2812,  2813,  2814,  2815,  2818,  2824,  2824,
    2833,  2833,  2844,  2845,  2846,  2851,  2851,  2859,  2860,  2861,
    2866,  2867,  2868,  2869,  2870,  2873,  2873,  2882,  2888,  2894,
    2900,  2900,  2909,  2909,  2920,  2921,  2922,  2927,  2928,  2929,
    2932,  2938
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
#line 6291 "dhcp4_parser.cc"

#line 2944 "dhcp4_parser.yy"


void
isc::dhcp::Dhcp4Parser::error(const location_type& loc,
                              const std::string& what)
{
    ctx.error(loc, what);
}
