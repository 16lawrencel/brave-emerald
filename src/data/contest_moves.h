const struct ContestMove gContestMoves[MOVES_COUNT] =
{
    [MOVE_NONE] = {0},

    [MOVE_POUND] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_POUND,
        .comboMoves = {0},
    },

    [MOVE_KARATECHOP] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_DOUBLESLAP] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_POUND},
    },

    [MOVE_COMETPUNCH] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_MEGAPUNCH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
    },

    [MOVE_PAYDAY] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FIREPUNCH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_FIRE_PUNCH,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_THUNDER_PUNCH, COMBO_STARTER_ICE_PUNCH},
    },

    [MOVE_ICEPUNCH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_ICE_PUNCH,
        .comboMoves = {COMBO_STARTER_THUNDER_PUNCH, COMBO_STARTER_FIRE_PUNCH},
    },

    [MOVE_THUNDERPUNCH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_THUNDER_PUNCH,
        .comboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_FIRE_PUNCH, COMBO_STARTER_ICE_PUNCH},
    },

    [MOVE_SCRATCH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SCRATCH,
        .comboMoves = {COMBO_STARTER_LEER},
    },

    [MOVE_VICEGRIP] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_VICE_GRIP,
        .comboMoves = {0},
    },

    [MOVE_GUILLOTINE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_VICE_GRIP},
    },

    [MOVE_RAZORWIND] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SWORDSDANCE] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_SWORDS_DANCE,
        .comboMoves = {0},
    },

    [MOVE_CUT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWORDS_DANCE},
    },

    [MOVE_GUST] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_WINGATTACK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_WHIRLWIND] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FLY] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_BIND] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_VICE_GRIP},
    },

    [MOVE_SLAM] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_POUND},
    },

    [MOVE_VINEWHIP] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_STOMP] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,{0, COMBO_STARTER_LEER},
    },

    [MOVE_DOUBLEKICK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_MEGAKICK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
    },

    [MOVE_JUMPKICK] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_MIND_READER},
    },

    [MOVE_ROLLINGKICK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SANDATTACK] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_SAND_ATTACK,
        .comboMoves = {COMBO_STARTER_MUD_SLAP, COMBO_STARTER_SANDSTORM},
    },

    [MOVE_HEADBUTT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_HORNATTACK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_HORN_ATTACK,
        .comboMoves = {COMBO_STARTER_LEER},
    },

    [MOVE_FURYATTACK] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HORN_ATTACK, COMBO_STARTER_PECK},
    },

    [MOVE_HORNDRILL] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HORN_ATTACK},
    },

    [MOVE_TACKLE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_LEER, COMBO_STARTER_HARDEN},
    },

    [MOVE_BODYSLAM] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_WRAP] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_TAKEDOWN] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN},
    },

    [MOVE_THRASH] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAGE},
    },

    [MOVE_DOUBLEEDGE] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_HARDEN},
    },

    [MOVE_TAILWHIP] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARM},
    },

    [MOVE_POISONSTING] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_TWINEEDLE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_PINMISSILE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_LEER] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_LEER,
        .comboMoves = {COMBO_STARTER_RAGE, COMBO_STARTER_SCARY_FACE},
    },

    [MOVE_BITE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_LEER, COMBO_STARTER_SCARY_FACE},
    },

    [MOVE_GROWL] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARM},
    },

    [MOVE_ROAR] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SING] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_SING,
        .comboMoves = {0},
    },

    [MOVE_SUPERSONIC] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SONICBOOM] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_DISABLE] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_ACID] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_EMBER] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_FLAMETHROWER] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_MIST] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_WATERGUN] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_WATER_SPORT, COMBO_STARTER_MUD_SPORT},
    },

    [MOVE_HYDROPUMP] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_SURF] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_SURF,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_DIVE},
    },

    [MOVE_ICEBEAM] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_BLIZZARD] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_POWDER_SNOW, COMBO_STARTER_HAIL},
    },

    [MOVE_PSYBEAM] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_BUBBLEBEAM] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_AURORABEAM] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_HYPERBEAM] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_PECK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_PECK,
        .comboMoves = {0},
    },

    [MOVE_DRILLPECK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_PECK},
    },

    [MOVE_SUBMISSION] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_MIND_READER},
    },

    [MOVE_LOWKICK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_COUNTER] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_TAUNT},
    },

    [MOVE_SEISMICTOSS] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FAKE_OUT},
    },

    [MOVE_STRENGTH] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_ABSORB] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_MEGADRAIN] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_LEECHSEED] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_GROWTH] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_GROWTH,
        .comboMoves = {0},
    },

    [MOVE_RAZORLEAF] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_SOLARBEAM] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_GROWTH},
    },

    [MOVE_POISONPOWDER] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWEET_SCENT},
    },

    [MOVE_STUNSPORE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWEET_SCENT},
    },

    [MOVE_SLEEPPOWDER] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWEET_SCENT},
    },

    [MOVE_PETALDANCE] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_STRINGSHOT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_STRING_SHOT,
        .comboMoves = {0},
    },

    [MOVE_DRAGONRAGE] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_DRAGON_RAGE,
        .comboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_DANCE},
    },

    [MOVE_FIRESPIN] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_THUNDERSHOCK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_THUNDERBOLT] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_THUNDERWAVE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_THUNDER] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE, COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_LOCK_ON},
    },

    [MOVE_ROCKTHROW] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_ROCK_THROW,
        .comboMoves = {0},
    },

    [MOVE_EARTHQUAKE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_EARTHQUAKE,
        .comboMoves = {0},
    },

    [MOVE_FISSURE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_EARTHQUAKE},
    },

    [MOVE_DIG] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_TOXIC] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_CONFUSION] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_CONFUSION,
        .comboMoves = {COMBO_STARTER_PSYCHIC, COMBO_STARTER_KINESIS, COMBO_STARTER_CALM_MIND},
    },

    [MOVE_PSYCHIC] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_PSYCHIC,
        .comboMoves = {COMBO_STARTER_KINESIS, COMBO_STARTER_CONFUSION, COMBO_STARTER_CALM_MIND},
    },

    [MOVE_HYPNOSIS] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_HYPNOSIS,
        .comboMoves = {0},
    },

    [MOVE_MEDITATE] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_AGILITY] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_DOUBLE_TEAM},
    },

    [MOVE_QUICKATTACK] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_DOUBLE_TEAM},
    },

    [MOVE_RAGE] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_RAGE,
        .comboMoves = {0},
    },

    [MOVE_TELEPORT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_DOUBLE_TEAM, COMBO_STARTER_PSYCHIC, COMBO_STARTER_KINESIS, COMBO_STARTER_CONFUSION},
    },

    [MOVE_NIGHTSHADE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_MIMIC] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SCREECH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_DOUBLETEAM] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_DOUBLE_TEAM,
        .comboMoves = {0},
    },

    [MOVE_RECOVER] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_HARDEN] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_HARDEN,
        .comboMoves = {0},
    },

    [MOVE_MINIMIZE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SMOKESCREEN] =
    {
        .effect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SMOG},
    },

    [MOVE_CONFUSERAY] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_WITHDRAW] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_DEFENSECURL] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_DEFENSE_CURL,
        .comboMoves = {0},
    },

    [MOVE_BARRIER] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_LIGHTSCREEN] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_HAZE] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_REFLECT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_FOCUSENERGY] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_FOCUS_ENERGY,
        .comboMoves = {0},
    },

    [MOVE_BIDE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_METRONOME] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_MIRRORMOVE] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SELFDESTRUCT] =
    {
        .effect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_EGGBOMB] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SOFT_BOILED},
    },

    [MOVE_LICK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SMOG] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SMOG,
        .comboMoves = {0},
    },

    [MOVE_SLUDGE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SLUDGE,
        .comboMoves = {COMBO_STARTER_SLUDGE_BOMB},
    },

    [MOVE_BONECLUB] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_BONE_CLUB,
        .comboMoves = {COMBO_STARTER_BONEMERANG, COMBO_STARTER_BONE_RUSH},
    },

    [MOVE_FIREBLAST] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_WATERFALL] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_CLAMP] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_SWIFT] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SKULLBASH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SPIKECANNON] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_CONSTRICT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_AMNESIA] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_KINESIS] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_KINESIS,
        .comboMoves = {COMBO_STARTER_PSYCHIC, COMBO_STARTER_CONFUSION},
    },

    [MOVE_SOFTBOILED] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_SOFT_BOILED,
        .comboMoves = {0},
    },

    [MOVE_HIGHJUMPKICK] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_MIND_READER},
    },

    [MOVE_GLARE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_LEER},
    },

    [MOVE_DREAMEATER] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HYPNOSIS, COMBO_STARTER_CALM_MIND},
    },

    [MOVE_POISONGAS] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_BARRAGE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_LEECHLIFE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_LOVELYKISS] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SKYATTACK] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_TRANSFORM] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_BUBBLE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_DIZZYPUNCH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SPORE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FLASH] =
    {
        .effect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_PSYWAVE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_SPLASH] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_ACIDARMOR] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_CRABHAMMER] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SWORDS_DANCE},
    },

    [MOVE_EXPLOSION] =
    {
        .effect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FURYSWIPES] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SCRATCH},
    },

    [MOVE_BONEMERANG] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_BONEMERANG,
        .comboMoves = {COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONE_RUSH},
    },

    [MOVE_REST] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_REST,
        .comboMoves = {COMBO_STARTER_BELLY_DRUM, COMBO_STARTER_CHARM, COMBO_STARTER_YAWN},
    },

    [MOVE_ROCKSLIDE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ROCK_THROW},
    },

    [MOVE_HYPERFANG] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SHARPEN] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_CONVERSION] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_TRIATTACK] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_LOCK_ON},
    },

    [MOVE_SUPERFANG] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SCARY_FACE},
    },

    [MOVE_SLASH] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWORDS_DANCE, COMBO_STARTER_SCRATCH},
    },

    [MOVE_SUBSTITUTE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_STRUGGLE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SKETCH] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_TRIPLEKICK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_THIEF] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SPIDERWEB] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_STRING_SHOT},
    },

    [MOVE_MINDREADER] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_MIND_READER,
        .comboMoves = {0},
    },

    [MOVE_NIGHTMARE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HYPNOSIS},
    },

    [MOVE_FLAMEWHEEL] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_SNORE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_REST},
    },

    [MOVE_CURSE] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_CURSE,
        .comboMoves = {0},
    },

    [MOVE_FLAIL] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ENDURE},
    },

    [MOVE_CONVERSION2] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_AEROBLAST] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_COTTONSPORE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_REVERSAL] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ENDURE},
    },

    [MOVE_SPITE] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CURSE},
    },

    [MOVE_POWDERSNOW] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_POWDER_SNOW,
        .comboMoves = {COMBO_STARTER_HAIL},
    },

    [MOVE_PROTECT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_HARDEN},
    },

    [MOVE_MACHPUNCH] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SCARYFACE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SCARY_FACE,
        .comboMoves = {COMBO_STARTER_RAGE, COMBO_STARTER_LEER},
    },

    [MOVE_FEINTATTACK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FAKE_OUT, COMBO_STARTER_LEER, COMBO_STARTER_POUND},
    },

    [MOVE_SWEETKISS] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARM},
    },

    [MOVE_BELLYDRUM] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_BELLY_DRUM,
        .comboMoves = {0},
    },

    [MOVE_SLUDGEBOMB] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SLUDGE_BOMB,
        .comboMoves = {COMBO_STARTER_SLUDGE},
    },

    [MOVE_MUDSLAP] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_MUD_SLAP,
        .comboMoves = {COMBO_STARTER_SAND_ATTACK, COMBO_STARTER_MUD_SPORT, COMBO_STARTER_SANDSTORM},
    },

    [MOVE_OCTAZOOKA] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_LOCK_ON},
    },

    [MOVE_SPIKES] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_ZAPCANNON] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_LOCK_ON},
    },

    [MOVE_FORESIGHT] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_DESTINYBOND] =
    {
        .effect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_CURSE, COMBO_STARTER_ENDURE},
    },

    [MOVE_PERISHSONG] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_MEAN_LOOK, COMBO_STARTER_SING},
    },

    [MOVE_ICYWIND] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_DETECT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_TAUNT},
    },

    [MOVE_BONERUSH] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_BONE_RUSH,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_BONE_CLUB, COMBO_STARTER_BONEMERANG},
    },

    [MOVE_LOCKON] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_LOCK_ON,
        .comboMoves = {0},
    },

    [MOVE_OUTRAGE] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SANDSTORM] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_SANDSTORM,
        .comboMoves = {0},
    },

    [MOVE_GIGADRAIN] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_ENDURE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_ENDURE,
        .comboMoves = {0},
    },

    [MOVE_CHARM] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_CHARM,
        .comboMoves = {0},
    },

    [MOVE_ROLLOUT] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_DEFENSE_CURL, COMBO_STARTER_HARDEN},
    },

    [MOVE_FALSESWIPE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWORDS_DANCE},
    },

    [MOVE_SWAGGER] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_MILKDRINK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SPARK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_FURYCUTTER] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWORDS_DANCE},
    },

    [MOVE_STEELWING] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_MEANLOOK] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_MEAN_LOOK,
        .comboMoves = {COMBO_STARTER_CURSE},
    },

    [MOVE_ATTRACT] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SLEEPTALK] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_REST},
    },

    [MOVE_HEALBELL] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_RETURN] =
    {
        .effect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_PRESENT] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FRUSTRATION] =
    {
        .effect = CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SAFEGUARD] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_PAINSPLIT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ENDURE},
    },

    [MOVE_SACREDFIRE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_MAGNITUDE] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_DYNAMICPUNCH] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_MIND_READER},
    },

    [MOVE_MEGAHORN] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_DRAGONBREATH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_DRAGON_BREATH,
        .comboMoves = {COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_DANCE},
    },

    [MOVE_BATONPASS] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_ENCORE] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_PURSUIT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_RAPIDSPIN] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SWEETSCENT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_SWEET_SCENT,
        .comboMoves = {0},
    },

    [MOVE_IRONTAIL] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_METALCLAW] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_METAL_SOUND},
    },

    [MOVE_VITALTHROW] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FAKE_OUT},
    },

    [MOVE_MORNINGSUN] =
    {
        .effect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_SYNTHESIS] =
    {
        .effect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_MOONLIGHT] =
    {
        .effect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_HIDDENPOWER] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_CROSSCHOP] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_TWISTER] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_RAINDANCE] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_RAIN_DANCE,
        .comboMoves = {0},
    },

    [MOVE_SUNNYDAY] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_SUNNY_DAY,
        .comboMoves = {0},
    },

    [MOVE_CRUNCH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SCARY_FACE},
    },

    [MOVE_MIRRORCOAT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_TAUNT},
    },

    [MOVE_PSYCHUP] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_EXTREMESPEED] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_EARLIER,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_ANCIENTPOWER] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SHADOWBALL] =
    {
        .effect = CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FUTURESIGHT] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_PSYCHIC, COMBO_STARTER_KINESIS, COMBO_STARTER_CONFUSION, COMBO_STARTER_CALM_MIND},
    },

    [MOVE_ROCKSMASH] =
    {
        .effect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_WHIRLPOOL] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_BEATUP] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FAKEOUT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_FAKE_OUT,
        .comboMoves = {0},
    },

    [MOVE_UPROAR] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_STOCKPILE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = COMBO_STARTER_STOCKPILE,
        .comboMoves = {0},
    },

    [MOVE_SPITUP] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_STOCKPILE},
    },

    [MOVE_SWALLOW] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_STOCKPILE},
    },

    [MOVE_HEATWAVE] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_HAIL] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_HAIL,
        .comboMoves = {0},
    },

    [MOVE_TORMENT] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FLATTER] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARM},
    },

    [MOVE_WILLOWISP] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_MEMENTO] =
    {
        .effect = CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FACADE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FOCUSPUNCH] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_SMELLINGSALTS] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FOLLOWME] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_NATUREPOWER] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_CHARGE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_CHARGE,
        .comboMoves = {0},
    },

    [MOVE_TAUNT] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_TAUNT,
        .comboMoves = {0},
    },

    [MOVE_HELPINGHAND] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_TRICK] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_ROLEPLAY] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_WISH] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_ASSIST] =
    {
        .effect = CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_INGRAIN] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SUPERPOWER] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_LOCK_ON},
    },

    [MOVE_MAGICCOAT] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_RECYCLE] =
    {
        .effect = CONTEST_EFFECT_REPETITION_NOT_BORING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_REVENGE] =
    {
        .effect = CONTEST_EFFECT_NEXT_APPEAL_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_BRICKBREAK] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_YAWN] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_YAWN,
        .comboMoves = {0},
    },

    [MOVE_KNOCKOFF] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FAKE_OUT},
    },

    [MOVE_ENDEAVOR] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ENDURE},
    },

    [MOVE_ERUPTION] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ENDURE, COMBO_STARTER_EARTHQUAKE, COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_SKILLSWAP] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_IMPRISON] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_REFRESH] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_WATER_SPORT, COMBO_STARTER_SING},
    },

    [MOVE_GRUDGE] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CURSE},
    },

    [MOVE_SNATCH] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SECRETPOWER] =
    {
        .effect = CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_DIVE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = COMBO_STARTER_DIVE,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SURF},
    },

    [MOVE_ARMTHRUST] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY, COMBO_STARTER_FAKE_OUT},
    },

    [MOVE_CAMOUFLAGE] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_TAILGLOW] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_LUSTERPURGE] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_MISTBALL] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },

    [MOVE_FEATHERDANCE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_TEETERDANCE] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_BLAZEKICK] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_MUDSPORT] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_MUD_SPORT,
        .comboMoves = {COMBO_STARTER_MUD_SLAP, COMBO_STARTER_WATER_SPORT},
    },

    [MOVE_ICEBALL] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_NEEDLEARM] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SLACKOFF] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_YAWN},
    },

    [MOVE_HYPERVOICE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_POISONFANG] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_CRUSHCLAW] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SWORDS_DANCE},
    },

    [MOVE_BLASTBURN] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_HYDROCANNON] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_METEORMASH] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_ASTONISH] =
    {
        .effect = CONTEST_EFFECT_STARTLE_PREV_MON,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_WEATHERBALL] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_SUNNY_DAY, COMBO_STARTER_HAIL, COMBO_STARTER_SANDSTORM},
    },

    [MOVE_AROMATHERAPY] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_FAKETEARS] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_LAST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_AIRCUTTER] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_OVERHEAT] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SUNNY_DAY},
    },

    [MOVE_ODORSLEUTH] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_ROCKTOMB] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_ROCK_THROW},
    },

    [MOVE_SILVERWIND] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_METALSOUND] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_METAL_SOUND,
        .comboMoves = {0},
    },

    [MOVE_GRASSWHISTLE] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_TICKLE] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_COSMICPOWER] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_WATERSPOUT] =
    {
        .effect = CONTEST_EFFECT_BETTER_WHEN_LATER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_SIGNALBEAM] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SHADOWPUNCH] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_EXTRASENSORY] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SKYUPPERCUT] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_FOCUS_ENERGY},
    },

    [MOVE_SANDTOMB] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_SANDSTORM},
    },

    [MOVE_SHEERCOLD] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_MUDDYWATER] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_BULLETSEED] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_AERIALACE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_ICICLESPEAR] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_IRONDEFENSE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_BLOCK] =
    {
        .effect = CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_HOWL] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_DRAGONCLAW] =
    {
        .effect = CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_DRAGON_BREATH, COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_DANCE},
    },

    [MOVE_FRENZYPLANT] =
    {
        .effect = CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_BULKUP] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_BOUNCE] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_MUDSHOT] =
    {
        .effect = CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_POISONTAIL] =
    {
        .effect = CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_COVET] =
    {
        .effect = CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_VOLTTACKLE] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_MAGICALLEAF] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_GROWTH},
    },

    [MOVE_WATERSPORT] =
    {
        .effect = CONTEST_EFFECT_HIGHLY_APPEALING,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .comboStarterId = COMBO_STARTER_WATER_SPORT,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE, COMBO_STARTER_MUD_SPORT},
    },

    [MOVE_CALMMIND] =
    {
        .effect = CONTEST_EFFECT_AVOID_STARTLE_ONCE,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = COMBO_STARTER_CALM_MIND,
        .comboMoves = {0},
    },

    [MOVE_LEAFBLADE] =
    {
        .effect = CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_DRAGONDANCE] =
    {
        .effect = CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = COMBO_STARTER_DRAGON_DANCE,
        .comboMoves = {COMBO_STARTER_DRAGON_RAGE, COMBO_STARTER_DRAGON_BREATH},
    },

    [MOVE_ROCKBLAST] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_SAME_TYPE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_SHOCKWAVE] =
    {
        .effect = CONTEST_EFFECT_BETTER_IF_FIRST,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CHARGE},
    },

    [MOVE_WATERPULSE] =
    {
        .effect = CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_RAIN_DANCE},
    },

    [MOVE_DOOMDESIRE] =
    {
        .effect = CONTEST_EFFECT_DONT_EXCITE_AUDIENCE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .comboStarterId = 0,
        .comboMoves = {0},
    },

    [MOVE_PSYCHOBOOST] =
    {
        .effect = CONTEST_EFFECT_USER_MORE_EASILY_STARTLED,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .comboStarterId = 0,
        .comboMoves = {COMBO_STARTER_CALM_MIND},
    },
};

