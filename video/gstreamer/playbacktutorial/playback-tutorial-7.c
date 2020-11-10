#include <gst/gst.h>
#include<stdio.h>

int
main (int argc, char *argv[])
{
  GstElement *pipeline, *bin, *equalizer, *convert, *sink;
  GstPad *pad, *ghost_pad;
  GstBus *bus;
  GstMessage *msg;

  /* Initialize GStreamer */
  printf("Manikanta: main : gst_init : Initialize GStreamer \n");
  gst_init (&argc, &argv);
  printf("Manikanta: main : gst_parse_launch : Build the pipeline \n");
  /* Build the pipeline */
  pipeline =
      gst_parse_launch
      ("playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm",
      NULL);

  /* Create the elements inside the sink bin */
    printf("Manikanta: main : gst_element_factory_make : Create the elements inside the sink bin :equalizer \n");
  equalizer = gst_element_factory_make ("equalizer-3bands", "equalizer");
    printf("Manikanta: main : gst_element_factory_make : Create the elements inside the sink bin :convert \n");
  convert = gst_element_factory_make ("audioconvert", "convert");
    printf("Manikanta: main : gst_element_factory_make : Create the elements inside the sink bin :sink \n");
  sink = gst_element_factory_make ("autoaudiosink", "audio_sink");
  if (!equalizer || !convert || !sink) {
    g_printerr ("Not all elements could be created.\n");
    return -1;
  }

  /* Create the sink bin, add the elements and link them */
      printf("Manikanta: main : gst_bin_new : Create the sink bin  \n");
  bin = gst_bin_new ("audio_sink_bin");
      printf("Manikanta: main : gst_bin_add_many : add the elements  \n");
  gst_bin_add_many (GST_BIN (bin), equalizer, convert, sink, NULL);
      printf("Manikanta: main : gst_element_link_many : link them  \n");  
  gst_element_link_many (equalizer, convert, sink, NULL);
        printf("Manikanta: main : gst_element_get_static_pad : equalizer pad \n");  
  pad = gst_element_get_static_pad (equalizer, "sink");
          printf("Manikanta: main : gst_ghost_pad_new : ghost_pad \n");  
  ghost_pad = gst_ghost_pad_new ("sink", pad);
          printf("Manikanta: main : gst_pad_set_active : ghost_pad \n");    
  gst_pad_set_active (ghost_pad, TRUE);
           printf("Manikanta: main : gst_element_add_pad : ghost_pad \n");    
  gst_element_add_pad (bin, ghost_pad);
  gst_object_unref (pad);

  /* Configure the equalizer */
             printf("Manikanta: main : g_object_set : Configure the equalizer \n");    
  g_object_set (G_OBJECT (equalizer), "band1", (gdouble) - 24.0, NULL);
  g_object_set (G_OBJECT (equalizer), "band2", (gdouble) - 24.0, NULL);

  /* Set playbin2's audio sink to be our sink bin */
               printf("Manikanta: main : g_object_set : Set playbin2's audio sink to be our sink bin \n");    
  g_object_set (GST_OBJECT (pipeline), "audio-sink", bin, NULL);

  /* Start playing */
               printf("Manikanta: main : gst_element_set_state : Start playing \n");    
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* Wait until error or EOS */
               printf("Manikanta: main : gst_element_get_bus : Wait until error or EOS  \n");      
  bus = gst_element_get_bus (pipeline);
                 printf("Manikanta: main : gst_bus_timed_pop_filtered :   \n");      
  msg =
      gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
      GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* Free resources */
  if (msg != NULL)
                   printf("Manikanta: main : gst_message_unref : Free resources  \n");      
    gst_message_unref (msg);
                    printf("Manikanta: main : gst_object_unref : Free resources  \n");         
  gst_object_unref (bus);
                     printf("Manikanta: main : gst_element_set_state : Free resources  \n");          
  gst_element_set_state (pipeline, GST_STATE_NULL);
                      printf("Manikanta: main : gst_object_unref : Free resources  \n");           
  gst_object_unref (pipeline);
  return 0;
}
