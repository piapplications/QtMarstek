# Contributing to QtMarstek

Merci de contribuer à QtMarstek !

L'objectif du projet est de fournir une bibliothèque Qt moderne permettant de piloter les batteries Marstek tout en masquant complètement le protocole propriétaire.

---

# Philosophie

QtMarstek doit ressembler à une bibliothèque officielle Qt.

Le développeur ne doit jamais manipuler directement :

- les sockets UDP ;
- les paquets du protocole ;
- les CRC ;
- les temporisations ;
- les retransmissions.

Toute cette logique appartient aux couches internes.

---

# Objectifs

Le projet privilégie :

- une API simple ;
- un code lisible ;
- la stabilité de l'API publique ;
- la compatibilité Qt 6.x ;
- une couverture de tests élevée.

---

# Versions de Qt

Version minimale :

Qt 6.8

Les nouvelles fonctionnalités devront rester compatibles avec Qt 6.8 sauf justification particulière.

---

# Plateformes

Le code doit fonctionner sur :

- Linux
- Windows

Le support de macOS pourra être ajouté ultérieurement.

---

# Style C++

Le projet suit les recommandations Qt.

## Classes

Une classe publique par fichier.

Exemple :

```
MarstekDevice.h
MarstekDevice.cpp
```

---

## Nommage

Classes

```
MarstekDevice
```

Méthodes

```
refreshStatus()
```

Variables privées

```
_deviceName
_socket
_protocol
```

Constantes

```
DefaultTimeout
```

Enumérations

```
enum class DeviceState
```

---

# API publique

L'API publique ne doit jamais exposer :

- les identifiants internes du protocole ;
- les numéros de commande ;
- les offsets des paquets ;
- les CRC.

Ces éléments doivent rester internes.

---

# Gestion mémoire

Utiliser autant que possible les mécanismes Qt.

Éviter :

- new/delete explicites ;
- pointeurs propriétaires bruts.

Préférer :

- parent QObject ;
- std::unique_ptr ;
- std::shared_ptr si un partage est réellement nécessaire ;
- QPointer pour référencer un QObject sans en être propriétaire.

---

# Programmation asynchrone

Les méthodes réseau sont asynchrones.

Ne jamais bloquer la boucle d'événements.

Éviter :

```
QEventLoop loop;
loop.exec();
```

dans la bibliothèque.

Privilégier :

- signaux/slots ;
- QTimer ;
- callbacks Qt.

---

# Documentation

Toutes les classes publiques doivent être documentées avec Doxygen.

Chaque méthode publique doit comporter :

- sa description ;
- ses paramètres ;
- sa valeur de retour ;
- les signaux éventuellement émis.

---

# Tests

Toute nouvelle fonctionnalité importante doit être accompagnée de tests unitaires.

Les tests sont réalisés avec Qt Test.

---

# Exemples

Les exemples font partie intégrante du projet.

Ils doivent toujours compiler.

Ils servent également de documentation.

---

# Reverse engineering

Toute découverte concernant le protocole doit être documentée dans :

docs/protocol.md

avant d'être utilisée dans le code.

---

# Commits

Préférer des commits courts et ciblés.

Exemples :

```
Add UDP discovery

Implement packet parser

Support firmware v148

Fix scheduler upload
```

Éviter les commits de type :

```
Various fixes

Update project
```

---

# Branches

Une branche par fonctionnalité.

Exemple :

feature/discovery

feature/parser

feature/scheduler

feature/tests

---

# Pull Requests

Une Pull Request doit :

- compiler ;
- passer les tests ;
- mettre à jour la documentation si nécessaire.

---

# Licence

MIT