const struct ContestEffect gContestEffects[] =
{
    [CONTEST_EFFECT_HIGHLY_APPEALING] =
    {
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 40,
        .jam = 0,
    },
    [CONTEST_EFFECT_USER_MORE_EASILY_STARTLED] =
    {
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 60,
        .jam = 0,
    },
    [CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES] =
    {
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 80,
        .jam = 0,
    },
    [CONTEST_EFFECT_REPETITION_NOT_BORING] =
    {
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_AVOID_STARTLE_ONCE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_AVOID_STARTLE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_AVOID_STARTLE_SLIGHTLY] =
    {
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_USER_LESS_EASILY_STARTLED] =
    {
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_STARTLE_FRONT_MON] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 30,
        .jam = 20,
    },
    [CONTEST_EFFECT_SLIGHTLY_STARTLE_PREV_MONS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MON] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 20,
        .jam = 30,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MONS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 20,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 10,
        .jam = 40,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 10,
        .jam = 30,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MON_2] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 30,
        .jam = 20,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MONS_2] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
    },
    [CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 40,
        .jam = 40,
    },
    [CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_COOL_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_BEAUTY_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_CUTE_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_SMART_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_STARTLE_MONS_TOUGH_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_MAKE_FOLLOWING_MON_NERVOUS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_BADLY_STARTLES_MONS_IN_GOOD_CONDITION] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
    },
    [CONTEST_EFFECT_BETTER_IF_FIRST] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_IF_LAST] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_WHEN_LATER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_IF_SAME_TYPE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_IF_DIFF_TYPE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
    },
    [CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_NEXT_APPEAL_EARLIER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_NEXT_APPEAL_LATER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_MAKE_SCRAMBLING_TURN_ORDER_EASIER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER] =
    {
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
    },
    [CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS] =
    {
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
    },
    [CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED] =
    {
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
    },
    [CONTEST_EFFECT_DONT_EXCITE_AUDIENCE] =
    {
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
    },
};

