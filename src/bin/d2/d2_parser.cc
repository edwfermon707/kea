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
#define yylex   d2_parser_lex



#include "d2_parser.h"


// Unqualified %code blocks.
#line 34 "d2_parser.yy"

#include <d2/parser_context.h>

#line 52 "d2_parser.cc"


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
#if D2_PARSER_DEBUG

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

#else // !D2_PARSER_DEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !D2_PARSER_DEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 14 "d2_parser.yy"
namespace isc { namespace d2 {
#line 145 "d2_parser.cc"

  /// Build a parser object.
  D2Parser::D2Parser (isc::d2::D2ParserContext& ctx_yyarg)
#if D2_PARSER_DEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      ctx (ctx_yyarg)
  {}

  D2Parser::~D2Parser ()
  {}

  D2Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  D2Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  D2Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  D2Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  D2Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  D2Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  D2Parser::symbol_kind_type
  D2Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  D2Parser::stack_symbol_type::stack_symbol_type ()
  {}

  D2Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
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

  D2Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
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
  D2Parser::stack_symbol_type&
  D2Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
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

  D2Parser::stack_symbol_type&
  D2Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_value: // value
      case symbol_kind::S_map_value: // map_value
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
  D2Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if D2_PARSER_DEBUG
  template <typename Base>
  void
  D2Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
#line 118 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 384 "d2_parser.cc"
        break;

      case symbol_kind::S_INTEGER: // "integer"
#line 118 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < int64_t > (); }
#line 390 "d2_parser.cc"
        break;

      case symbol_kind::S_FLOAT: // "floating point"
#line 118 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < double > (); }
#line 396 "d2_parser.cc"
        break;

      case symbol_kind::S_BOOLEAN: // "boolean"
#line 118 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < bool > (); }
#line 402 "d2_parser.cc"
        break;

      case symbol_kind::S_value: // value
#line 118 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 408 "d2_parser.cc"
        break;

      case symbol_kind::S_map_value: // map_value
#line 118 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 414 "d2_parser.cc"
        break;

      case symbol_kind::S_ncr_protocol_value: // ncr_protocol_value
#line 118 "d2_parser.yy"
                 { yyoutput << yysym.value.template as < ElementPtr > (); }
#line 420 "d2_parser.cc"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  D2Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  D2Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  D2Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if D2_PARSER_DEBUG
  std::ostream&
  D2Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  D2Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  D2Parser::debug_level_type
  D2Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  D2Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // D2_PARSER_DEBUG

  D2Parser::state_type
  D2Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  D2Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  D2Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  D2Parser::operator() ()
  {
    return parse ();
  }

  int
  D2Parser::parse ()
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
#line 127 "d2_parser.yy"
                     { ctx.ctx_ = ctx.NO_KEYWORD; }
#line 695 "d2_parser.cc"
    break;

  case 4: // $@2: %empty
#line 128 "d2_parser.yy"
                         { ctx.ctx_ = ctx.CONFIG; }
#line 701 "d2_parser.cc"
    break;

  case 6: // $@3: %empty
#line 129 "d2_parser.yy"
                    { ctx.ctx_ = ctx.DHCPDDNS; }
#line 707 "d2_parser.cc"
    break;

  case 8: // $@4: %empty
#line 130 "d2_parser.yy"
                    { ctx.ctx_ = ctx.TSIG_KEY; }
#line 713 "d2_parser.cc"
    break;

  case 10: // $@5: %empty
#line 131 "d2_parser.yy"
                     { ctx.ctx_ = ctx.TSIG_KEYS; }
#line 719 "d2_parser.cc"
    break;

  case 12: // $@6: %empty
#line 132 "d2_parser.yy"
                       { ctx.ctx_ = ctx.DDNS_DOMAIN; }
#line 725 "d2_parser.cc"
    break;

  case 14: // $@7: %empty
#line 133 "d2_parser.yy"
                        { ctx.ctx_ = ctx.DDNS_DOMAINS; }
#line 731 "d2_parser.cc"
    break;

  case 16: // $@8: %empty
#line 134 "d2_parser.yy"
                      { ctx.ctx_ = ctx.DNS_SERVERS; }
#line 737 "d2_parser.cc"
    break;

  case 18: // $@9: %empty
#line 135 "d2_parser.yy"
                       { ctx.ctx_ = ctx.DNS_SERVERS; }
#line 743 "d2_parser.cc"
    break;

  case 20: // $@10: %empty
#line 136 "d2_parser.yy"
                         { ctx.ctx_ = ctx.HOOKS_LIBRARIES; }
#line 749 "d2_parser.cc"
    break;

  case 22: // value: "integer"
#line 144 "d2_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location))); }
#line 755 "d2_parser.cc"
    break;

  case 23: // value: "floating point"
#line 145 "d2_parser.yy"
             { yylhs.value.as < ElementPtr > () = ElementPtr(new DoubleElement(yystack_[0].value.as < double > (), ctx.loc2pos(yystack_[0].location))); }
#line 761 "d2_parser.cc"
    break;

  case 24: // value: "boolean"
#line 146 "d2_parser.yy"
               { yylhs.value.as < ElementPtr > () = ElementPtr(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location))); }
#line 767 "d2_parser.cc"
    break;

  case 25: // value: "constant string"
#line 147 "d2_parser.yy"
              { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location))); }
#line 773 "d2_parser.cc"
    break;

  case 26: // value: "null"
#line 148 "d2_parser.yy"
                 { yylhs.value.as < ElementPtr > () = ElementPtr(new NullElement(ctx.loc2pos(yystack_[0].location))); }
#line 779 "d2_parser.cc"
    break;

  case 27: // value: map2
