#ifndef _EMOTIFY_H_
#define _EMOTIFY_H_

typedef enum emotions {
    SAD,
    HAPPY,
    GRIMACE,
    CRY,
    ANGRY,
    NONE
} emotions_t;

emotions_t read_emotion() {
    char emo[10];
    printf("what's your emotion (HAPPY, SAD, GRIMACE, CRY, ANGRY): ");
    scanf("%s", emo);
    
    if (strcmp(emo, "happy") == 0 || strcmp(emo, "HAPPY") == 0)
        return HAPPY;
    else if (strcmp(emo, "sad") == 0 || strcmp(emo, "SAD") == 0)
        return SAD;
    else if (strcmp(emo, "grimace") == 0 || strcmp(emo, "GRIMACE") == 0)
        return GRIMACE;
    else if (strcmp(emo, "cry") == 0 || strcmp(emo, "CRY") == 0)
        return CRY;
    else if (strcmp(emo, "angry") == 0 || strcmp(emo, "ANGRY") == 0)
        return ANGRY;
    else
        return NONE;
}

#endif