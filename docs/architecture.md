
QtMarstek

Objectif
========
QtMarstek est une bibliothèque Qt 6 permettant de découvrir, surveiller et piloter les batteries Marstek (Venus A, puis autres modèles) au travers du protocole réseau propriétaire.
La bibliothèque doit masquer complètement le protocole UDP au développeur.
L'utilisateur de la bibliothèque ne manipule que des objets Qt.

Architecture générale
=====================
Application
      │
      │
      ▼
MarstekDiscovery
      │
      ├───────────────┐
      ▼               ▼
MarstekDevice     MarstekDevice
      │
      ▼
MarstekProtocol
      │
      ▼
MarstekPacket
      │
      ▼
      UDP

Les classes publiques
=====================

MarstekDiscovery
----------------
Responsabilités :
    - découverte automatique
    - maintien de la liste des batteries
    - émission des signaux
    - aucune connaissance du protocole

API typique :

start();
stop();
devices();
device(ip);

Signaux :

deviceAdded()
deviceRemoved()
deviceChanged()

MarstekDevice
-------------
Un objet représente UNE batterie.

Il contient :
  - nom
  - modèle
  - firmware
  - adresse IP
  - MAC
  - état courant
  - puissance
  - SOC
  - température
  - etc.

Il possède également les méthodes :

refresh()
setOutputPower()
setWorkMode()
schedule()
...

Toutes ces méthodes sont asynchrones.

MarstekScheduler
----------------
Gestion des horaires.

Exemple :
    00:00 → 06:00 charge
    06:00 → 14:00 attente
    14:00 → 24:00 décharge

afin d'éviter les booléens partout.

Les classes internes
====================
Ces classes ne sont jamais visibles de l'utilisateur.

MarstekProtocol
MarstekPacket
MarstekTransport
MarstekCommandQueue
MarstekParser
MarstekCrc

MarstekTransport
----------------
Responsable de

QUdpSocket
timeouts
retransmissions
broadcast

Aucune logique métier.

MarstekProtocol
---------------
Convertit

MarstekDevice
  ↓
MarstekPacket
  ↓
UDP

et inversement.
Elle ne connaît que le protocole.

MarstekPacket
-------------
Objet immutable.
Exemple :

Command
Payload
CRC

Il ne connaît pas Qt.

Threading
---------
Je recommande un seul thread.
Pourquoi ?
Le trafic UDP est très faible.
Une batterie envoie quelques dizaines de paquets par minute.
Qt gère parfaitement cela dans la boucle d'événements.
Éviter les threads rendra la bibliothèque :

  - plus simple ;
  - plus fiable ;
  - plus portable.

API
===
Je voudrais qu'elle ressemble à ceci :

MarstekDiscovery discovery;

QObject::connect(
    &discovery,
    &MarstekDiscovery::deviceAdded,
    [](MarstekDevice *device) {
        qDebug() << device->name();

        device->refresh();
    });
discovery.start();

L'utilisateur ne voit jamais un paquet UDP.

Philosophie
===========
Je voudrais que QtMarstek ressemble aux bibliothèques Qt officielles.
Autrement dit :
  - API très simple ;
  - protocole entièrement caché ;
  - aucune allocation manuelle ;
  - signaux/slots partout ;
  - objets propriétaires (QObject) ;
  - documentation Doxygen ;
  - exemples complets.

Ce que j'ajouterais
-------------------
J'aimerais aller un peu plus loin que ce document d'architecture et définir dès le départ la feuille de route du projet.
Je te proposerais de créer quatre documents dans docs/ :

architecture.md : architecture logicielle (le document ci-dessus) ;
protocol.md : tout ce que nous découvrons sur le protocole Marstek (formats de paquets, commandes, champs, CRC, etc.) ;
roadmap.md : les fonctionnalités prévues et leur état d'avancement ;
contributing.md : conventions de codage, structure des commits, règles de documentation et de tests.

Ainsi, le dépôt GitHub ne contiendra pas seulement du code, mais également toute la connaissance accumulée au fil de notre travail. À mon avis, cela donnera à QtMarstek une base très solide pour évoluer, même plusieurs années plus tard.