## About

This mod is intended for Palworld's Dedicated Servers to help prevent various serious bugs that may negatively impact gameplay or otherwise cause your server to be stuck in a crash loop. List of fixes included with the mod:

- [x] Prevents crashing when a player's data is still referenced within a guild, but the player itself doesn't exist in the save anymore.
- [x] Prevents crashing when an unbuilt Electricity Generator exists within a base after a server restart, though I'm not entirely sure if this crash extends to other things so I will keep this section updated.

## Requirements

https://github.com/Okaetsu/RE-UE4SS/releases/tag/experimental-palworld

## Installing

1. Download the latest release from https://github.com/Okaetsu/UnofficialServerPatch/releases
2. Drop the UnofficialServerPatch folder from inside the .zip into your server's Win64/ue4ss/Mods folder.

This mod will not work for Linux. Intended for Dedicated Servers only.
