1. Network discovery
   =================
Broadcast
---------
Destination : 255.255.255.255
Port        : xxxx
Protocol    : UDP

Capture :
18:12:24.978971
...

Description
-----------
Les batteries répondent par un paquet UDP contenant :

  - adresse IP
  - nom
  - version
  - MAC
  - ...

2. Format de paquet
   ================
+------------+
| Header     |
+------------+
| Command    |
+------------+
| Payload    |
+------------+
| CRC        |
+------------+

3. Commandes
   =========
+---------+------------+-----------------+--------+
| Command | Direction  | Description     | Status |
| ------- | ---------- | --------------- | ------ |
| 0x0001  | PC → Venus | Discovery       | ✔      |
| 0x0002  | Venus → PC | Discovery reply | ✔      |
| ...     | ...        | ...             | ...    |

4. Payloads
   ========
Réponse à la découverte :
+--------+--------+---------+
| Offset | Length | Meaning |
| ------ | ------ | ------- |
| 0      | 4      | IPv4    |
| 4      | 6      | MAC     |
| 10     | ...    | Name    |

5. CRC
   ===
Description de l'algorithme.

<-- À compléter. -->

6. Firmware differences
   ====================
v148

...

v149

...

7. Champs inconnus
   ===============
+--------+--------+--------------+
| Offset | Length | Observations |
| ------ | ------ | ------------ |
| 12     | 4      | Toujours nul |
| 24     | 2      | Variable     |

8. Captures
   ========
Toutes les captures tcpdump ou Wireshark.

Exemple :
0x0000 ...

9. Vecteurs de Test
   ================
Chaque commande connue.

Entrée
...

Sortie attendue
...

10. TODO
    ====
  - identifier CRC
  - comprendre commande XX
  - décoder champ YY
