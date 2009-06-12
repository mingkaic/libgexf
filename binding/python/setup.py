#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
setup.py file for Libgexf
"""

from distutils.core import Extension, setup

libgexf_module = Extension(
  '_libgexf', # genere un _libgexf.so
  #include_dirs=['path/to/libgexf/includes/'],
  sources=[
    
   # 'libgexf.i', # genere un libgexf.py (ne fonctionne que pour les sources C et pas C++)

    # sources C: les .o seront automatiquement généré,
    # et automatiquement linké avec le module
    '../../graph.cpp',
    '../../directedgraph.cpp',
    '../../undirectedgraph.cpp',
    '../../gexf.cpp',

    # chemin du wrapper généré automatiquement par SWIG (ce wrapper doit déjà exister donc)
    'libgexf_wrap.cpp',
  ],

  # eventuellement, les librairies à "linker"
  # par exemple si on a besoin de libxml, c'est ici qu'on le spécifie au compilateur
  # attention aux habitués de gcc et de la compilation en ligne de commande:
  # ici inutile de donner le format spécifique à gcc ("-lpthread") ou spécifique à visual studio etc..
  # il suffit de mettre "pthread" et le script python va rajouter le "-l" devant si nécessaire
  libraries=[
     #'z', # zlib (compression) (inutile sous ubuntu par exemple, car déjà intégré au packaging de base pour développer)
     #'pthread' # Posix Threads (multithreading posix) (inutile sous linux, car posix fait déjà partie du système)
  ] 
)

setup (
       name='libgexf', # important, c'est le vrai nom du module, qui sera utilisé quand on fera un "import libgexf;" par exemple

       # metadonnees diverses
       version='0.1', 
       author="Sebastien Heymann",
       author_email="sebastien.heymann@gephi.org",
       url="http://gephi.org",
       description="""Toolkit library for GEXF file format.""",
       long_description="""une description en un paragraphe (abstract)""",
       
       # liste des modules à compiler. 
       # le module "libgexf_module" a été défini ligne 12
       # 
       ext_modules=[ libgexf_module, ],

       # si on veut rajouter un package python
       # par exemple 
       #             packages = ["monpackage"]
       # va rajouter le packag
       #             monpackage/
       # puisqu'en python les packages sont enfait tout simplement des répertoires contenant 
       # un fichier "constructeur" __init__.py (c'est un peu du système de fichier orienté objet)
       # cela aura pour effet de rajouter de manière récursive
       #             monpackage/__init__.py
       #             monpackage/sous/sous/sous/package/fichier.py
       # etc.. 
       #packages= ["monpackage", ], # 
       
       # si on veut rajouter des scripts python en plus
       # par exemple
       #              py_modules = ["monmodule"]
       # va rajouter le fichier
       #              monmodule.py (dans le répertoire courant)
       # dans le package
       py_modules = ["libgexf"], # UNCOMMENT TO USE THE SWIG WRAPPER

       # on peut rajouter des fichiers divers aussi (readme, examples, licences, doc html etc..)
       #data_files = [('share/libgexf-python/',['readme.txt']),],

       # encore des meta donnees, pour la base de donnees en ligne des modules python (python.org)
       classifiers=[
       "Development Status :: 2 - Pre-Alpha",
       "Intended Audience :: Science/Research",
       "Intended Audience :: Developers",
       "Intended Audience :: Information Technology",
       "License :: Free for non-commercial use",
       "Operating System :: POSIX :: Linux",
       "Topic :: Software Development :: Libraries :: Python Modules", ],
       )