// A lookup table with TRUE for each combo starter ID and FALSE for ID 0,
// which means "not a combo starter move".
const bool8 gComboStarterLookupTable[] =
{
    FALSE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    TRUE
};

void (*const gContestEffectFuncs[])(void) =
{
    ContestEffect_HighlyAppealing,
    ContestEffect_UserMoreEasilyStartled,
    ContestEffect_GreatAppealButNoMoreMoves,
    ContestEffect_RepetitionNotBoring,
    ContestEffect_AvoidStartleOnce,
    ContestEffect_AvoidStartle,
    ContestEffect_AvoidStartleSlightly,
    ContestEffect_UserLessEasilyStartled,
    ContestEffect_StartleFrontMon,
    ContestEffect_StartlePrevMons,
    ContestEffect_StartleFrontMon,
    ContestEffect_StartlePrevMons,
    ContestEffect_StartleFrontMon,
    ContestEffect_StartlePrevMons,
    ContestEffect_StartlePrevMon2,
    ContestEffect_StartlePrevMons2,
    ContestEffect_ShiftJudgeAttention,
    ContestEffect_StartleMonWithJudgesAttention,
    ContestEffect_JamsOthersButMissOneTurn,
    ContestEffect_StartleMonsSameTypeAppeal,
    ContestEffect_StartleMonsCoolAppeal,
    ContestEffect_StartleMonsBeautyAppeal,
    ContestEffect_StartleMonsCuteAppeal,
    ContestEffect_StartleMonsSmartAppeal,
    ContestEffect_StartleMonsToughAppeal,
    ContestEffect_MakeFollowingMonNervous,
    ContestEffect_MakeFollowingMonsNervous,
    ContestEffect_WorsenConditionOfPrevMons,
    ContestEffect_BadlyStartlesMonsInGoodCondition,
    ContestEffect_BetterIfFirst,
    ContestEffect_BetterIfLast,
    ContestEffect_AppealAsGoodAsPrevOnes,
    ContestEffect_AppealAsGoodAsPrevOne,
    ContestEffect_BetterWhenLater,
    ContestEffect_QualityDependsOnTiming,
    ContestEffect_BetterIfSameType,
    ContestEffect_BetterIfDiffType,
    ContestEffect_AffectedByPrevAppeal,
    ContestEffect_ImproveConditionPreventNervousness,
    ContestEffect_BetterWithGoodCondition,
    ContestEffect_NextAppealEarlier,
    ContestEffect_NextAppealLater,
    ContestEffect_MakeScramblingTurnOrderEasier,
    ContestEffect_ScrambleNextTurnOrder,
    ContestEffect_ExciteAudienceInAnyContest,
    ContestEffect_BadlyStartleMonsWithGoodAppeals,
    ContestEffect_BetterWhenAudienceExcited,
    ContestEffect_DontExciteAudience,
};