#line 149 "d2_parser.yy"
            { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 785 "d2_parser.cc"
    break;

  case 28: // value: list_generic
#line 150 "d2_parser.yy"
                    { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 791 "d2_parser.cc"
    break;

  case 29: // sub_json: value
#line 153 "d2_parser.yy"
                {
    // Push back the JSON value on the stack
    ctx.stack_.push_back(yystack_[0].value.as < ElementPtr > ());
}
#line 800 "d2_parser.cc"
    break;

  case 30: // $@11: %empty
#line 158 "d2_parser.yy"
                     {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 811 "d2_parser.cc"
    break;

  case 31: // map2: "{" $@11 map_content "}"
#line 163 "d2_parser.yy"
                             {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.
}
#line 821 "d2_parser.cc"
    break;

  case 32: // map_value: map2
#line 169 "d2_parser.yy"
                { yylhs.value.as < ElementPtr > () = ctx.stack_.back(); ctx.stack_.pop_back(); }
#line 827 "d2_parser.cc"
    break;

  case 35: // not_empty_map: "constant string" ":" value
#line 176 "d2_parser.yy"
                                  {
                  // map containing a single entry
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 837 "d2_parser.cc"
    break;

  case 36: // not_empty_map: not_empty_map "," "constant string" ":" value
#line 181 "d2_parser.yy"
                                                      {
                  // map consisting of a shorter map followed by
                  // comma and string:value
                  ctx.unique(yystack_[2].value.as < std::string > (), ctx.loc2pos(yystack_[2].location));
                  ctx.stack_.back()->set(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ElementPtr > ());
                  }
#line 848 "d2_parser.cc"
    break;

  case 37: // $@12: %empty
#line 189 "d2_parser.yy"
                              {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 857 "d2_parser.cc"
    break;

  case 38: // list_generic: "[" $@12 list_content "]"
#line 192 "d2_parser.yy"
                               {
    // list parsing complete. Put any sanity checking here
}
#line 865 "d2_parser.cc"
    break;

  case 41: // not_empty_list: value
#line 200 "d2_parser.yy"
                      {
                  // List consisting of a single element.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 874 "d2_parser.cc"
    break;

  case 42: // not_empty_list: not_empty_list "," value
#line 204 "d2_parser.yy"
                                           {
                  // List ending with , and a value.
                  ctx.stack_.back()->add(yystack_[0].value.as < ElementPtr > ());
                  }
#line 883 "d2_parser.cc"
    break;

  case 43: // unknown_map_entry: "constant string" ":"
#line 215 "d2_parser.yy"
                                {
    const std::string& where = ctx.contextName();
    const std::string& keyword = yystack_[1].value.as < std::string > ();
    error(yystack_[1].location,
          "got unexpected keyword \"" + keyword + "\" in " + where + " map.");
}
#line 894 "d2_parser.cc"
    break;

  case 44: // $@13: %empty
#line 224 "d2_parser.yy"
                           {
    // This code is executed when we're about to start parsing
    // the content of the map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 905 "d2_parser.cc"
    break;

  case 45: // syntax_map: "{" $@13 global_object "}"
#line 229 "d2_parser.yy"
                               {
    // map parsing completed. If we ever want to do any wrap up
    // (maybe some sanity checking), this would be the best place
    // for it.
}
#line 915 "d2_parser.cc"
    break;

  case 46: // $@14: %empty
#line 237 "d2_parser.yy"
                        {
    ctx.unique("DhcpDdns", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("DhcpDdns", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.DHCPDDNS);
}
#line 927 "d2_parser.cc"
    break;

  case 47: // global_object: "DhcpDdns" $@14 ":" "{" dhcpddns_params "}"
#line 243 "d2_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 936 "d2_parser.cc"
    break;

  case 48: // $@15: %empty
#line 248 "d2_parser.yy"
                             {
    // Parse the dhcpddns map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 946 "d2_parser.cc"
    break;

  case 49: // sub_dhcpddns: "{" $@15 dhcpddns_params "}"
#line 252 "d2_parser.yy"
                                 {
    // parsing completed
}
#line 954 "d2_parser.cc"
    break;

  case 68: // $@16: %empty
#line 279 "d2_parser.yy"
                       {
    ctx.unique("ip-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 963 "d2_parser.cc"
    break;

  case 69: // ip_address: "ip-address" $@16 ":" "constant string"
#line 282 "d2_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-address", s);
    ctx.leave();
}
#line 973 "d2_parser.cc"
    break;

  case 70: // port: "port" ":" "integer"
#line 288 "d2_parser.yy"
                         {
    ctx.unique("port", ctx.loc2pos(yystack_[2].location));
    if (yystack_[0].value.as < int64_t > () <= 0 || yystack_[0].value.as < int64_t > () >= 65536 ) {
        error(yystack_[0].location, "port must be greater than zero but less than 65536");
    }
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("port", i);
}
#line 986 "d2_parser.cc"
    break;

  case 71: // dns_server_timeout: "dns-server-timeout" ":" "integer"
#line 297 "d2_parser.yy"
                                                     {
    ctx.unique("dns-server-timeout", ctx.loc2pos(yystack_[2].location));
    if (yystack_[0].value.as < int64_t > () <= 0) {
        error(yystack_[0].location, "dns-server-timeout must be greater than zero");
    } else {
        ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
        ctx.stack_.back()->set("dns-server-timeout", i);
    }
}
#line 1000 "d2_parser.cc"
    break;

  case 72: // dns_server_max_attempts: "dns-server-max-attempts" ":" "integer"
#line 307 "d2_parser.yy"
                                                               {
    ctx.unique("dns-server-max-attempts", ctx.loc2pos(yystack_[2].location));
    if (yystack_[0].value.as < int64_t > () <= 0) {
        error(yystack_[0].location, "dns-server-max-attempts must be greater than zero");
    } else {
        ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
        ctx.stack_.back()->set("dns-server-max-attempts", i);
    }
}
#line 1014 "d2_parser.cc"
    break;

  case 73: // $@17: %empty
#line 317 "d2_parser.yy"
                           {
    ctx.unique("ncr-protocol", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_PROTOCOL);
}
#line 1023 "d2_parser.cc"
    break;

  case 74: // ncr_protocol: "ncr-protocol" $@17 ":" ncr_protocol_value
#line 320 "d2_parser.yy"
                           {
    ctx.stack_.back()->set("ncr-protocol", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1032 "d2_parser.cc"
    break;

  case 75: // ncr_protocol_value: "UDP"
#line 326 "d2_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("UDP", ctx.loc2pos(yystack_[0].location))); }
#line 1038 "d2_parser.cc"
    break;

  case 76: // ncr_protocol_value: "TCP"
#line 327 "d2_parser.yy"
        { yylhs.value.as < ElementPtr > () = ElementPtr(new StringElement("TCP", ctx.loc2pos(yystack_[0].location))); }
#line 1044 "d2_parser.cc"
    break;

  case 77: // $@18: %empty
#line 330 "d2_parser.yy"
                       {
    ctx.unique("ncr-format", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NCR_FORMAT);
}
#line 1053 "d2_parser.cc"
    break;

  case 78: // ncr_format: "ncr-format" $@18 ":" "JSON"
#line 333 "d2_parser.yy"
             {
    ElementPtr json(new StringElement("JSON", ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ncr-format", json);
    ctx.leave();
}
#line 1063 "d2_parser.cc"
    break;

  case 79: // max_ncr_queue_size: "max-ncr-queue-size" ":" "integer"
#line 339 "d2_parser.yy"
                                                     {
    ctx.unique("max-ncr-queue-size", ctx.loc2pos(yystack_[2].location));
    if (yystack_[0].value.as < int64_t > () <= 0) {
        error(yystack_[0].location, "max-ncr-queue-size must be greater than zero");
    } else {
        ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
        ctx.stack_.back()->set("max-ncr-queue-size", i);
    }
}
#line 1077 "d2_parser.cc"
    break;

  case 80: // $@19: %empty
#line 349 "d2_parser.yy"
                           {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1085 "d2_parser.cc"
    break;

  case 81: // user_context: "user-context" $@19 ":" map_value
#line 351 "d2_parser.yy"
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
#line 1112 "d2_parser.cc"
    break;

  case 82: // $@20: %empty
#line 374 "d2_parser.yy"
                 {
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1120 "d2_parser.cc"
    break;

  case 83: // comment: "comment" $@20 ":" "constant string"
#line 376 "d2_parser.yy"
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
#line 1149 "d2_parser.cc"
    break;

  case 84: // $@21: %empty
#line 401 "d2_parser.yy"
                            {
    ctx.unique("forward-ddns", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("forward-ddns", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.FORWARD_DDNS);
}
#line 1161 "d2_parser.cc"
    break;

  case 85: // forward_ddns: "forward-ddns" $@21 ":" "{" ddns_mgr_params "}"
#line 407 "d2_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1170 "d2_parser.cc"
    break;

  case 86: // $@22: %empty
#line 412 "d2_parser.yy"
                            {
    ctx.unique("reverse-ddns", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("reverse-ddns", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.REVERSE_DDNS);
}
#line 1182 "d2_parser.cc"
    break;

  case 87: // reverse_ddns: "reverse-ddns" $@22 ":" "{" ddns_mgr_params "}"
#line 418 "d2_parser.yy"
                                                      {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1191 "d2_parser.cc"
    break;

  case 94: // $@23: %empty
#line 437 "d2_parser.yy"
                           {
    ctx.unique("ddns-domains", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ddns-domains", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.DDNS_DOMAINS);
}
#line 1203 "d2_parser.cc"
    break;

  case 95: // ddns_domains: "ddns-domains" $@23 ":" "[" ddns_domain_list "]"
#line 443 "d2_parser.yy"
                                                         {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1212 "d2_parser.cc"
    break;

  case 96: // $@24: %empty
#line 448 "d2_parser.yy"
                                  {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 1221 "d2_parser.cc"
    break;

  case 97: // sub_ddns_domains: "[" $@24 ddns_domain_list "]"
#line 451 "d2_parser.yy"
                                   {
    // parsing completed
}
#line 1229 "d2_parser.cc"
    break;

  case 102: // $@25: %empty
#line 463 "d2_parser.yy"
                            {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1239 "d2_parser.cc"
    break;

  case 103: // ddns_domain: "{" $@25 ddns_domain_params "}"
#line 467 "d2_parser.yy"
                                    {
    ctx.stack_.pop_back();
}
#line 1247 "d2_parser.cc"
    break;

  case 104: // $@26: %empty
#line 471 "d2_parser.yy"
                                {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1256 "d2_parser.cc"
    break;

  case 105: // sub_ddns_domain: "{" $@26 ddns_domain_params "}"
#line 474 "d2_parser.yy"
                                    {
    // parsing completed
}
#line 1264 "d2_parser.cc"
    break;

  case 114: // $@27: %empty
#line 491 "d2_parser.yy"
                       {
    ctx.unique("name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1273 "d2_parser.cc"
    break;

  case 115: // ddns_domain_name: "name" $@27 ":" "constant string"
#line 494 "d2_parser.yy"
               {
    if (yystack_[0].value.as < std::string > () == "") {
        error(yystack_[1].location, "Ddns domain name cannot be blank");
    }
    ElementPtr elem(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("name", name);
    ctx.leave();
}
#line 1287 "d2_parser.cc"
    break;

  case 116: // $@28: %empty
#line 504 "d2_parser.yy"
                        {
    ctx.unique("key-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1296 "d2_parser.cc"
    break;

  case 117: // ddns_key_name: "key-name" $@28 ":" "constant string"
#line 507 "d2_parser.yy"
               {
    ElementPtr elem(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("key-name", name);
    ctx.leave();
}
#line 1307 "d2_parser.cc"
    break;

  case 118: // $@29: %empty
#line 517 "d2_parser.yy"
                         {
    ctx.unique("dns-servers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("dns-servers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.DNS_SERVERS);
}
#line 1319 "d2_parser.cc"
    break;

  case 119: // dns_servers: "dns-servers" $@29 ":" "[" dns_server_list "]"
#line 523 "d2_parser.yy"
                                                        {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1328 "d2_parser.cc"
    break;

  case 120: // $@30: %empty
#line 528 "d2_parser.yy"
                                 {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 1337 "d2_parser.cc"
    break;

  case 121: // sub_dns_servers: "[" $@30 dns_server_list "]"
#line 531 "d2_parser.yy"
                                  {
    // parsing completed
}
#line 1345 "d2_parser.cc"
    break;

  case 124: // $@31: %empty
#line 539 "d2_parser.yy"
                           {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1355 "d2_parser.cc"
    break;

  case 125: // dns_server: "{" $@31 dns_server_params "}"
#line 543 "d2_parser.yy"
                                   {
    ctx.stack_.pop_back();
}
#line 1363 "d2_parser.cc"
    break;

  case 126: // $@32: %empty
#line 547 "d2_parser.yy"
                               {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1372 "d2_parser.cc"
    break;

  case 127: // sub_dns_server: "{" $@32 dns_server_params "}"
#line 550 "d2_parser.yy"
                                   {
    // parsing completed
}
#line 1380 "d2_parser.cc"
    break;

  case 137: // $@33: %empty
#line 567 "d2_parser.yy"
                              {
    ctx.unique("hostname", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1389 "d2_parser.cc"
    break;

  case 138: // dns_server_hostname: "hostname" $@33 ":" "constant string"
#line 570 "d2_parser.yy"
               {
    if (yystack_[0].value.as < std::string > () != "") {
        error(yystack_[1].location, "hostname is not yet supported");
    }
    ElementPtr elem(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hostname", name);
    ctx.leave();
}
#line 1403 "d2_parser.cc"
    break;

  case 139: // $@34: %empty
#line 580 "d2_parser.yy"
                                  {
    ctx.unique("ip-address", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1412 "d2_parser.cc"
    break;

  case 140: // dns_server_ip_address: "ip-address" $@34 ":" "constant string"
#line 583 "d2_parser.yy"
               {
    ElementPtr s(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("ip-address", s);
    ctx.leave();
}
#line 1422 "d2_parser.cc"
    break;

  case 141: // dns_server_port: "port" ":" "integer"
#line 589 "d2_parser.yy"
                                    {
    ctx.unique("port", ctx.loc2pos(yystack_[2].location));
    if (yystack_[0].value.as < int64_t > () <= 0 || yystack_[0].value.as < int64_t > () >= 65536 ) {
        error(yystack_[0].location, "port must be greater than zero but less than 65536");
    }
    ElementPtr i(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("port", i);
}
#line 1435 "d2_parser.cc"
    break;

  case 142: // $@35: %empty
#line 604 "d2_parser.yy"
                     {
    ctx.unique("tsig-keys", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("tsig-keys", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.TSIG_KEYS);
}
#line 1447 "d2_parser.cc"
    break;

  case 143: // tsig_keys: "tsig-keys" $@35 ":" "[" tsig_keys_list "]"
#line 610 "d2_parser.yy"
                                                       {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1456 "d2_parser.cc"
    break;

  case 144: // $@36: %empty
#line 615 "d2_parser.yy"
                               {
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(l);
}
#line 1465 "d2_parser.cc"
    break;

  case 145: // sub_tsig_keys: "[" $@36 tsig_keys_list "]"
#line 618 "d2_parser.yy"
                                 {
    // parsing completed
}
#line 1473 "d2_parser.cc"
    break;

  case 150: // $@37: %empty
#line 630 "d2_parser.yy"
                         {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1483 "d2_parser.cc"
    break;

  case 151: // tsig_key: "{" $@37 tsig_key_params "}"
#line 634 "d2_parser.yy"
                                 {
    ctx.stack_.pop_back();
}
#line 1491 "d2_parser.cc"
    break;

  case 152: // $@38: %empty
#line 638 "d2_parser.yy"
                             {
    // Parse tsig key list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1501 "d2_parser.cc"
    break;

  case 153: // sub_tsig_key: "{" $@38 tsig_key_params "}"
#line 642 "d2_parser.yy"
                                 {
    // parsing completed
}
#line 1509 "d2_parser.cc"
    break;

  case 163: // $@39: %empty
#line 660 "d2_parser.yy"
                    {
    ctx.unique("name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1518 "d2_parser.cc"
    break;

  case 164: // tsig_key_name: "name" $@39 ":" "constant string"
#line 663 "d2_parser.yy"
               {
    if (yystack_[0].value.as < std::string > () == "") {
        error(yystack_[1].location, "TSIG key name cannot be blank");
    }
    ElementPtr elem(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("name", name);
    ctx.leave();
}
#line 1532 "d2_parser.cc"
    break;

  case 165: // $@40: %empty
#line 673 "d2_parser.yy"
                              {
    ctx.unique("algorithm", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1541 "d2_parser.cc"
    break;

  case 166: // tsig_key_algorithm: "algorithm" $@40 ":" "constant string"
#line 676 "d2_parser.yy"
               {
    if (yystack_[0].value.as < std::string > () == "") {
        error(yystack_[1].location, "TSIG key algorithm cannot be blank");
    }
    ElementPtr elem(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("algorithm", elem);
    ctx.leave();
}
#line 1554 "d2_parser.cc"
    break;

  case 167: // tsig_key_digest_bits: "digest-bits" ":" "integer"
#line 685 "d2_parser.yy"
                                                {
    ctx.unique("digest-bits", ctx.loc2pos(yystack_[2].location));
    if (yystack_[0].value.as < int64_t > () < 0 || (yystack_[0].value.as < int64_t > () > 0  && (yystack_[0].value.as < int64_t > () % 8 != 0))) {
        error(yystack_[0].location, "TSIG key digest-bits must either be zero or a positive, multiple of eight");
    }
    ElementPtr elem(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("digest-bits", elem);
}
#line 1567 "d2_parser.cc"
    break;

  case 168: // $@41: %empty
#line 694 "d2_parser.yy"
                        {
    ctx.unique("secret", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1576 "d2_parser.cc"
    break;

  case 169: // tsig_key_secret: "secret" $@41 ":" "constant string"
#line 697 "d2_parser.yy"
               {
    if (yystack_[0].value.as < std::string > () == "") {
        error(yystack_[1].location, "TSIG key secret cannot be blank");
    }
    ElementPtr elem(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("secret", elem);
    ctx.leave();
}
#line 1589 "d2_parser.cc"
    break;

  case 170: // $@42: %empty
#line 711 "d2_parser.yy"
                               {
    ctx.unique("control-socket", ctx.loc2pos(yystack_[0].location));
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("control-socket", m);
    ctx.stack_.push_back(m);
    ctx.enter(ctx.CONTROL_SOCKET);
}
#line 1601 "d2_parser.cc"
    break;

  case 171: // control_socket: "control-socket" $@42 ":" "{" control_socket_params "}"
#line 717 "d2_parser.yy"
                                                            {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1610 "d2_parser.cc"
    break;

  case 179: // $@43: %empty
#line 733 "d2_parser.yy"
                                 {
    ctx.unique("socket-type", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1619 "d2_parser.cc"
    break;

  case 180: // control_socket_type: "socket-type" $@43 ":" "constant string"
#line 736 "d2_parser.yy"
               {
    ElementPtr stype(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-type", stype);
    ctx.leave();
}
#line 1629 "d2_parser.cc"
    break;

  case 181: // $@44: %empty
#line 742 "d2_parser.yy"
                                 {
    ctx.unique("socket-name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1638 "d2_parser.cc"
    break;

  case 182: // control_socket_name: "socket-name" $@44 ":" "constant string"
#line 745 "d2_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("socket-name", name);
    ctx.leave();
}
#line 1648 "d2_parser.cc"
    break;

  case 183: // $@45: %empty
#line 753 "d2_parser.yy"
                                 {
    ctx.unique("hooks-libraries", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("hooks-libraries", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.HOOKS_LIBRARIES);
}
#line 1660 "d2_parser.cc"
    break;

  case 184: // hooks_libraries: "hooks-libraries" $@45 ":" "[" hooks_libraries_list "]"
#line 759 "d2_parser.yy"
                                                             {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1669 "d2_parser.cc"
    break;

  case 189: // $@46: %empty
#line 772 "d2_parser.yy"
                              {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1679 "d2_parser.cc"
    break;

  case 190: // hooks_library: "{" $@46 hooks_params "}"
#line 776 "d2_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    ctx.stack_.pop_back();
}
#line 1689 "d2_parser.cc"
    break;

  case 191: // $@47: %empty
#line 782 "d2_parser.yy"
                                  {
    // Parse the hooks-libraries list entry map
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.push_back(m);
}
#line 1699 "d2_parser.cc"
    break;

  case 192: // sub_hooks_library: "{" $@47 hooks_params "}"
#line 786 "d2_parser.yy"
                              {
    // The library hooks parameter is required
    ctx.require("library", ctx.loc2pos(yystack_[3].location), ctx.loc2pos(yystack_[0].location));
    // parsing completed
}
#line 1709 "d2_parser.cc"
    break;

  case 198: // $@48: %empty
#line 801 "d2_parser.yy"
                 {
    ctx.unique("library", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1718 "d2_parser.cc"
    break;

  case 199: // library: "library" $@48 ":" "constant string"
#line 804 "d2_parser.yy"
               {
    ElementPtr lib(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("library", lib);
    ctx.leave();
}
#line 1728 "d2_parser.cc"
    break;

  case 200: // $@49: %empty
#line 810 "d2_parser.yy"
                       {
    ctx.unique("parameters", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1737 "d2_parser.cc"
    break;

  case 201: // parameters: "parameters" $@49 ":" map_value
#line 813 "d2_parser.yy"
                  {
    ctx.stack_.back()->set("parameters", yystack_[0].value.as < ElementPtr > ());
    ctx.leave();
}
#line 1746 "d2_parser.cc"
    break;

  case 202: // $@50: %empty
#line 820 "d2_parser.yy"
                 {
    ctx.unique("loggers", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("loggers", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.LOGGERS);
}
#line 1758 "d2_parser.cc"
    break;

  case 203: // loggers: "loggers" $@50 ":" "[" loggers_entries "]"
#line 826 "d2_parser.yy"
                                                         {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1767 "d2_parser.cc"
    break;

  case 206: // $@51: %empty
#line 838 "d2_parser.yy"
                             {
    ElementPtr l(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(l);
    ctx.stack_.push_back(l);
}
#line 1777 "d2_parser.cc"
    break;

  case 207: // logger_entry: "{" $@51 logger_params "}"
#line 842 "d2_parser.yy"
                               {
    ctx.stack_.pop_back();
}
#line 1785 "d2_parser.cc"
    break;

  case 217: // $@52: %empty
#line 859 "d2_parser.yy"
           {
    ctx.unique("name", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1794 "d2_parser.cc"
    break;

  case 218: // name: "name" $@52 ":" "constant string"
#line 862 "d2_parser.yy"
               {
    ElementPtr name(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("name", name);
    ctx.leave();
}
#line 1804 "d2_parser.cc"
    break;

  case 219: // debuglevel: "debuglevel" ":" "integer"
#line 868 "d2_parser.yy"
                                     {
    ctx.unique("debuglevel", ctx.loc2pos(yystack_[2].location));
    ElementPtr dl(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("debuglevel", dl);
}
#line 1814 "d2_parser.cc"
    break;

  case 220: // $@53: %empty
#line 874 "d2_parser.yy"
                   {
    ctx.unique("severity", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1823 "d2_parser.cc"
    break;

  case 221: // severity: "severity" $@53 ":" "constant string"
#line 877 "d2_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("severity", sev);
    ctx.leave();
}
#line 1833 "d2_parser.cc"
    break;

  case 222: // $@54: %empty
#line 883 "d2_parser.yy"
                                    {
    ctx.unique("output_options", ctx.loc2pos(yystack_[0].location));
    ElementPtr l(new ListElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output_options", l);
    ctx.stack_.push_back(l);
    ctx.enter(ctx.OUTPUT_OPTIONS);
}
#line 1845 "d2_parser.cc"
    break;

  case 223: // output_options_list: "output_options" $@54 ":" "[" output_options_list_content "]"
#line 889 "d2_parser.yy"
                                                                    {
    ctx.stack_.pop_back();
    ctx.leave();
}
#line 1854 "d2_parser.cc"
    break;

  case 226: // $@55: %empty
#line 898 "d2_parser.yy"
                             {
    ElementPtr m(new MapElement(ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->add(m);
    ctx.stack_.push_back(m);
}
#line 1864 "d2_parser.cc"
    break;

  case 227: // output_entry: "{" $@55 output_params_list "}"
#line 902 "d2_parser.yy"
                                    {
    ctx.stack_.pop_back();
}
#line 1872 "d2_parser.cc"
    break;

  case 235: // $@56: %empty
#line 917 "d2_parser.yy"
               {
    ctx.unique("output", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1881 "d2_parser.cc"
    break;

  case 236: // output: "output" $@56 ":" "constant string"
#line 920 "d2_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("output", sev);
    ctx.leave();
}
#line 1891 "d2_parser.cc"
    break;

  case 237: // flush: "flush" ":" "boolean"
#line 926 "d2_parser.yy"
                           {
    ctx.unique("flush", ctx.loc2pos(yystack_[2].location));
    ElementPtr flush(new BoolElement(yystack_[0].value.as < bool > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("flush", flush);
}
#line 1901 "d2_parser.cc"
    break;

  case 238: // maxsize: "maxsize" ":" "integer"
#line 932 "d2_parser.yy"
                               {
    ctx.unique("maxsize", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxsize(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxsize", maxsize);
}
#line 1911 "d2_parser.cc"
    break;

  case 239: // maxver: "maxver" ":" "integer"
#line 938 "d2_parser.yy"
                             {
    ctx.unique("maxver", ctx.loc2pos(yystack_[2].location));
    ElementPtr maxver(new IntElement(yystack_[0].value.as < int64_t > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("maxver", maxver);
}
#line 1921 "d2_parser.cc"
    break;

  case 240: // $@57: %empty
#line 944 "d2_parser.yy"
                 {
    ctx.unique("pattern", ctx.loc2pos(yystack_[0].location));
    ctx.enter(ctx.NO_KEYWORD);
}
#line 1930 "d2_parser.cc"
    break;

  case 241: // pattern: "pattern" $@57 ":" "constant string"
#line 947 "d2_parser.yy"
               {
    ElementPtr sev(new StringElement(yystack_[0].value.as < std::string > (), ctx.loc2pos(yystack_[0].location)));
    ctx.stack_.back()->set("pattern", sev);
    ctx.leave();
}
#line 1940 "d2_parser.cc"
    break;


#line 1944 "d2_parser.cc"

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
  D2Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  D2Parser::yytnamerr_ (const char *yystr)
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
  D2Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // D2Parser::context.
  D2Parser::context::context (const D2Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  D2Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
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
  D2Parser::yy_syntax_error_arguments_ (const context& yyctx,
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
  D2Parser::yysyntax_error_ (const context& yyctx) const
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


  const short D2Parser::yypact_ninf_ = -215;

  const signed char D2Parser::yytable_ninf_ = -1;

  const short
  D2Parser::yypact_[] =
  {
      43,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,    26,     8,    25,    41,    67,    18,    96,    28,   130,
      82,   131,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,     8,    86,   129,     7,    31,   140,    51,   150,
      23,   151,    27,  -215,   163,   156,   166,   164,   168,  -215,
     165,  -215,   170,   171,   172,  -215,  -215,   173,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,   174,  -215,    73,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,   175,  -215,  -215,  -215,
    -215,  -215,    77,  -215,  -215,  -215,  -215,  -215,  -215,   176,
     177,  -215,  -215,  -215,  -215,  -215,  -215,  -215,    80,  -215,
    -215,  -215,  -215,  -215,   178,   180,  -215,  -215,   181,  -215,
    -215,  -215,  -215,  -215,    81,  -215,  -215,  -215,  -215,  -215,
      44,  -215,  -215,  -215,  -215,   101,  -215,  -215,  -215,  -215,
       8,     8,  -215,   127,   183,  -215,   184,   132,   133,   134,
     185,   186,   135,   187,   192,   193,   194,   195,   196,   197,
     198,  -215,     7,  -215,   199,   144,   201,   202,    31,  -215,
      31,  -215,   140,   203,   204,   207,    51,  -215,    51,  -215,
     150,   211,   157,   212,    23,  -215,    23,   151,  -215,   214,
     215,   -30,  -215,  -215,  -215,   216,   218,   167,  -215,  -215,
    -215,    98,   208,  -215,   221,   179,   222,   223,   217,   224,
     227,   228,  -215,   182,  -215,   188,   189,  -215,   108,  -215,
     190,   229,   191,  -215,   109,  -215,   200,  -215,   213,  -215,
     110,  -215,   219,   221,  -215,     8,     7,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,    -1,    -1,   140,    20,   230,
     232,  -215,  -215,  -215,  -215,  -215,   151,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,   118,  -215,  -215,   119,  -215,
    -215,  -215,   120,   234,  -215,  -215,  -215,  -215,  -215,   121,
    -215,  -215,  -215,  -215,   236,   220,  -215,  -215,   160,  -215,
     161,  -215,   231,    -1,  -215,  -215,  -215,   239,   240,    20,
    -215,    27,  -215,   230,    16,   232,  -215,  -215,   241,  -215,
     225,   226,  -215,   122,  -215,  -215,  -215,   247,  -215,  -215,
    -215,  -215,   128,  -215,  -215,  -215,  -215,  -215,  -215,   150,
    -215,  -215,  -215,   248,   249,   206,   250,    16,  -215,   252,
     233,   251,  -215,   235,  -215,  -215,  -215,   238,  -215,  -215,
     162,  -215,    60,   238,  -215,  -215,   256,   257,   258,  -215,
     153,  -215,  -215,  -215,  -215,  -215,  -215,  -215,   263,   159,
     210,   237,   267,    60,  -215,   244,  -215,  -215,  -215,   245,
    -215,  -215,  -215
  };

  const unsigned char
  D2Parser::yydefact_[] =
  {
       0,     2,     4,     6,     8,    10,    12,    14,    16,    18,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,    37,    30,    26,    25,    22,    23,    24,
      29,     3,    27,    28,    44,     5,    48,     7,   152,     9,
     144,    11,   104,    13,    96,    15,   126,    17,   120,    19,
     191,    21,    39,    33,     0,     0,     0,   146,     0,    98,
       0,     0,     0,    41,     0,    40,     0,     0,    34,    46,
       0,    68,     0,     0,     0,    73,    77,     0,    80,    82,
      84,    86,   142,   170,   183,   202,     0,    67,     0,    50,
      52,    53,    54,    55,    56,    57,    58,    65,    66,    59,
      60,    61,    62,    63,    64,   165,     0,   168,   163,   162,
     160,   161,     0,   154,   156,   157,   158,   159,   150,     0,
     147,   148,   116,   118,   114,   113,   111,   112,     0,   106,
     108,   109,   110,   102,     0,    99,   100,   139,     0,   137,
     136,   134,   135,   133,     0,   128,   130,   131,   132,   124,
       0,   122,   198,   200,   195,     0,   193,   196,   197,    38,
       0,     0,    31,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,     0,    49,     0,     0,     0,     0,     0,   153,
       0,   145,     0,     0,     0,     0,     0,   105,     0,    97,
       0,     0,     0,     0,     0,   127,     0,     0,   121,     0,
       0,     0,   192,    42,    35,     0,     0,     0,    70,    71,
      72,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,   167,     0,     0,   155,     0,   149,
       0,     0,     0,   107,     0,   101,     0,   141,     0,   129,
       0,   123,     0,     0,   194,     0,     0,    69,    75,    76,
      74,    78,    32,    81,    83,    88,    88,   146,     0,   185,
       0,   166,   169,   164,   151,   117,     0,   115,   103,   140,
     138,   125,   199,   201,    36,     0,    94,    93,     0,    89,
      90,    92,     0,     0,   179,   181,   178,   176,   177,     0,
     172,   174,   175,   189,     0,   186,   187,   206,     0,   204,
       0,    47,     0,     0,    85,    87,   143,     0,     0,     0,
     171,     0,   184,     0,     0,     0,   203,   119,     0,    91,
       0,     0,   173,     0,   188,   217,   222,     0,   220,   216,
     214,   215,     0,   208,   210,   212,   213,   211,   205,    98,
     180,   182,   190,     0,     0,     0,     0,     0,   207,     0,
       0,     0,   219,     0,   209,    95,   218,     0,   221,   226,
       0,   224,     0,     0,   223,   235,     0,     0,     0,   240,
       0,   228,   230,   231,   232,   233,   234,   225,     0,     0,
       0,     0,     0,     0,   227,     0,   237,   238,   239,     0,
     229,   236,   241
  };

  const short
  D2Parser::yypgoto_[] =
  {
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,   -41,  -215,  -214,  -215,   -72,  -215,  -215,  -215,
    -215,  -215,  -215,   -56,  -215,  -215,  -215,  -215,  -215,  -215,
     -20,    91,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,   -55,  -215,   -44,  -215,  -215,  -215,  -215,
    -215,   -11,  -215,   -39,  -215,  -215,  -215,  -215,   -73,  -215,
      79,  -215,  -215,  -215,    83,    87,  -215,  -215,   -51,  -215,
    -215,  -215,  -215,  -215,     1,    75,  -215,  -215,  -215,    84,
      85,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
      19,  -215,    95,  -215,  -215,  -215,   103,   100,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,   -28,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,   -27,  -215,  -215,
    -215,   -26,    88,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
     -25,  -215,  -215,   -59,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,   -68,  -215,  -215,   -87,  -215,  -215,  -215,  -215,
    -215,  -215,  -215
  };

  const short
  D2Parser::yydefgoto_[] =
  {
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    30,    31,    32,    53,   263,    67,    68,    33,
      52,    64,    65,    87,    35,    54,    70,   164,    37,    55,
      88,    89,    90,   166,    91,    92,    93,    94,   170,   260,
      95,   171,    96,    97,   173,    98,   174,    99,   175,   100,
     176,   288,   289,   290,   291,   312,    45,    59,   134,   135,
     136,   198,    43,    58,   128,   129,   130,   195,   131,   193,
     132,   194,    49,    61,   150,   151,   206,    47,    60,   144,
     145,   146,   203,   147,   201,   148,   101,   177,    41,    57,
     119,   120,   121,   190,    39,    56,   112,   113,   114,   187,
     115,   184,   116,   117,   186,   102,   178,   299,   300,   301,
     317,   302,   318,   103,   179,   304,   305,   306,   321,    51,
      62,   155,   156,   157,   209,   158,   210,   104,   180,   308,
     309,   324,   342,   343,   344,   353,   345,   346,   356,   347,
     354,   370,   371,   372,   380,   381,   382,   388,   383,   384,
     385,   386,   392
  };

  const short
  D2Parser::yytable_[] =
  {
     109,   110,   125,   126,   140,   141,   154,   152,   153,   143,
     262,    63,   111,    23,   127,    24,   142,    25,    71,    72,
      73,    74,    75,    40,   286,    76,    22,    77,    78,    79,
      80,    81,    34,    44,   137,   138,    82,    78,    79,   262,
      83,    78,    79,    84,    78,    79,    85,   207,    36,   122,
     208,   139,    78,    79,   294,   295,   335,   336,    86,   337,
     338,   105,   106,   107,   152,   153,    86,    26,    27,    28,
      29,   108,    78,    79,    38,    86,   182,   122,   123,    86,
     188,   183,    86,   196,   204,   189,    86,    48,   197,   205,
      86,   124,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,   375,    42,   211,   376,   377,   378,   379,   212,
      86,   188,   196,   204,   258,   259,   274,   278,   281,   213,
     214,   182,   313,   313,   319,   211,   311,   314,   315,   320,
     352,   357,   109,   110,   109,   110,   358,    46,    50,    69,
     125,   126,   125,   126,   111,    66,   111,   118,   140,   141,
     140,   141,   127,   143,   127,   143,   393,   133,   149,   160,
     142,   394,   142,   325,   207,   373,   326,   327,   374,   159,
     161,   163,   162,   165,   167,   168,   169,   172,   181,   185,
     192,   283,   191,   200,   199,   202,   215,   216,   217,   221,
     222,   224,   218,   219,   220,   223,   225,   226,   227,   228,
     229,   230,   231,   233,   234,   235,   236,   240,   241,   287,
     287,   242,   296,   297,   284,   246,   248,   247,   252,   253,
     255,   396,   267,   323,   298,   256,   257,   261,    24,   265,
     266,   268,   269,   270,   276,   328,   285,   303,   264,   307,
     316,   271,   322,   330,   331,   369,   349,   272,   273,   275,
     277,   355,   360,   361,   363,   292,   367,   287,   365,   279,
     389,   390,   391,   296,   297,   154,   362,   395,   339,   340,
     397,   399,   280,   232,   329,   298,   359,   310,   282,   245,
     341,   244,   251,   243,   350,   351,   293,   239,   237,   249,
     250,   332,   366,   238,   368,   333,   334,   398,   364,   254,
     348,   339,   340,   401,   402,   387,   400,     0,     0,     0,
       0,     0,     0,   341
  };

  const short
  D2Parser::yycheck_[] =
  {
      56,    56,    58,    58,    60,    60,    62,    37,    38,    60,
     224,    52,    56,     5,    58,     7,    60,     9,    11,    12,
      13,    14,    15,     5,    25,    18,     0,    20,    21,    22,
      23,    24,     7,     5,    11,    12,    29,    21,    22,   253,
      33,    21,    22,    36,    21,    22,    39,     3,     7,    26,
       6,    28,    21,    22,    34,    35,    40,    41,    59,    43,
      44,    30,    31,    32,    37,    38,    59,    59,    60,    61,
      62,    40,    21,    22,     7,    59,     3,    26,    27,    59,
       3,     8,    59,     3,     3,     8,    59,     5,     8,     8,
      59,    40,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    42,     7,     3,    45,    46,    47,    48,     8,
      59,     3,     3,     3,    16,    17,     8,     8,     8,   160,
     161,     3,     3,     3,     3,     3,     8,     8,     8,     8,
       8,     3,   188,   188,   190,   190,     8,     7,     7,    10,
     196,   196,   198,   198,   188,    59,   190,     7,   204,   204,
     206,   206,   196,   204,   198,   206,     3,     7,     7,     3,
     204,     8,   206,     3,     3,     3,     6,     6,     6,     6,
       4,     3,     8,     8,     4,     4,     4,     4,     4,     4,
       3,   253,     6,     3,     6,     4,    59,     4,     4,     4,
       4,     4,    60,    60,    60,    60,     4,     4,     4,     4,
       4,     4,     4,     4,    60,     4,     4,     4,     4,   265,
     266,     4,   268,   268,   255,     4,     4,    60,     4,     4,
       4,    62,     5,     3,   268,     7,    59,    19,     7,     7,
       7,     7,     5,     5,     5,     4,   256,     7,    59,     7,
       6,    59,     6,     4,     4,     7,     5,    59,    59,    59,
      59,     4,     4,     4,     4,   266,     5,   313,     6,    59,
       4,     4,     4,   319,   319,   321,    60,     4,   324,   324,
      60,     4,    59,   182,   313,   319,   349,   276,    59,   200,
     324,   198,   207,   196,    59,    59,   267,   192,   188,   204,
     206,   319,    59,   190,    59,   321,   323,    60,   357,   211,
     325,   357,   357,    59,    59,   373,   393,    -1,    -1,    -1,
      -1,    -1,    -1,   357
  };

  const unsigned char
  D2Parser::yystos_[] =
  {
       0,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     5,     7,     9,    59,    60,    61,    62,
      75,    76,    77,    82,     7,    87,     7,    91,     7,   157,
       5,   151,     7,   125,     5,   119,     7,   140,     5,   135,
       7,   182,    83,    78,    88,    92,   158,   152,   126,   120,
     141,   136,   183,    75,    84,    85,    59,    80,    81,    10,
      89,    11,    12,    13,    14,    15,    18,    20,    21,    22,
      23,    24,    29,    33,    36,    39,    59,    86,    93,    94,
      95,    97,    98,    99,   100,   103,   105,   106,   108,   110,
     112,   149,   168,   176,   190,    30,    31,    32,    40,    86,
     106,   108,   159,   160,   161,   163,   165,   166,     7,   153,
     154,   155,    26,    27,    40,    86,   106,   108,   127,   128,
     129,   131,   133,     7,   121,   122,   123,    11,    12,    28,
      86,   106,   108,   131,   142,   143,   144,   146,   148,     7,
     137,   138,    37,    38,    86,   184,   185,   186,   188,     6,
       3,     4,     8,     3,    90,     8,    96,     4,     4,     4,
     101,   104,     4,   107,   109,   111,   113,   150,   169,   177,
     191,     4,     3,     8,   164,     4,   167,   162,     3,     8,
     156,     6,     3,   132,   134,   130,     3,     8,   124,     6,
       3,   147,     4,   145,     3,     8,   139,     3,     6,   187,
     189,     3,     8,    75,    75,    59,     4,     4,    60,    60,
      60,     4,     4,    60,     4,     4,     4,     4,     4,     4,
       4,     4,    94,     4,    60,     4,     4,   160,   159,   155,
       4,     4,     4,   128,   127,   123,     4,    60,     4,   143,
     142,   138,     4,     4,   185,     4,     7,    59,    16,    17,
     102,    19,    77,    79,    59,     7,     7,     5,     7,     5,
       5,    59,    59,    59,     8,    59,     5,    59,     8,    59,
      59,     8,    59,    79,    75,    93,    25,    86,   114,   115,
     116,   117,   114,   153,    34,    35,    86,   106,   108,   170,
     171,   172,   174,     7,   178,   179,   180,     7,   192,   193,
     137,     8,   118,     3,     8,     8,     6,   173,   175,     3,
       8,   181,     6,     3,   194,     3,     6,     6,     4,   116,
       4,     4,   171,   184,   180,    40,    41,    43,    44,    86,
     106,   108,   195,   196,   197,   199,   200,   202,   193,     5,
      59,    59,     8,   198,   203,     4,   201,     3,     8,   121,
       4,     4,    60,     4,   196,     6,    59,     5,    59,     7,
     204,   205,   206,     3,     6,    42,    45,    46,    47,    48,
     207,   208,   209,   211,   212,   213,   214,   205,   210,     4,
       4,     4,   215,     3,     8,     4,    62,    60,    60,     4,
     208,    59,    59
  };

  const unsigned char
  D2Parser::yyr1_[] =
  {
       0,    63,    65,    64,    66,    64,    67,    64,    68,    64,
      69,    64,    70,    64,    71,    64,    72,    64,    73,    64,
      74,    64,    75,    75,    75,    75,    75,    75,    75,    76,
      78,    77,    79,    80,    80,    81,    81,    83,    82,    84,
      84,    85,    85,    86,    88,    87,    90,    89,    92,    91,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    96,    95,
      97,    98,    99,   101,   100,   102,   102,   104,   103,   105,
     107,   106,   109,   108,   111,   110,   113,   112,   114,   114,
     115,   115,   116,   116,   118,   117,   120,   119,   121,   121,
     122,   122,   124,   123,   126,   125,   127,   127,   128,   128,
     128,   128,   128,   128,   130,   129,   132,   131,   134,   133,
     136,   135,   137,   137,   139,   138,   141,   140,   142,   142,
     143,   143,   143,   143,   143,   143,   143,   145,   144,   147,
     146,   148,   150,   149,   152,   151,   153,   153,   154,   154,
     156,   155,   158,   157,   159,   159,   160,   160,   160,   160,
     160,   160,   160,   162,   161,   164,   163,   165,   167,   166,
     169,   168,   170,   170,   171,   171,   171,   171,   171,   173,
     172,   175,   174,   177,   176,   178,   178,   179,   179,   181,
     180,   183,   182,   184,   184,   184,   185,   185,   187,   186,
     189,   188,   191,   190,   192,   192,   194,   193,   195,   195,
     196,   196,   196,   196,   196,   196,   196,   198,   197,   199,
     201,   200,   203,   202,   204,   204,   206,   205,   207,   207,
     208,   208,   208,   208,   208,   210,   209,   211,   212,   213,
     215,   214
  };

  const signed char
  D2Parser::yyr2_[] =
  {
       0,     2,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     4,     1,     0,     1,     3,     5,     0,     4,     0,
       1,     1,     3,     2,     0,     4,     0,     6,     0,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       3,     3,     3,     0,     4,     1,     1,     0,     4,     3,
       0,     4,     0,     4,     0,     6,     0,     6,     0,     1,
       1,     3,     1,     1,     0,     6,     0,     4,     0,     1,
       1,     3,     0,     4,     0,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     0,     4,     0,     4,     0,     6,
       0,     4,     1,     3,     0,     4,     0,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     3,     0,     6,     0,     4,     0,     1,     1,     3,
       0,     4,     0,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     4,     3,     0,     4,
       0,     6,     1,     3,     1,     1,     1,     1,     1,     0,
       4,     0,     4,     0,     6,     0,     1,     1,     3,     0,
       4,     0,     4,     1,     3,     1,     1,     1,     0,     4,
       0,     4,     0,     6,     1,     3,     0,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     3,
       0,     4,     0,     6,     1,     3,     0,     4,     1,     3,
       1,     1,     1,     1,     1,     0,     4,     3,     3,     3,
       0,     4
  };


#if D2_PARSER_DEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const D2Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\",\"", "\":\"",
  "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\"null\"", "\"DhcpDdns\"",
  "\"ip-address\"", "\"port\"", "\"dns-server-timeout\"",
  "\"dns-server-max-attempts\"", "\"ncr-protocol\"", "\"UDP\"", "\"TCP\"",
  "\"ncr-format\"", "\"JSON\"", "\"max-ncr-queue-size\"",
  "\"user-context\"", "\"comment\"", "\"forward-ddns\"",
  "\"reverse-ddns\"", "\"ddns-domains\"", "\"key-name\"",
  "\"dns-servers\"", "\"hostname\"", "\"tsig-keys\"", "\"algorithm\"",
  "\"digest-bits\"", "\"secret\"", "\"control-socket\"", "\"socket-type\"",
  "\"socket-name\"", "\"hooks-libraries\"", "\"library\"",
  "\"parameters\"", "\"loggers\"", "\"name\"", "\"output_options\"",
  "\"output\"", "\"debuglevel\"", "\"severity\"", "\"flush\"",
  "\"maxsize\"", "\"maxver\"", "\"pattern\"", "TOPLEVEL_JSON",
  "TOPLEVEL_DHCPDDNS", "SUB_DHCPDDNS", "SUB_TSIG_KEY", "SUB_TSIG_KEYS",
  "SUB_DDNS_DOMAIN", "SUB_DDNS_DOMAINS", "SUB_DNS_SERVER",
  "SUB_DNS_SERVERS", "SUB_HOOKS_LIBRARY", "\"constant string\"",
  "\"integer\"", "\"floating point\"", "\"boolean\"", "$accept", "start",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "value", "sub_json", "map2", "$@11", "map_value", "map_content",
  "not_empty_map", "list_generic", "$@12", "list_content",
  "not_empty_list", "unknown_map_entry", "syntax_map", "$@13",
  "global_object", "$@14", "sub_dhcpddns", "$@15", "dhcpddns_params",
  "dhcpddns_param", "ip_address", "$@16", "port", "dns_server_timeout",
  "dns_server_max_attempts", "ncr_protocol", "$@17", "ncr_protocol_value",
  "ncr_format", "$@18", "max_ncr_queue_size", "user_context", "$@19",
  "comment", "$@20", "forward_ddns", "$@21", "reverse_ddns", "$@22",
  "ddns_mgr_params", "not_empty_ddns_mgr_params", "ddns_mgr_param",
  "ddns_domains", "$@23", "sub_ddns_domains", "$@24", "ddns_domain_list",
  "not_empty_ddns_domain_list", "ddns_domain", "$@25", "sub_ddns_domain",
  "$@26", "ddns_domain_params", "ddns_domain_param", "ddns_domain_name",
  "$@27", "ddns_key_name", "$@28", "dns_servers", "$@29",
  "sub_dns_servers", "$@30", "dns_server_list", "dns_server", "$@31",
  "sub_dns_server", "$@32", "dns_server_params", "dns_server_param",
  "dns_server_hostname", "$@33", "dns_server_ip_address", "$@34",
  "dns_server_port", "tsig_keys", "$@35", "sub_tsig_keys", "$@36",
  "tsig_keys_list", "not_empty_tsig_keys_list", "tsig_key", "$@37",
  "sub_tsig_key", "$@38", "tsig_key_params", "tsig_key_param",
  "tsig_key_name", "$@39", "tsig_key_algorithm", "$@40",
  "tsig_key_digest_bits", "tsig_key_secret", "$@41", "control_socket",
  "$@42", "control_socket_params", "control_socket_param",
  "control_socket_type", "$@43", "control_socket_name", "$@44",
  "hooks_libraries", "$@45", "hooks_libraries_list",
  "not_empty_hooks_libraries_list", "hooks_library", "$@46",
  "sub_hooks_library", "$@47", "hooks_params", "hooks_param", "library",
  "$@48", "parameters", "$@49", "loggers", "$@50", "loggers_entries",
  "logger_entry", "$@51", "logger_params", "logger_param", "name", "$@52",
  "debuglevel", "severity", "$@53", "output_options_list", "$@54",
  "output_options_list_content", "output_entry", "$@55",
  "output_params_list", "output_params", "output", "$@56", "flush",
  "maxsize", "maxver", "pattern", "$@57", YY_NULLPTR
  };
#endif


#if D2_PARSER_DEBUG
  const short
  D2Parser::yyrline_[] =
  {
       0,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   144,   145,   146,   147,   148,   149,   150,   153,
     158,   158,   169,   172,   173,   176,   181,   189,   189,   196,
     197,   200,   204,   215,   224,   224,   237,   237,   248,   248,
     256,   257,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   279,   279,
     288,   297,   307,   317,   317,   326,   327,   330,   330,   339,
     349,   349,   374,   374,   401,   401,   412,   412,   423,   424,
     427,   428,   431,   432,   437,   437,   448,   448,   455,   456,
     459,   460,   463,   463,   471,   471,   478,   479,   482,   483,
     484,   485,   486,   487,   491,   491,   504,   504,   517,   517,
     528,   528,   535,   536,   539,   539,   547,   547,   554,   555,
     558,   559,   560,   561,   562,   563,   564,   567,   567,   580,
     580,   589,   604,   604,   615,   615,   622,   623,   626,   627,
     630,   630,   638,   638,   647,   648,   651,   652,   653,   654,
     655,   656,   657,   660,   660,   673,   673,   685,   694,   694,
     711,   711,   722,   723,   726,   727,   728,   729,   730,   733,
     733,   742,   742,   753,   753,   764,   765,   768,   769,   772,
     772,   782,   782,   792,   793,   794,   797,   798,   801,   801,
     810,   810,   820,   820,   833,   834,   838,   838,   846,   847,
     850,   851,   852,   853,   854,   855,   856,   859,   859,   868,
     874,   874,   883,   883,   894,   895,   898,   898,   906,   907,
     910,   911,   912,   913,   914,   917,   917,   926,   932,   938,
     944,   944
  };

  void
  D2Parser::yy_stack_print_ () const
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
  D2Parser::yy_reduce_print_ (int yyrule) const
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
#endif // D2_PARSER_DEBUG


#line 14 "d2_parser.yy"
} } // isc::d2
#line 2736 "d2_parser.cc"

#line 953 "d2_parser.yy"


void
isc::d2::D2Parser::error(const location_type& loc,
                              const std::string& what)
{
    ctx.error(loc, what);
}
