import os
import sys
import json
import pygame

pygame.display.init()
display_width = 32
display_height = 64
icon_width = 16
icon_height = 16
rect_thickness = 10
scaling_factor = 20
frame_delay = 50
black = (0, 0, 0)
white = (255, 255, 255)

gameDisplay = pygame.display.set_mode((display_width*scaling_factor, display_height*scaling_factor))

def drawRectBorder(x, y, width, height):
    pygame.draw.rect(gameDisplay, white, (x, y, width, rect_thickness))
    pygame.draw.rect(gameDisplay, white, (x, y + height, width, rect_thickness))
    pygame.draw.rect(gameDisplay, white, (x, y, rect_thickness, height))
    pygame.draw.rect(gameDisplay, white, (x + width, y, rect_thickness, height))

def displayIconAndGetCoords(icon_path):
    icon_img = pygame.image.load(icon_path)
    screen = pygame.Surface((display_width, display_height))
    screen.blit(icon_img, (0, 0))
    while True:
        pygame.time.delay(frame_delay)
        gameDisplay.blit(pygame.transform.scale(screen, gameDisplay.get_rect().size), (0, 0))
        x, y = pygame.mouse.get_pos()
        small_x = x // scaling_factor
        small_y = y // scaling_factor
        drawRectBorder(small_x * scaling_factor, small_y * scaling_factor, icon_width * scaling_factor, icon_height * scaling_factor)
        pygame.display.update()

        events = pygame.event.get()
        for event in events:
            if event.type == pygame.MOUSEBUTTONUP:
                return (small_x, small_y)


BASE_DIR = "graphics/pokemon"

with open("scripts/pokemon_icon_data.json", "r") as f:
    pokemon_icon_data = json.load(f)

pokemon_list = os.listdir(BASE_DIR)
pokemon_list.remove("icon_palettes")
pokemon_list.remove("question_mark")
pokemon_list.remove("unown")
for letter in os.listdir(os.path.join(BASE_DIR, "unown")):
    if os.path.isdir(os.path.join(BASE_DIR, "unown", letter)):
        pokemon_list.append(f"unown_{letter}")

for pokemon in pokemon_list:
    if pokemon.startswith("unown"):
        sp = pokemon.split("_")
        pokemon_dir = os.path.join(BASE_DIR, *pokemon.split("_", maxsplit=1))
    else:
        pokemon_dir = os.path.join(BASE_DIR, pokemon)

    if not os.path.isdir(pokemon_dir):
        continue

    if pokemon not in pokemon_icon_data:
        raise Exception(f"Pokemon {pokemon} not found in POKEMON_ICON_DATA")

    print(pokemon)
    x, y = displayIconAndGetCoords(os.path.join(pokemon_dir, "icon.png"))
    pokemon_icon_data[pokemon]["icon_x"] = x
    pokemon_icon_data[pokemon]["icon_y"] = y
    with open("scripts/pokemon_icon_data.json", "w") as f:
        json.dump(pokemon_icon_data, f, indent=4, sort_keys=True)

pygame.quit()

