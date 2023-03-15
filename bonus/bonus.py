#!/bin/env python3

import pygame
from pygame.locals import *
import sys
import random
from time import *

txt = ""
scene = 1
t0 = time()

def event_exit(event):
    if (event.type == QUIT):
        sys.exit()
    if (event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE):
        sys.exit()

def event_window():
    strend = 0
    global txt, t0, scene

    for event in pygame.event.get():
        event_exit(event)
        if event.type == pygame.KEYDOWN:
            if (scene == 1 or scene == 2 or scene == 3):
                scene += 1
            if event.key == pygame.K_RETURN:
                strend = 1
                print(txt)
            elif (event.key == pygame.K_BACKSPACE):
                txt = txt[:-1]
            elif (event.key == pygame.K_SPACE):
                txt = txt + "  "
            else:
                txt += pygame.key.name(event.key)

def print_prompt(screen, text_dir) -> int:
    global txt, t0
    white = (255, 255, 255)
    green = (0, 255, 0)
    blue = (53, 209, 255)

    font = pygame.font.Font('font/Times.ttf', 24)
    name = font.render('user@user-HP-ProBook-440-G7', True, green)
    two_point = font.render(':', True, white)
    dir = font.render(text_dir, True, blue)
    dolar = font.render('$', True, white)
    texte = font.render(txt, True, white)

    screen.blit(name, (0, 0))
    screen.blit(two_point, (318, 0))
    screen.blit(dir, (325, 0))
    screen.blit(dolar, (dir.get_width() + 330, 0))
    screen.blit(texte, (dir.get_width() + 360, 0))
    t1 = time()
    if (t1 - t0 > 0.75):
        pygame.draw.rect(screen,white,(dir.get_width() + texte.get_width() + 365, 2, 10, 18))
    if (t1 - t0 > 1.5):
        t0 = t1

def print_img(screen, path):
    bg = pygame.image.load(path)
    screen.blit(bg, (0, 0))

def main():
    global scene
    black = (0, 0, 0)

    pygame.init()
    pygame.display.set_caption("Terminal - 42sh")
    SIZE = WIDTH, HEIGHT =  pygame.display.Info().current_w, pygame.display.Info().current_h
    screen = pygame.display.set_mode(SIZE)

    #box = pygame.image.load("img/box.png")
    #box = pygame.transform.scale(box, (50, 50))

    while (True):
        event_window()
        if (scene == 1):
            print_img(screen, "img/42sh.png")
        elif (scene == 2):
            print_img(screen, "img/bg.png")
            print_prompt(screen, "~/keynote")
        elif (scene == 3):
            print_img(screen, "img/saviez-vous1.png")
            print_prompt(screen, "~/keynote")
        elif (scene == 4):
            print_img(screen, "img/saviez-vous2.png")
            print_prompt(screen, "~/keynote")
        pygame.display.update()

main()

